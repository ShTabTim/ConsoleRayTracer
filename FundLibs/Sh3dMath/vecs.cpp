#include "vecs.h"

vec2::vec2(double v) : x(v), y(v) {}
vec2::vec2(double x, double y) : x(x), y(y) {}
vec2::vec2(vec3 u) : x(u.x), y(u.y) {}
vec2::vec2(vec4 u) : x(u.x), y(u.y) {}

vec3::vec3(double v):x(v), y(v){}
vec3::vec3(double x, double y, double z) : x(x), y(y), z(z) {}
vec3::vec3(vec2 u, double z) : x(u.x), y(u.y), z(z) {}
vec3::vec3(vec4 u) : x(u.x), y(u.y), z(u.z) {}

vec4::vec4(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}
vec4::vec4(vec2 u, double z, double w) : x(u.x), y(u.y), z(z), w(w) {}
vec4::vec4(vec3 u, double w) : x(u.x), y(u.y), z(u.z), w(w) {}

vec2 vec2::operator+=(vec2 const& other) {
    x += other.x;
    y += other.y;
    return *this; 
}
vec2 vec2::operator-=(vec2 const& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}
vec2 vec2::operator-() { return vec2(-x, -y); }
vec2 vec2::operator * (double const& other) { return vec2(x * other, y * other); }
vec2 vec2::operator / (double const& other) { return vec2(x / other, y / other); }
vec2 vec2::operator+(vec2 const& other) { return vec2(x + other.x, y + other.y); }
vec2 vec2::operator-(vec2 const& other) { return vec2(x - other.x, y - other.y); }
vec2 vec2::operator*(vec2 const& other) { return vec2(x * other.x, y * other.y); }
vec2 vec2::operator/(vec2 const& other) { return vec2(x / other.x, y / other.y); }
float vec2::operator%(vec2 const& other) { return x * other.x + y * other.y; }

vec3 vec3::operator+=(vec3 const& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}
vec3 vec3::operator-=(vec3 const& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}
vec3 vec3::operator-() { return vec3(-x, -y, -z); }
vec3 vec3::operator * (double const& other) { return vec3(x * other, y * other, z * other); }
vec3 vec3::operator / (double const& other) { return vec3(x / other, y / other, z / other); }
vec3 vec3::operator+(vec3 const& other) { return vec3(x + other.x, y + other.y, z + other.z); }
vec3 vec3::operator-(vec3 const& other) { return vec3(x - other.x, y - other.y, z - other.z); }
vec3 vec3::operator*(vec3 const& other) { return vec3(x * other.x, y * other.y, z * other.z); }
vec3 vec3::operator/(vec3 const& other) { return vec3(x / other.x, y / other.y, z / other.z); }
float vec3::operator%(vec3 const& other) { return x * other.x + y * other.y + z * other.z; }


vec4 vec4::operator+=(vec4 const& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}
vec4 vec4::operator-=(vec4 const& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}
vec4 vec4::operator-() { return vec4(-x, -y, -z, -w); }
vec4 vec4::operator * (double const& other) { return vec4(x * other, y * other, z * other, w * other); }
vec4 vec4::operator / (double const& other) { return vec4(x / other, y / other, z / other, w / other); }
vec4 vec4::operator+(vec4 const& other) { return vec4(x + other.x, y + other.y, z + other.z, w + other.w); }
vec4 vec4::operator-(vec4 const& other) { return vec4(x - other.x, y - other.y, z - other.z, w - other.w); }
vec4 vec4::operator*(vec4 const& other) { return vec4(x * other.x, y * other.y, z * other.z, w * other.w); }
vec4 vec4::operator/(vec4 const& other) { return vec4(x / other.x, y / other.y, z / other.z, w / other.w); }
float vec4::operator%(vec4 const& other) { return x * other.x + y * other.y + z * other.z + w * other.w; }