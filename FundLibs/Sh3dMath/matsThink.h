#pragma once

#include "mats.h"
#include "vecs.h"

#define M_PI 3.14159265358979323846 

#define rotMatDeg(aDeg) rotMat((aDeg)*M_PI/180)
#define rotMatDeg(aDeg, b) rotMat((aDeg)*M_PI/180, b)
#define rotMatDeg4(aDeg, b) rotMat((aDeg)*M_PI/180, b)

vec3 operator ^ (vec3 a, vec3 b);

double det(mat2 a);
double det(mat3 a);
//TODO : double det(mat4 a);

mat2 rotMat(double a);
mat3 rotMat(double a, vec3 b);
mat4 rotMat4(double a, vec3 b);

mat4 rotMat4X(double a);
mat4 rotMat4Y(double a);
mat4 rotMat4Z(double a);

mat2 size(vec2 a);
mat3 size(vec3 a);
mat4 size(vec4 a);

mat3 trans(vec2 a);
mat4 trans(vec3 a);
mat4 trans(vec4 a);