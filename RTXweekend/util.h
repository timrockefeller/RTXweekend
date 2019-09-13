#pragma once
#include "vec3.h"
#include "ray.h";

inline vec3 color(const ray &r) {
	vec3 direction_nor = normal(r.direction());
	float t = 0.5*(direction_nor.y() + 1.0);
	return (1.0 - t) * vec3(1.0) + t * vec3(0.5, 0.7, 1.0);
}