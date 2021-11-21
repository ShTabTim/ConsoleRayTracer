#include "vecUmat.h"

vec2 operator * (vec2 a, mat2 b) {
	a.x = a.x * b.M11 + a.y * b.M12;
	a.y = a.x * b.M21 + a.y * b.M22;
	return a;
}
vec3 operator * (vec3 a, mat3 b) {
	a.x = a.x * b.M11 + a.y * b.M12 + a.z * b.M13;
	a.y = a.x * b.M21 + a.y * b.M22 + a.z * b.M23;
	a.z = a.x * b.M31 + a.y * b.M32 + a.z * b.M33;
	return a;
}
vec4 operator * (vec4 a, mat4 b) {
	a.x = a.x * b.M11 + a.y * b.M12 + a.z * b.M13 + a.w * b.M14;
	a.y = a.x * b.M21 + a.y * b.M22 + a.z * b.M23 + a.w * b.M24;
	a.z = a.x * b.M31 + a.y * b.M32 + a.z * b.M33 + a.w * b.M34;
	a.w = a.x * b.M41 + a.y * b.M42 + a.z * b.M43 + a.w * b.M44;
	return a;
}