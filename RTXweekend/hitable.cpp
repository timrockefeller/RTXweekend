#include "hitable.h"
#include "sphere.h"
#include "hitablelist.h"

using namespace RTXW;


bool hitablelist::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
	hit_record temprec;
	bool hit_anything = false;
	float closest_so_far = t_max;
	for (size_t i = 0; i < list_size; i++) {
		if (list[i]->hit(r, t_min, t_max, temprec)) {
			hit_anything = true;
			closest_so_far = temprec.t;
			rec = temprec;
		}
	}
	return hit_anything;
}


bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b*b - a*c;

	if (discriminant > 0) {
		float temp = (-b - sqrt(b*b - a*c)) / a;
		if (temp<t_max&&temp>t_min) {
			rec.t = temp;
			rec.p = r.pointAt(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
		temp = (-b + sqrt(b*b - a * c)) / a;
		if (temp<t_max&&temp>t_min) {
			rec.t = temp;
			rec.p = r.pointAt(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
	}
	return false;
}