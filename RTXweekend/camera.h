#pragma once
#include "ray.h"
namespace RTXW {
	const float M_PI = 3.14159265358979;

	inline vec3 random_in_unit_disk() {
		vec3 p;
		do {
			p = 2.0*vec3(drand(), drand(), 0) - vec3(1, 1, 0);
		} while (dot(p, p) > 1.0);
		return p;
	}

	class camera
	{
	public:
		camera() {
			origin = vec3(0.0);
			horizontal = vec3(4.0, 0.0, 0.0);
			vertical = vec3(0.0, 2.0, 0.0);
			lower_left_corner = vec3(-2.0, -1.0, -1.0);
		}

		camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect, float aperture, float focus_dist) {
			lens_radius = aperture / 2.0;

			float theta = vfov * M_PI / 180.0;
			float half_height = tan(theta / 2.0);
			float half_width = aspect * half_height;

			origin = lookfrom;
			w = normal(lookfrom - lookat);
			u = normal(cross(vup, w));
			v = cross(w, u);

			lower_left_corner = origin - half_width * focus_dist * u - half_height * focus_dist * v - focus_dist * w;

			horizontal = 2 * half_width * focus_dist * u;
			vertical = 2 * half_height * focus_dist * v;
		}

		ray getRay(float u, float v) {
			vec3 rd = lens_radius * random_in_unit_disk();
			vec3 offset = u * rd.x() + v * rd.y();
			return ray(origin + offset, lower_left_corner + u * horizontal + v * vertical - origin - offset);
		}

		vec3 u, v, w;
		vec3 origin;
		vec3 lower_left_corner;
		vec3 horizontal;
		vec3 vertical;
		float lens_radius;
	};


}