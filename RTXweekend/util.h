#pragma once
#include "vec3.h"
#include "ray.h"
#include "hitable.h"
#include "material.h"
#include "sphere.h"
#include "hitablelist.h"
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


		static  vec3 color(const ray &r, hitable* world, int depth = 0) {

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

		static hitable * random_scene() {
			int n = 500;
			hitable **list = new hitable*[n + 1];
			list[0] = new sphere(vec3(0, -1000, 0), 1000, new lambertain(vec3(0.5)));
			int i = 1;
			for (int a = -11; a < 11; a += 5) {
				for (int b = -11; b < 11; b += 5) {
					float choose_mat = drand();
					vec3 center(a + 0.9*drand(), 0.2, b + 0.9*drand());
					if ((center - vec3(4, 0.2, 0)).length() > 0.9) {
						if (choose_mat < 0.8) {  // diffuse
							list[i++] = new sphere(
								center, 0.2,
								new lambertain(vec3(drand()*drand(),
									drand()*drand(),
									drand()*drand()))
							);
						}
						else if (choose_mat < 0.95) { // metal
							list[i++] = new sphere(
								center, 0.2,
								new metal(vec3(0.5*(1 + drand()),
									0.5*(1 + drand()),
									0.5*(1 + drand())),
									0.5*drand())
							);
						}
						else {  // glass
							list[i++] = new sphere(center, 0.2, new dielectric(1.5));
						}
					}
				}
			}

			list[i++] = new sphere(vec3(0, 1, 0), 1.0, new dielectric(1.5));
			list[i++] = new sphere(vec3(-4, 1, 0), 1.0, new lambertain(vec3(0.4, 0.2, 0.1)));
			list[i++] = new sphere(vec3(4, 1, 0), 1.0, new metal(vec3(0.7, 0.6, 0.5), 0.0));

			return new hitablelist(list, i);
		}
	};


}