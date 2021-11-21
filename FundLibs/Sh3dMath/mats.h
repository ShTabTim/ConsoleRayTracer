#pragma once

typedef struct mat2 {
	double 
		M11, M12,
		M21, M22;
	mat2(
		double M11 = 1, double M12 = 0,
		double M21 = 0, double M22 = 1
	);
}mat2;

typedef struct mat3 {
	double 
		M11, M12, M13,
		M21, M22, M23,
		M31, M32, M33;
	mat3(
		double M11 = 1, double M12 = 0, double M13 = 0,
		double M21 = 0, double M22 = 1, double M23 = 0,
		double M31 = 0, double M32 = 0, double M33 = 1
	);
}mat3;

typedef struct mat4 {
	double 
		M11, M12, M13, M14,
		M21, M22, M23, M24,
		M31, M32, M33, M34,
		M41, M42, M43, M44;
	mat4(
		double M11 = 1, double M12 = 0, double M13 = 0, double M14 = 0,
		double M21 = 0, double M22 = 1, double M23 = 0, double M24 = 0,
		double M31 = 0, double M32 = 0, double M33 = 1, double M34 = 0,
		double M41 = 0, double M42 = 0, double M43 = 0, double M44 = 1
	);
}mat4;

bool operator == (mat4 a, mat4 b);

mat2 operator + (mat2 a, mat2 b);
mat3 operator + (mat3 a, mat3 b);
mat4 operator + (mat4 a, mat4 b);

mat2 operator - (mat2 a, mat2 b);
mat3 operator - (mat3 a, mat3 b);
mat4 operator - (mat4 a, mat4 b);

mat2 operator * (mat2 a, mat2 b);
mat3 operator * (mat3 a, mat3 b);
mat4 operator * (mat4 a, mat4 b);

mat2 operator * (mat2 a, unsigned char b);
mat3 operator * (mat3 a, unsigned char b);
mat4 operator * (mat4 a, unsigned char b);

mat2 operator * (mat2 a, unsigned int b);
mat3 operator * (mat3 a, unsigned int b);
mat4 operator * (mat4 a, unsigned int b);

mat2 operator * (mat2 a, char b);
mat3 operator * (mat3 a, char b);
mat4 operator * (mat4 a, char b);

mat2 operator * (mat2 a, int b);
mat3 operator * (mat3 a, int b);
mat4 operator * (mat4 a, int b);

mat2 operator * (mat2 a, float b);
mat3 operator * (mat3 a, float b);
mat4 operator * (mat4 a, float b);

mat2 operator * (mat2 a, double b);
mat3 operator * (mat3 a, double b);
mat4 operator * (mat4 a, double b);

mat2 operator / (mat2 a, unsigned char b);
mat3 operator / (mat3 a, unsigned char b);
mat4 operator / (mat4 a, unsigned char b);

mat2 operator / (mat2 a, unsigned int b);
mat3 operator / (mat3 a, unsigned int b);
mat4 operator / (mat4 a, unsigned int b);

mat2 operator / (mat2 a, char b);
mat3 operator / (mat3 a, char b);
mat4 operator / (mat4 a, char b);

mat2 operator / (mat2 a, int b);
mat3 operator / (mat3 a, int b);
mat4 operator / (mat4 a, int b);

mat2 operator / (mat2 a, float b);
mat3 operator / (mat3 a, float b);
mat4 operator / (mat4 a, float b);

mat2 operator / (mat2 a, double b);
mat3 operator / (mat3 a, double b);
mat4 operator / (mat4 a, double b);