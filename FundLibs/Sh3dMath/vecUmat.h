#pragma once

#include "vecs.h"
#include "mats.h"

vec2 operator * (vec2 a, mat2 b);
vec3 operator * (vec3 a, mat3 b);
vec4 operator * (vec4 a, mat4 b);