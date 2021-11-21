#pragma once
#pragma comment(lib, "winmm.lib")

#ifndef UNICODE
#error Please enable UNICODE for your compiler! VS: Project Properties -> General -> \
Character Set -> Use Unicode. Thanks! - TIM
#endif

#include "DrawBuffer.h"

#include <windows.h>

#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <thread>
#include <atomic>
#include <condition_variable>

class ConsoleRenderer {
private:
	void RenderThread();
protected:
	DB db;

	std::wstring AppName;
	HANDLE OriginalConsole;
	CONSOLE_SCREEN_BUFFER_INFO OriginalConsoleInfo;
	HANDLE ConsoleHDL;
	HANDLE ConsoleInHDL;
	SMALL_RECT WindowRect;

	short m_keyOldState[256] = { 0 };
	short m_keyNewState[256] = { 0 };

	bool m_mouseOldState[5] = { 0 };
	bool m_mouseNewState[5] = { 0 };
	bool m_bConsoleInFocus = true;

	static std::atomic<bool> AtomActive;
	static std::condition_variable RendFinished;
	static std::mutex mutexRend;

	virtual bool initSim() = 0;
	virtual bool loopSim(float dt) = 0;
	virtual bool finitSim() = 0;


	struct sKeyState {
		bool bPressed;
		bool bReleased;
		bool bHeld;
	} m_keys[256], m_mouse[5];

	int m_mousePosX;
	int m_mousePosY;


	int Error(const wchar_t *msg);
	static BOOL CloseHandler(DWORD evt);
public:
	ConsoleRenderer();
	~ConsoleRenderer();

	int ConstructConsole(int width, int height, int fontw, int fonth);


	void Start();

	int ScreenW();
	int ScreenH();


	sKeyState GetKey(int nKeyID);

	sKeyState GetMouse(int nMouseButtonID);
	int GetMouseX();
	int GetMouseY();

	bool IsFocused();
};