#pragma once
#include "hitable.h"

namespace RTXW {
	class material {
	public:
		virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const = 0;
	};

	class lambertain : public material { // diffuse
	public:
		lambertain(const vec3& a) :albedo(a) {}
		virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;
		vec3 albedo;
	};

	class metal : public material { // specular
	public:
		metal(const vec3& a, float f) : albedo(a) { fuzz = f < 1 ? f : 1; }
		virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;
		vec3 albedo;
		float fuzz;
	};
}