#pragma once
#include<cmath>
namespace RTXW {
	class vec3
	{
	public:
		vec3() {};
		vec3(float e0, float e1, float e2) {
			e[0] = e0;
			e[1] = e1;
			e[2] = e2;
		}
		vec3(float r) {
			e[0] = e[1] = e[2] = r;
		}
		~vec3() = default;

		inline float x() const { return e[0]; }
		inline float y() const { return e[1]; }
		inline float z() const { return e[2]; }
		inline float r() const { return e[0]; }
		inline float g() const { return e[1]; }
		inline float b() const { return e[2]; }

		inline const vec3& operator+() const { return *this; }
		inline vec3& operator-() const { return vec3(-e[0], -e[1], -e[2]); }
		inline float operator[](int i) const { return e[i]; }
		inline float& operator[](int i) { return e[i]; }

		inline vec3& operator+=(const vec3 &v2);
		inline vec3& operator-=(const vec3 &v2);
		inline vec3& operator*=(const vec3 &v2);
		inline vec3& operator/=(const vec3 &v2);
		inline vec3& operator*=(const float t);
		inline vec3& operator/=(const float t);

		inline float length()const {
			return sqrt(squared_length());
		}
		inline float squared_length() const {
			return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
		}
		inline vec3& normalize();

		float e[3];

	};

	inline vec3& vec3::normalize() {
		float k = 1.0 / length();
		e[0] *= k; e[1] *= k; e[2] *= k;
		return *this;
	}


	inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
		return vec3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
	}
	inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
		return vec3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
	}
	inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
		return vec3(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]);
	}
	inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
		return vec3(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]);
	}
	inline vec3 operator*(const vec3 &v1, float t) {
		return vec3(v1[0] * t, v1[1] * t, v1[2] * t);
	}
	inline vec3 operator*(float t, const vec3 &v1) {
		return vec3(v1[0] * t, v1[1] * t, v1[2] * t);
	}
	inline vec3 operator/(const vec3 &v1, const float t) {
		return vec3(v1[0] / t, v1[1] / t, v1[2] / t);
	}

	inline float dot(const vec3 &v1, const vec3 &v2) {
		return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
	}
	inline vec3 cross(const vec3 &v1, const vec3 &v2) {
		return vec3(
			v1[1] * v2[2] - v1[2] * v2[1],
			v1[2] * v2[0] - v1[0] * v2[2],
			v1[0] * v2[1] - v1[1] * v2[0]
		);
	}
	inline vec3 normal(const vec3 & v) {
		return v / v.length();
	}
	inline vec3 sqrtv(const vec3 & v) {
		return vec3(sqrt(v[0]), sqrt(v[1]), sqrt(v[2]));
	}
	inline vec3 reflect(const vec3& v, const vec3& n) {
		return v - 2 * dot(v, n)*n;
	}

	inline vec3& vec3::operator+=(const vec3 &v2) {
		e[0] += v2[0];
		e[1] += v2[1];
		e[2] += v2[2];
		return *this;
	}
	inline vec3& vec3::operator-=(const vec3 &v2) {
		e[0] -= v2[0];
		e[1] -= v2[1];
		e[2] -= v2[2];
		return *this;
	}
	inline vec3& vec3::operator*=(const vec3 &v2) {
		e[0] *= v2[0];
		e[1] *= v2[1];
		e[2] *= v2[2];
		return *this;
	}
	inline vec3& vec3::operator/=(const vec3 &v2) {
		e[0] /= v2[0];
		e[1] /= v2[1];
		e[2] /= v2[2];
		return *this;
	}
	inline vec3& vec3::operator*=(const float t) {
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;
		return *this;
	}
	inline vec3& vec3::operator/=(const float t) {
		e[0] /= t;
		e[1] /= t;
		e[2] /= t;
		return *this;
	}
}