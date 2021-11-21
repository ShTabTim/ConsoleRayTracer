#include "mats.h"

mat2::mat2(
	double M11, double M12,
	double M21, double M22
) :
	M11(12), M12(12),
	M21(21), M22(M22)
{}

mat3::mat3(
	double M11, double M12, double M13,
	double M21, double M22, double M23,
	double M31, double M32, double M33
) :
	M11(M11), M12(M12), M13(M13),
	M21(M21), M22(M22), M23(M23),
	M31(M31), M32(M32), M33(M33)
{}

mat4::mat4(
	double M11, double M12, double M13, double M14,
	double M21, double M22, double M23, double M24,
	double M31, double M32, double M33, double M34,
	double M41, double M42, double M43, double M44
) :
	M11(M11), M12(M12), M13(M13), M14(M14),
	M21(M21), M22(M22), M23(M23), M24(M24),
	M31(M31), M32(M32), M33(M33), M34(M34),
	M41(M41), M42(M42), M43(M43), M44(M44)
{}

bool operator == (mat4 a, mat4 b) {
	return
		a.M11 == b.M11 &&
		a.M12 == b.M12 &&
		a.M13 == b.M13 &&
		a.M14 == b.M14 &&

		a.M21 == b.M21 &&
		a.M22 == b.M22 &&
		a.M23 == b.M23 &&
		a.M24 == b.M24 &&

		a.M31 == b.M31 &&
		a.M32 == b.M32 &&
		a.M33 == b.M33 &&
		a.M34 == b.M34 &&

		a.M41 == b.M41 &&
		a.M42 == b.M42 &&
		a.M43 == b.M43 &&
		a.M44 == b.M44;
}


mat2 operator + (mat2 a, mat2 b) {
	a.M11 += b.M11; a.M12 += b.M12;
	a.M21 += b.M21; a.M22 += b.M22;
	return a; 
}
mat3 operator + (mat3 a, mat3 b) {
	a.M11 += b.M11; a.M12 += b.M12; a.M13 += b.M13;
	a.M21 += b.M21; a.M22 += b.M22; a.M23 += b.M23;
	a.M31 += b.M31; a.M32 += b.M32; a.M33 += b.M33;
	return a; 
}
mat4 operator + (mat4 a, mat4 b) {
	a.M11 += b.M11; a.M12 += b.M12; a.M13 += b.M13; a.M14 += b.M14;
	a.M21 += b.M21; a.M22 += b.M22; a.M23 += b.M23; a.M24 += b.M24;
	a.M31 += b.M31; a.M32 += b.M32; a.M33 += b.M33; a.M34 += b.M34;
	a.M41 += b.M41; a.M42 += b.M42; a.M43 += b.M43; a.M44 += b.M44;
	return a;
}

mat2 operator - (mat2 a, mat2 b) {
	a.M11 -= b.M11; a.M12 -= b.M12;
	a.M21 -= b.M21; a.M22 -= b.M22;
	return a;
}
mat3 operator - (mat3 a, mat3 b) {
	a.M11 -= b.M11; a.M12 -= b.M12; a.M13 -= b.M13;
	a.M21 -= b.M21; a.M22 -= b.M22; a.M23 -= b.M23;
	a.M31 -= b.M31; a.M32 -= b.M32; a.M33 -= b.M33;
	return a;
}
mat4 operator - (mat4 a, mat4 b) {
	a.M11 -= b.M11; a.M12 -= b.M12; a.M13 -= b.M13; a.M14 -= b.M14;
	a.M21 -= b.M21; a.M22 -= b.M22; a.M23 -= b.M23; a.M24 -= b.M24;
	a.M31 -= b.M31; a.M32 -= b.M32; a.M33 -= b.M33; a.M34 -= b.M34;
	a.M41 -= b.M41; a.M42 -= b.M42; a.M43 -= b.M43; a.M44 -= b.M44;
	return a;
}

mat2 operator * (mat2 a, mat2 b) {
	a.M11 = a.M11 * b.M11 + a.M12 * b.M21;
	a.M12 = a.M11 * b.M12 + a.M12 * b.M22;

	a.M21 = a.M21 * b.M11 + a.M22 * b.M21;
	a.M22 = a.M21 * b.M12 + a.M22 * b.M22;
	return a;
}
mat3 operator * (mat3 a, mat3 b) {
	a.M11 = a.M11 * b.M11 + a.M12 * b.M21 + a.M13 * b.M31;
	a.M12 = a.M11 * b.M12 + a.M12 * b.M22 + a.M13 * b.M32;
	a.M13 = a.M11 * b.M13 + a.M12 * b.M23 + a.M13 * b.M33;

	a.M21 = a.M21 * b.M11 + a.M22 * b.M21 + a.M23 * b.M31;
	a.M22 = a.M21 * b.M12 + a.M22 * b.M22 + a.M23 * b.M32;
	a.M23 = a.M21 * b.M13 + a.M22 * b.M23 + a.M23 * b.M33;

	a.M31 = a.M31 * b.M11 + a.M32 * b.M21 + a.M33 * b.M31;
	a.M32 = a.M31 * b.M12 + a.M32 * b.M22 + a.M33 * b.M32;
	a.M33 = a.M31 * b.M13 + a.M32 * b.M23 + a.M33 * b.M33;
	return a;
}
mat4 operator * (mat4 a, mat4 b){
	a.M11 = a.M11 * b.M11 + a.M12 * b.M21 + a.M13 * b.M31 + a.M14 * b.M41;
	a.M12 = a.M11 * b.M12 + a.M12 * b.M22 + a.M13 * b.M32 + a.M14 * b.M42;
	a.M13 = a.M11 * b.M13 + a.M12 * b.M23 + a.M13 * b.M33 + a.M14 * b.M43;
	a.M14 = a.M11 * b.M14 + a.M12 * b.M24 + a.M13 * b.M34 + a.M14 * b.M44;

	a.M21 = a.M21 * b.M11 + a.M22 * b.M21 + a.M23 * b.M31 + a.M24 * b.M41;
	a.M22 = a.M21 * b.M12 + a.M22 * b.M22 + a.M23 * b.M32 + a.M24 * b.M42;
	a.M22 = a.M21 * b.M13 + a.M22 * b.M23 + a.M23 * b.M33 + a.M24 * b.M43;
	a.M24 = a.M21 * b.M14 + a.M22 * b.M24 + a.M23 * b.M34 + a.M24 * b.M44;

	a.M31 = a.M31 * b.M11 + a.M32 * b.M21 + a.M33 * b.M31 + a.M34 * b.M41;
	a.M32 = a.M31 * b.M12 + a.M32 * b.M22 + a.M33 * b.M32 + a.M34 * b.M42;
	a.M32 = a.M31 * b.M13 + a.M32 * b.M23 + a.M33 * b.M33 + a.M34 * b.M43;
	a.M34 = a.M31 * b.M14 + a.M32 * b.M24 + a.M33 * b.M34 + a.M34 * b.M44;

	a.M41 = a.M41 * b.M11 + a.M42 * b.M21 + a.M43 * b.M31 + a.M44 * b.M41;
	a.M42 = a.M41 * b.M12 + a.M42 * b.M22 + a.M43 * b.M32 + a.M44 * b.M42;
	a.M42 = a.M41 * b.M13 + a.M42 * b.M23 + a.M43 * b.M33 + a.M44 * b.M43;
	a.M44 = a.M41 * b.M14 + a.M42 * b.M24 + a.M43 * b.M34 + a.M44 * b.M44;
	return a;
}

mat2 operator * (mat2 a, unsigned char b) {
	a.M11 *= b; a.M12 *= b;
	a.M21 *= b; a.M22 *= b;
	return a;
}
mat3 operator * (mat3 a, unsigned char b) {
	a.M11 *= b; a.M12 *= b; a.M13 *= b;
	a.M21 *= b; a.M22 *= b; a.M23 *= b;
	a.M31 *= b; a.M32 *= b; a.M33 *= b;
	return a;
}
mat4 operator * (mat4 a, unsigned char b) {
	a.M11 *= b; a.M12 *= b; a.M13 *= b; a.M14 *= b;
	a.M21 *= b; a.M22 *= b; a.M23 *= b; a.M24 *= b;
	a.M31 *= b; a.M32 *= b; a.M33 *= b; a.M34 *= b;
	a.M41 *= b; a.M42 *= b; a.M43 *= b; a.M44 *= b;
	return a;
}

mat2 operator * (mat2 a, unsigned int b) {
	a.M11 *= b; a.M12 *= b;
	a.M21 *= b; a.M22 *= b;
	return a;
}
mat3 operator * (mat3 a, unsigned int b) {
	a.M11 *= b; a.M12 *= b; a.M13 *= b;
	a.M21 *= b; a.M22 *= b; a.M23 *= b;
	a.M31 *= b; a.M32 *= b; a.M33 *= b;
	return a;
}
mat4 operator * (mat4 a, unsigned int b) {
	a.M11 *= b; a.M12 *= b; a.M13 *= b; a.M14 *= b;
	a.M21 *= b; a.M22 *= b; a.M23 *= b; a.M24 *= b;
	a.M31 *= b; a.M32 *= b; a.M33 *= b; a.M34 *= b;
	a.M41 *= b; a.M42 *= b; a.M43 *= b; a.M44 *= b;
	return a;
}

mat2 operator * (mat2 a, char b) {
	a.M11 *= b; a.M12 *= b;
	a.M21 *= b; a.M22 *= b;
	return a;
}
mat3 operator * (mat3 a, char b) {
	a.M11 *= b; a.M12 *= b; a.M13 *= b;
	a.M21 *= b; a.M22 *= b; a.M23 *= b;
	a.M31 *= b; a.M32 *= b; a.M33 *= b;
	return a;
}
mat4 operator * (mat4 a, char b) {
	a.M11 *= b; a.M12 *= b; a.M13 *= b; a.M14 *= b;
	a.M21 *= b; a.M22 *= b; a.M23 *= b; a.M24 *= b;
	a.M31 *= b; a.M32 *= b; a.M33 *= b; a.M34 *= b;
	a.M41 *= b; a.M42 *= b; a.M43 *= b; a.M44 *= b;
	return a;
}

mat2 operator * (mat2 a, int b) {
	a.M11 *= b; a.M12 *= b;
	a.M21 *= b; a.M22 *= b;
	return a;
}
mat3 operator * (mat3 a, int b) {
	a.M11 *= b; a.M12 *= b; a.M13 *= b;
	a.M21 *= b; a.M22 *= b; a.M23 *= b;
	a.M31 *= b; a.M32 *= b; a.M33 *= b;
	return a;
}
mat4 operator * (mat4 a, int b) {
	a.M11 *= b; a.M12 *= b; a.M13 *= b; a.M14 *= b;
	a.M21 *= b; a.M22 *= b; a.M23 *= b; a.M24 *= b;
	a.M31 *= b; a.M32 *= b; a.M33 *= b; a.M34 *= b;
	a.M41 *= b; a.M42 *= b; a.M43 *= b; a.M44 *= b;
	return a;
}

mat2 operator * (mat2 a, float b) {
	a.M11 *= b; a.M12 *= b;
	a.M21 *= b; a.M22 *= b;
	return a;
}
mat3 operator * (mat3 a, float b) {
	a.M11 *= b; a.M12 *= b; a.M13 *= b;
	a.M21 *= b; a.M22 *= b; a.M23 *= b;
	a.M31 *= b; a.M32 *= b; a.M33 *= b;
	return a;
}
mat4 operator * (mat4 a, float b) {
	a.M11 *= b; a.M12 *= b; a.M13 *= b; a.M14 *= b;
	a.M21 *= b; a.M22 *= b; a.M23 *= b; a.M24 *= b;
	a.M31 *= b; a.M32 *= b; a.M33 *= b; a.M34 *= b;
	a.M41 *= b; a.M42 *= b; a.M43 *= b; a.M44 *= b;
	return a;
}

mat2 operator * (mat2 a, double b) {
	a.M11 *= b; a.M12 *= b;
	a.M21 *= b; a.M22 *= b;
	return a;
}
mat3 operator * (mat3 a, double b) {
	a.M11 *= b; a.M12 *= b; a.M13 *= b;
	a.M21 *= b; a.M22 *= b; a.M23 *= b;
	a.M31 *= b; a.M32 *= b; a.M33 *= b;
	return a;
}
mat4 operator * (mat4 a, double b) {
	a.M11 *= b; a.M12 *= b; a.M13 *= b; a.M14 *= b;
	a.M21 *= b; a.M22 *= b; a.M23 *= b; a.M24 *= b;
	a.M31 *= b; a.M32 *= b; a.M33 *= b; a.M34 *= b;
	a.M41 *= b; a.M42 *= b; a.M43 *= b; a.M44 *= b;
	return a;
}

mat2 operator / (mat2 a, unsigned char b) {
	a.M11 /= b; a.M12 /= b;
	a.M21 /= b; a.M22 /= b;
	return a;
}
mat3 operator / (mat3 a, unsigned char b) {
	a.M11 /= b; a.M12 /= b; a.M13 /= b;
	a.M21 /= b; a.M22 /= b; a.M23 /= b;
	a.M31 /= b; a.M32 /= b; a.M33 /= b;
	return a;
}
mat4 operator / (mat4 a, unsigned char b) {
	a.M11 /= b; a.M12 /= b; a.M13 /= b; a.M14 /= b;
	a.M21 /= b; a.M22 /= b; a.M23 /= b; a.M24 /= b;
	a.M31 /= b; a.M32 /= b; a.M33 /= b; a.M34 /= b;
	a.M41 /= b; a.M42 /= b; a.M43 /= b; a.M44 /= b;
	return a;
}

mat2 operator / (mat2 a, unsigned int b) {
	a.M11 /= b; a.M12 /= b;
	a.M21 /= b; a.M22 /= b;
	return a;
}
mat3 operator / (mat3 a, unsigned int b) {
	a.M11 /= b; a.M12 /= b; a.M13 /= b;
	a.M21 /= b; a.M22 /= b; a.M23 /= b;
	a.M31 /= b; a.M32 /= b; a.M33 /= b;
	return a;
}
mat4 operator / (mat4 a, unsigned int b) {
	a.M11 /= b; a.M12 /= b; a.M13 /= b; a.M14 /= b;
	a.M21 /= b; a.M22 /= b; a.M23 /= b; a.M24 /= b;
	a.M31 /= b; a.M32 /= b; a.M33 /= b; a.M34 /= b;
	a.M41 /= b; a.M42 /= b; a.M43 /= b; a.M44 /= b;
	return a;
}

mat2 operator / (mat2 a, char b) {
	a.M11 /= b; a.M12 /= b;
	a.M21 /= b; a.M22 /= b;
	return a;
}
mat3 operator / (mat3 a, char b) {
	a.M11 /= b; a.M12 /= b; a.M13 /= b;
	a.M21 /= b; a.M22 /= b; a.M23 /= b;
	a.M31 /= b; a.M32 /= b; a.M33 /= b;
	return a;
}
mat4 operator / (mat4 a, char b) {
	a.M11 /= b; a.M12 /= b; a.M13 /= b; a.M14 /= b;
	a.M21 /= b; a.M22 /= b; a.M23 /= b; a.M24 /= b;
	a.M31 /= b; a.M32 /= b; a.M33 /= b; a.M34 /= b;
	a.M41 /= b; a.M42 /= b; a.M43 /= b; a.M44 /= b;
	return a;
}

mat2 operator / (mat2 a, int b) {
	a.M11 /= b; a.M12 /= b;
	a.M21 /= b; a.M22 /= b;
	return a;
}
mat3 operator / (mat3 a, int b) {
	a.M11 /= b; a.M12 /= b; a.M13 /= b;
	a.M21 /= b; a.M22 /= b; a.M23 /= b;
	a.M31 /= b; a.M32 /= b; a.M33 /= b;
	return a;
}
mat4 operator / (mat4 a, int b) {
	a.M11 /= b; a.M12 /= b; a.M13 /= b; a.M14 /= b;
	a.M21 /= b; a.M22 /= b; a.M23 /= b; a.M24 /= b;
	a.M31 /= b; a.M32 /= b; a.M33 /= b; a.M34 /= b;
	a.M41 /= b; a.M42 /= b; a.M43 /= b; a.M44 /= b;
	return a;
}

mat2 operator / (mat2 a, float b) {
	a.M11 /= b; a.M12 /= b;
	a.M21 /= b; a.M22 /= b;
	return a;
}
mat3 operator / (mat3 a, float b) {
	a.M11 /= b; a.M12 /= b; a.M13 /= b;
	a.M21 /= b; a.M22 /= b; a.M23 /= b;
	a.M31 /= b; a.M32 /= b; a.M33 /= b;
	return a;
}
mat4 operator / (mat4 a, float b) {
	a.M11 /= b; a.M12 /= b; a.M13 /= b; a.M14 /= b;
	a.M21 /= b; a.M22 /= b; a.M23 /= b; a.M24 /= b;
	a.M31 /= b; a.M32 /= b; a.M33 /= b; a.M34 /= b;
	a.M41 /= b; a.M42 /= b; a.M43 /= b; a.M44 /= b;
	return a;
}

mat2 operator / (mat2 a, double b) {
	a.M11 /= b; a.M12 /= b;
	a.M21 /= b; a.M22 /= b;
	return a;
}
mat3 operator / (mat3 a, double b) {
	a.M11 /= b; a.M12 /= b; a.M13 /= b;
	a.M21 /= b; a.M22 /= b; a.M23 /= b;
	a.M31 /= b; a.M32 /= b; a.M33 /= b;
	return a;
}
mat4 operator / (mat4 a, double b) {
	a.M11 /= b; a.M12 /= b; a.M13 /= b; a.M14 /= b;
	a.M21 /= b; a.M22 /= b; a.M23 /= b; a.M24 /= b;
	a.M31 /= b; a.M32 /= b; a.M33 /= b; a.M34 /= b;
	a.M41 /= b; a.M42 /= b; a.M43 /= b; a.M44 /= b;
	return a;
}