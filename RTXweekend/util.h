#pragma once
#include "vec3.h"
#include "ray.h"
#include "hitable.h"
#include "material.h"
namespace RTXW {
	inline double drand() {
		return rand() / (RAND_MAX + 1.0);
	}

	class U {
	public:
		static vec3 random_in_unit_sphere() {
			vec3 p;
			do {
				p = 2.0*vec3(drand(), drand(), drand()) - vec3(1.0);
			} while (p.squared_length() >= 1.0);
			return p;
		}


		static  vec3 color(const ray &r, hitable* world,int depth=0) {

			hit_record rec;
			if (world->hit(r, 0.001, INFINITY, rec)) {
				ray scattered;
				vec3 attenuation;
				if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered))
				{
					return attenuation * color(scattered, world, depth + 1);
				}
				return vec3(0);
			}
			vec3 direction_nor = normal(r.direction()); // skybox
			float t = 0.5*(direction_nor.y() + 1.0);
			return (1.0 - t) * vec3(1.0) + t * vec3(0.5, 0.7, 1.0);
		}
	};


}