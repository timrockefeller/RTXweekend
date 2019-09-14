#pragma once
#include "ray.h"
namespace RTXW {
	class camera
	{
	public:
		camera() {
			origin = vec3(0.0);
			horizontal = vec3(4.0, 0.0, 0.0);
			vertical=vec3(0.0, 2.0, 0.0);
			lower_left_corner=vec3(-2.0, -1.0, -1.0);

		}

		ray getRay(float u, float v) {
			ray r(origin, lower_left_corner + u * horizontal + v * vertical);
			return r;
		}

		vec3 origin;
		vec3 lower_left_corner;
		vec3 horizontal;
		vec3 vertical;

	};


}