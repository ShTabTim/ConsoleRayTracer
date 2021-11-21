#include "ConsoleRenderer.h"

ConsoleRenderer::ConsoleRenderer() {
	ConsoleHDL = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleInHDL = GetStdHandle(STD_INPUT_HANDLE);

	std::memset(m_keyNewState, 0, 256 * sizeof(short));
	std::memset(m_keyOldState, 0, 256 * sizeof(short));
	std::memset(m_keys, 0, 256 * sizeof(sKeyState));
	m_mousePosX = 0;
	m_mousePosY = 0;

	AppName = L"Default";
}

int ConsoleRenderer::ConstructConsole(int width, int height, int fontw, int fonth) {
	if (ConsoleHDL == INVALID_HANDLE_VALUE)
		return Error(L"Bad Handle");

	WindowRect = { 0, 0, 1, 1 };
	SetConsoleWindowInfo(ConsoleHDL, TRUE, &WindowRect);

	COORD coord = { width, height };
	if (!SetConsoleScreenBufferSize(ConsoleHDL, coord))
		Error(L"SetConsoleScreenBufferSize");

	if (!SetConsoleActiveScreenBuffer(ConsoleHDL))
		return Error(L"SetConsoleActiveScreenBuffer");

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = fontw;
	cfi.dwFontSize.Y = fonth;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;

	wcscpy_s(cfi.FaceName, L"Consolas");
	if (!SetCurrentConsoleFontEx(ConsoleHDL, false, &cfi))
		return Error(L"SetCurrentConsoleFontEx");

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(ConsoleHDL, &csbi))
		return Error(L"GetConsoleScreenBufferInfo");
	if (height > csbi.dwMaximumWindowSize.Y)
		return Error(L"Screen Height / Font Height Too Big");
	if (width > csbi.dwMaximumWindowSize.X)
		return Error(L"Screen Width / Font Width Too Big");

	WindowRect = { 0, 0, (short)(width - 1), (short)(height - 1)};
	if (!SetConsoleWindowInfo(ConsoleHDL, TRUE, &WindowRect))
		return Error(L"SetConsoleWindowInfo");

	if (!SetConsoleMode(ConsoleInHDL, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT))
		return Error(L"SetConsoleMode");

	db.init(width, height);

	SetConsoleCtrlHandler((PHANDLER_ROUTINE)CloseHandler, TRUE);
	return 1;
}

ConsoleRenderer::~ConsoleRenderer() {
	SetConsoleActiveScreenBuffer(OriginalConsole);
	db.~DB();
}

void ConsoleRenderer::Start() {
	AtomActive = true;
	std::thread t = std::thread(&ConsoleRenderer::RenderThread, this);

	t.join();
}

int ConsoleRenderer::ScreenW() { return db.GetW(); }
int ConsoleRenderer::ScreenH() { return db.GetH(); }

void ConsoleRenderer::RenderThread() {
	if (!initSim())
		AtomActive = false;

	auto tp1 = std::chrono::system_clock::now();
	auto tp2 = std::chrono::system_clock::now();

	while (AtomActive) {
		while (AtomActive) {
			tp2 = std::chrono::system_clock::now();
			std::chrono::duration<float> dTime = tp2 - tp1;
			tp1 = tp2;
			float dt = dTime.count();

			for (int i = 0; i < 256; i++) {
				m_keyNewState[i] = GetAsyncKeyState(i);

				m_keys[i].bPressed = false;
				m_keys[i].bReleased = false;

				if (m_keyNewState[i] != m_keyOldState[i])
					if (m_keyNewState[i] & 0x8000) {
						m_keys[i].bPressed = !m_keys[i].bHeld;
						m_keys[i].bHeld = true;
					}
					else {
						m_keys[i].bReleased = true;
						m_keys[i].bHeld = false;
					}

				m_keyOldState[i] = m_keyNewState[i];
			}

			INPUT_RECORD inBuf[32];
			DWORD events = 0;
			GetNumberOfConsoleInputEvents(ConsoleInHDL, &events);
			if (events > 0)
				ReadConsoleInput(ConsoleInHDL, inBuf, events, &events);

			for (DWORD i = 0; i < events; i++)
				switch (inBuf[i].EventType) {
				case FOCUS_EVENT:
					m_bConsoleInFocus = inBuf[i].Event.FocusEvent.bSetFocus;
					break;

				case MOUSE_EVENT:
					switch (inBuf[i].Event.MouseEvent.dwEventFlags) {
					case MOUSE_MOVED:
						m_mousePosX = inBuf[i].Event.MouseEvent.dwMousePosition.X;
						m_mousePosY = inBuf[i].Event.MouseEvent.dwMousePosition.Y;
						break;
					case 0:
						for (int m = 0; m < 5; m++)
							m_mouseNewState[m] = (inBuf[i].Event.MouseEvent.dwButtonState & (1 << m)) > 0;
						break;
					}
					break;
				}

			for (int m = 0; m < 5; m++) {
				m_mouse[m].bPressed = false;
				m_mouse[m].bReleased = false;

				if (m_mouseNewState[m] != m_mouseOldState[m])
					if (m_mouseNewState[m]) {
						m_mouse[m].bPressed = true;
						m_mouse[m].bHeld = true;
					}
					else {
						m_mouse[m].bReleased = true;
						m_mouse[m].bHeld = false;
					}


				m_mouseOldState[m] = m_mouseNewState[m];
			}


			if (!loopSim(dt))
				AtomActive = false;

			wchar_t s[64];
			swprintf_s(s, 64, L"ConsoleRenderer - %s - FPS: %3.2f", AppName.c_str(), 1.0f / dt);
			SetConsoleTitle(s);
			WriteConsoleOutput(ConsoleHDL, db.GetBuffer(), { (short)db.GetW(), (short)db.GetH() }, { 0,0 }, &WindowRect);
		}

		if (finitSim()) {
			db.~DB();
			SetConsoleActiveScreenBuffer(OriginalConsole);
			RendFinished.notify_one();
		}
		else
			AtomActive = true;
	}
}

ConsoleRenderer::sKeyState ConsoleRenderer::GetKey(int nKeyID) { return m_keys[nKeyID]; }
ConsoleRenderer::sKeyState ConsoleRenderer::GetMouse(int nMouseButtonID) { return m_mouse[nMouseButtonID]; }
int ConsoleRenderer::GetMouseX() { return m_mousePosX; }
int ConsoleRenderer::GetMouseY() { return m_mousePosY; }
bool ConsoleRenderer::IsFocused() { return m_bConsoleInFocus; }

int ConsoleRenderer::Error(const wchar_t *msg) {
	wchar_t buf[256];
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), buf, 256, NULL);
	SetConsoleActiveScreenBuffer(OriginalConsole);
	wprintf(L"ERROR: %s\n\t%s\n", msg, buf);
	MessageBox(NULL, buf, msg, MB_OK);
	return 0;
}

BOOL ConsoleRenderer::CloseHandler(DWORD evt) {
	if (evt == CTRL_CLOSE_EVENT) {
		AtomActive = false;

		// Wait for thread to be exited
		std::unique_lock<std::mutex> ul(mutexRend);
		RendFinished.wait(ul);
	}
	return true;
}

std::atomic<bool> ConsoleRenderer::AtomActive(false);
std::condition_variable ConsoleRenderer::RendFinished;
std::mutex ConsoleRenderer::mutexRend;