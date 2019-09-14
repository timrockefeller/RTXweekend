#pragma once
#include "vec3.h"
#include "ray.h"
#include "hitable.h"
namespace RTXW {
	class U {
	public:
		static  vec3 color(const ray &r, hitable* world) {
			
			hit_record rec;
			if (world->hit(r, 0.0, INFINITY, rec)) {
				return 0.5*(vec3(1) + rec.normal);
			}
			vec3 direction_nor = normal(r.direction()); // skybox
			float t = 0.5*(direction_nor.y() + 1.0);
			return (1.0 - t) * vec3(1.0) + t * vec3(0.5, 0.7, 1.0);
		}
	};

	inline double drand() {
		return rand() / (RAND_MAX + 1.0);
	}
}