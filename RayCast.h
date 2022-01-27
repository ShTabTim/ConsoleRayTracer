#pragma once
#include <math.h>
#include "FundLibs/Sh3dMath/tenzor.h"

#define _mDim_ 3

float clamp(float value, float min, float max) { return fmax(fmin(value, max), min); }
float sign(float a) { return (0 < a) - (a < 0); }
float step(float edge, float x) { return x > edge; }

float dot(vec(_mDim_) a, vec(_mDim_) b) { float c = 0; sum(i, _mDim_, c += a[i] * b[i]); return c; }

vec(_mDim_) norm(vec(_mDim_) v) { vec(_mDim_) vv; float l = 1/sqrt(dot(v, v)); sum(i, _mDim_, vv[i] = v[i] * l); return vv; }
//vec(_mDim_) abs(vec(_mDim_) const& v) { vec(_mDim_) vv; sum(i, _mDim_, vv[i] = abs(v[i])); return vv; }
//vec(_mDim_) sign(vec(_mDim_) const& v) { vec(_mDim_) vv; sum(i, _mDim_, vv[i] = sign(v[i])); return vv;}
//vec(_mDim_) step(vec(_mDim_) const& edge, vec(_mDim_) v) { vec(_mDim_) vv; sum(i, _mDim_, vv[i] = sign(edge[i], v[i])); return vv; }
vec(_mDim_) reflect(vec(_mDim_) rd, vec(_mDim_) n) { vec(_mDim_) vv; float dot_2_nrd = dot(n, rd); sum(i, _mDim_, vv[i] = rd[i] - n[i] * dot_2_nrd); return vv; }

vec(_mDim_) rotateX(vec(_mDim_) a, float angle) {
    float sa = sin(angle), ca = cos(angle);
    vec(_mDim_) vv;
    sum(i, _mDim_, vv[i] = a[i]);
    vv[1] = a[1] * ca - a[2] * sa;
    vv[2] = a[1] * sa + a[2] * ca;
    return vv;
}

vec(_mDim_) rotateY(vec(_mDim_) a, float angle) {
    float sa = sin(angle), ca = cos(angle);
    vec(_mDim_) vv;
    sum(i, _mDim_, vv[i] = a[i]);
    vv[0] = a[0] * ca - a[2] * sa;
    vv[2] = a[0] * sa + a[2] * ca;
    return vv;
}

vec(_mDim_) rotateZ(vec(_mDim_) a, float angle) {
    float sa = sin(angle), ca = cos(angle);
    vec(_mDim_) vv;
    sum(i, _mDim_, vv[i] = a[i]);
    vv[0] = a[0] * ca - a[1] * sa;
    vv[1] = a[0] * sa + a[1] * ca;
    return vv;
}

vec(2) sphere(vec(_mDim_) ro, vec(_mDim_) rd, float r) {
    float b = -dot(ro, rd);
    float c = dot(ro, ro) - r * r;
    float h = b * b - c;
    if (h < 0.0) return vec(2)(-1.0);
    h = sqrt(h);
    vec(2) vv;
    vv[0] = b - h;
    vv[1] = b + h;
    return vv;
}

//vec2 box(vec3 ro, vec3 rd, vec3 boxSize, vec3& outNormal) {
//    vec3 m = vec3(1.0) / rd;
//    vec3 n = m * ro;
//    vec3 k = abs(m) * boxSize;
//    vec3 t1 = -n - k;
//    vec3 t2 = -n + k;
//    float tN = fmax(fmax(t1.x, t1.y), t1.z);
//    float tF = fmin(fmin(t2.x, t2.y), t2.z);
//    if (tN > tF || tF < 0.0) return vec2(-1.0);
//    vec3 yzx = vec3(t1.y, t1.z, t1.x);
//    vec3 zxy = vec3(t1.z, t1.x, t1.y);
//    outNormal = -sign(rd) * step(yzx, t1) * step(zxy, t1);
//    return vec2(tN, tF);
//}
//
//float plane(vec3 ro, vec3 rd, vec3 p, float w) {
//    return -(ro % p + w) / (rd % p);
//}

template<typename T, size_t L>
class gr {
    T grr[L];
public:
    size_t Siz = L;
    void init(T* f) {
        for(int i = 0; i < Siz; i++)
            grr[i] = f[i];
    }
    T get(size_t i) {
        return grr[i];
    }
};