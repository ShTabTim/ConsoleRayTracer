#include "FundLibs/ShConsoleGr/ConsoleRenderer.h"
#include "RayCast.h"
#include "FundLibs/Sh3dMath/IncMath.h"

#define PixSize 8
#define ScrWW (160)
#define ScrHH (92)

class MainRenderer : public ConsoleRenderer {
public:
	MainRenderer() { AppName = L"3D ray tracer"; }
private:
	float aspect = ((float)ScrWW)/ ((float)ScrHH);
	float r;
	gr<short, 4> grrr;
public:
	bool initSim() {
		short a[] = { 15, 7, 8, 0 };
		grrr.init(a);
		return true;
	}
	bool loopSim(float dt){
		r += dt;
		vec3 light = norm(vec3(-0.5, 0.5, -1.0));
		vec3 spherePos = vec3(3, 0, 0);
		vec3 spherePos2 = vec3(0, 3, 0);
		for (int i = 0; i < ScrWW; i++) {
			for (int j = 0; j < ScrHH; j++) {
				vec2 uv = vec2(i, j) / vec2(ScrWW, ScrHH) * 2.0f - 1.0f;
				uv.x *= aspect;
				vec3 ro = vec3(-12, 0, -3);
				vec3 rd = norm(vec3(2, uv.x, uv.y));
				ro = rotateY(ro, M_PI/6);
				rd = rotateY(rd, M_PI/6);
				ro = rotateZ(ro, r);
				rd = rotateZ(rd, r);
				float diff = 1;
				for (int k = 0; k < 1; k++) {
					float minIt = 99999;
					vec2 intersection;
					vec3 n = 0;
					float albedo = 1;
					vec3 boxN = 0;
					intersection = box(ro, rd, 1, boxN);
					if (intersection.x > 0 && intersection.x < minIt) {
						minIt = intersection.x;
						n = boxN;
					}
					intersection = sphere(ro - spherePos, rd, 1);
					if (intersection.x > 0 && intersection.x < minIt) {
						vec3 itPoint = ro - spherePos + rd * intersection.x;
						minIt = intersection.x;
						n = norm(itPoint);
					}
					//intersection = plane(ro, rd, vec3(0, 0, -1), 2);
					if (intersection.x > 0 && intersection.x < minIt) {
						minIt = intersection.x;
						n = vec3(0, 0, -1);
						albedo = 0.5;
					}
					if (minIt < 99999) {
						diff *= (n % light * 0.5 + 0.5) * albedo;
						ro = ro + rd * (minIt - 0.01);
						rd = reflect(rd, n);
					}
					else break;
				}
				int color = (int)(diff * grrr.Siz);
				color = clamp(color, 0, grrr.Siz-1);
				db.DrawPixel(i, j, 9608, grrr.get(color));
			}
		}
		return true;
	}
	bool finitSim(){
		return true;
	}
};


int main() {
	MainRenderer simulation;
	if (simulation.ConstructConsole(ScrWW, ScrHH, PixSize, PixSize))
		simulation.Start();
	else
		MessageBox(NULL, L"The simulation is die!", L"I DIE!", MB_OK);
	return 0;
}