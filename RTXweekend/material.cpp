#include "material.h"
#include "util.h"


using namespace RTXW;

bool lambertain::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const
{
	vec3 target = rec.p + rec.normal + U::random_in_unit_sphere();
	scattered = ray(rec.p, target - rec.p);
	attenuation = albedo;
	return true;
}

bool metal::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const
{
	vec3 reflected = reflect(normal(r_in.direction()), rec.normal);
	scattered = ray(rec.p, reflected + fuzz * U::random_in_unit_sphere());
	attenuation = albedo;
	return (dot(scattered.direction(), rec.normal) > 0);
}

bool dielectric::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const
{
	vec3 outward_normal;
	vec3 reflected = reflect(r_in.direction(), rec.normal);
	float ni_over_nt;
	attenuation = vec3(1.0);
	vec3 refracted;
	if (dot(r_in.direction(), rec.normal) > 0) {
		outward_normal = -rec.normal;
		ni_over_nt = ref_idx;
	}
	else {
		outward_normal = rec.normal;
		ni_over_nt = 1.0 / ref_idx;
	}
	if (refract(r_in.direction(), outward_normal, ni_over_nt, refracted)) {
		scattered = ray(rec.p, refracted);
	}
	else {
		scattered = ray(rec.p, reflected);
		return false;
	}
	return true;
}