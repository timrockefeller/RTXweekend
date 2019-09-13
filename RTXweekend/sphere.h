#pragma once
#include "hitable.h"
namespace RTXW {
	class sphere :
		public hitable
	{
	public:
		sphere() = default;
		sphere(vec3 center_, float radius_) {
			center = center_;
			radius = radius_;
		}
		~sphere() = default;

		virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;

		vec3 center;
		float radius;
	};
}

