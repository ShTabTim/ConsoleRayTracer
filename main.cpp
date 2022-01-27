#include "FundLibs/ShConsoleGr/ConsoleRenderer.h"
#include "RayCast.h"

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
	vec(_mDim_) _vec(float x, float y, float z) { vec(_mDim_) vv; vv[0] = x; vv[1] = y; vv[2] = z; return vv; }
	vec(2) _vec(float x, float y) { vec(2) vv; vv[0] = x; vv[1] = y; return vv; }
	bool initSim() {
		short a[] = { 15, 7, 8, 0 };
		grrr.init(a);
		return true;
	}
	bool loopSim(float dt){
		r += dt;
		vec(_mDim_) light = norm(_vec(-0.5, 0.5, -1.0));
		vec(_mDim_) spherePos = _vec(3, 0, 0);
		vec(_mDim_) spherePos2 = _vec(0, 3, 0);
		for (int i = 0; i < ScrWW; i++) {
			for (int j = 0; j < ScrHH; j++) {
				vec(2) uv = _vec(((float)i) / ((float)ScrWW) * 2.0f - 1.0f, ((float)j) / ((float)ScrHH) * 2.0f - 1.0f);
				uv[0] *= aspect;
				vec(_mDim_) ro = _vec(-12, 0, -3);
				vec(_mDim_) rd = norm(_vec(2, uv[0], uv[1]));
				ro = rotateY(ro, 3.14159265/6);
				rd = rotateY(rd, 3.14159265/6);
				ro = rotateZ(ro, r);
				rd = rotateZ(rd, r);
				float diff = 1;
				for (int k = 0; k < 1; k++) {
					float minIt = 99999;
					vec(2) intersection;
					vec(_mDim_) pos_ro;
					vec(_mDim_) n(0);
					float albedo = 1;
					//vec(_mDim_) boxN = 0;
					//intersection = box(ro, rd, 1, boxN);
					//if (intersection.x > 0 && intersection.x < minIt) {
					//	minIt = intersection.x;
					//	n = boxN;
					//}
					sum(i, _mDim_, pos_ro[i] = ro[i] - spherePos[i]);
					intersection = sphere(pos_ro, rd, 1);
					if (intersection[0] > 0 && intersection[0] < minIt) {
						vec(_mDim_) itPoint;
						sum(i, _mDim_, itPoint[i] = pos_ro[i] + rd[i] * intersection[0]);
						minIt = intersection[0];
						n = norm(itPoint);
					}
					//intersection = plane(ro, rd, vec3(0, 0, -1), 2);
					//if (intersection.x > 0 && intersection.x < minIt) {
					//	minIt = intersection.x;
					//	n = vec3(0, 0, -1);
					//	albedo = 0.5;
					//}
					if (minIt < 99999) {
						diff *= (dot(n, light) * 0.5 + 0.5) * albedo;
						sum(i, _mDim_, ro[i] = ro[i] + rd[i] * (minIt - 0.0001));
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