#pragma once
#include "hitable.h"
namespace RTXW {
	class hitablelist :
		public hitable
	{
	public:
		hitablelist() = default;
		hitablelist(hitable **list_, int num) { list = list_; list_size = num; }
		~hitablelist() = default;

		virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;

		size_t list_size;
		hitable **list;
	};

}