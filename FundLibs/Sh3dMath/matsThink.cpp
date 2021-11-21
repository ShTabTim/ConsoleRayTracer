#include "matsThink.h"

#include <cmath>

double det(mat2 a) {
	return a.M11 * a.M22 - a.M12 * a.M21;
}
double det(mat3 a) {
	return a.M11 * det(mat2(a.M22, a.M23, a.M32, a.M33)) - a.M12 * det(mat2(a.M21, a.M23, a.M31, a.M33)) + a.M13 * det(mat2(a.M21, a.M22, a.M31, a.M32));
}
/*
vec3 operator ^ (vec3 a, vec3 b) {
	return vec3(
		a.y * b.z - b.y * a.z,
		a.z * b.x - b.z * a.x,
		a.x * b.y - b.x * a.y
		);
}
*/
mat2 rotMat(double a) {
	return mat2(
		cos(a), -sin(a),
		sin(a), cos(a)
	);
}

mat3 rotMat(double a, vec3 b) {
	return mat3(
		  cos(a) + (1 - cos(a))*b.x*b.x  , (1 - cos(a))*b.x*b.y - sin(a)*b.z, (1 - cos(a))*b.x*b.z + sin(a)*b.y,
		(1 - cos(a))*b.y*b.x + sin(a)*b.z,   cos(a) + (1 - cos(a))*b.y*b.y  , (1 - cos(a))*b.y*b.z - sin(a)*b.x,
		(1 - cos(a))*b.z*b.x - sin(a)*b.y, (1 - cos(a))*b.z*b.y + sin(a)*b.x,   cos(a) + (1 - cos(a))*b.z*b.z
	);
}

mat4 rotMat4X(double a){
	return mat4(
		1, 0, 0, 0,
		0, cos(a), -sin(a), 0,
		0, sin(a), cos(a), 0,
		0, 0, 0, 1
	);
}
mat4 rotMat4Y(double a){
	return mat4(
		cos(a), 0, sin(a), 0,
		0, 1, 0, 0,
		-sin(a), 0, cos(a), 0,
		0, 0, 0, 1
	);
}
mat4 rotMat4Z(double a){
	return mat4(
		cos(a), -sin(a), 0, 0,
		sin(a), cos(a), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);
}

mat4 rotMat4(double a, vec3 b) {
	return mat4(
		  cos(a) + (1 - cos(a))*b.x*b.x  , (1 - cos(a))*b.x*b.y - sin(a)*b.z, (1 - cos(a))*b.x*b.z + sin(a)*b.y, 0,
		(1 - cos(a))*b.y*b.x + sin(a)*b.z,   cos(a) + (1 - cos(a))*b.y*b.y  , (1 - cos(a))*b.y*b.z - sin(a)*b.x, 0,
		(1 - cos(a))*b.z*b.x - sin(a)*b.y, (1 - cos(a))*b.z*b.y + sin(a)*b.x,   cos(a) + (1 - cos(a))*b.z*b.z, 0,
		0, 0, 0, 1
	);
}

mat2 size(vec2 a) {
	return mat2(
		a.x, 0,
		0, a.y
	);
}

mat3 size(vec3 a) {
	return mat3(
		a.x, 0, 0,
		0, a.y, 0,
		0, 0, a.z
	);
}

mat4 size(vec4 a) {
	return mat4(
		a.x, 0, 0, 0,
		0, a.y, 0, 0,
		0, 0, a.z, 0,
		0, 0, 0, a.w
	);
}

mat3 trans(vec2 a) {
	return mat3(
		0, 0, a.x,
		0, 0, a.y,
		0, 0, 1
	);
}

mat4 trans(vec3 a) {
	return mat4(
		0, 0, 0, a.x,
		0, 0, 0, a.y,
		0, 0, 0, a.z,
		0, 0, 0, 1
	);
}

mat4 trans(vec4 a) {
	return mat4(
		0, 0, 0, a.x,
		0, 0, 0, a.y,
		0, 0, 0, a.z,
		0, 0, 0, 1
	);
}