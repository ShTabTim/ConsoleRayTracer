#pragma once

struct vec2;
struct vec3;
struct vec4;

typedef struct vec2 {
	double x, y;
	vec2(double v = 0);
	vec2(double x, double y);
	vec2(vec3 u);
	vec2(vec4 u);

	vec2 operator-();
	vec2 operator * (double const& other);
	vec2 operator / (double const& other);
	vec2 operator+(vec2 const& other);
	vec2 operator+=(vec2 const& other);
	vec2 operator-(vec2 const& other);
	vec2 operator-=(vec2 const& other);
	vec2 operator*(vec2 const& other);
	vec2 operator/(vec2 const& other);
	float operator%(vec2 const& other);
}vec2;

typedef struct vec3 {
	double x, y, z;
	vec3(double v = 0);
	vec3(double x, double y, double z = 0);
	vec3(vec2 u, double z = 0);
	vec3(vec4 u);

	vec3 operator-();
	vec3 operator * (double const& other);
	vec3 operator / (double const& other);
	vec3 operator+(vec3 const& other);
	vec3 operator+=(vec3 const& other);
	vec3 operator-(vec3 const& other);
	vec3 operator-=(vec3 const& other);
	vec3 operator*(vec3 const& other);
	vec3 operator/(vec3 const& other);
	float operator%(vec3 const& other);
}vec3;

typedef struct vec4 {
	double x, y, z, w;
	vec4(double x = 0, double y = 0, double z = 0, double w = 0);
	vec4(vec2 u, double z = 0, double w = 0);
	vec4(vec3 u, double w = 0);

	vec4 operator-();
	vec4 operator * (double const& other);
	vec4 operator / (double const& other);
	vec4 operator+(vec4 const& other);
	vec4 operator+=(vec4 const& other);
	vec4 operator-(vec4 const& other);
	vec4 operator-=(vec4 const& other);
	vec4 operator*(vec4 const& other);
	vec4 operator/(vec4 const& other);
	float operator%(vec4 const& other);
}vec4;