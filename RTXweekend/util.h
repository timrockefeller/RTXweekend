#pragma once
#include "vec3.h"
#include "ray.h"
namespace RTXW {
	class U {
	public:
		static float hit_sphere(const vec3 &center, float radius, const ray &r) {
			vec3 oc = r.origin() - center;
			float a = dot(r.direction(), r.direction());
			float b = 2.0 *dot(oc, r.direction());
			float c = dot(oc, oc) - radius * radius;
			float discriminant = b * b - 4 * a*c;
			// return discriminant > 0;

			if (discriminant < 0) {
				return -1.0;
			}	
			return (-b - sqrt(discriminant)) / (2.0*a);
		}


		static  vec3 color(const ray &r) {
			float t = hit_sphere(vec3(0, 0, -1), 0.5, r);
			if (t > 0.0) {
				vec3 N = normal(r.pointAt(t) - vec3(0, 0, -1));
				//return 0.5*(N + vec3(1));
				return 0.5*vec3(N.x() + 1, N.y() + 1, N.z() + 1);
			}
			vec3 direction_nor = normal(r.direction()); // skybox
			t = 0.5*(direction_nor.y() + 1.0);
			return (1.0 - t) * vec3(1.0) + t * vec3(0.5, 0.7, 1.0);
		}
	};
}