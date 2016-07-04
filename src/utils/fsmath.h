#pragma once

#include <cstdint>
#include <climits>
#include <stdexcept>
#include <algorithm>
#include <glm/vec3.hpp>
#include <glm/mat3x3.hpp>


namespace glm {
	typedef tmat3x3<double, highp> dmat3x3;
}

namespace fsmath {
#define MAX_UINT_POWER2 (1 << (sizeof(unsigned int) * 8 - 1))

	inline double nextPowerOf2(double x)
	{
		double exponent = std::ceil(std::log2(x));
		return pow(2, exponent);
	}

	inline glm::dvec3 allNextPowerOf2(const glm::dvec3 &vec) {
		return glm::dvec3(
			nextPowerOf2(vec.x),
			nextPowerOf2(vec.y),
			nextPowerOf2(vec.z)
			);
	}

	inline bool anyLess(const glm::dvec3 &v1, const glm::dvec3 &v2) {
		return ((v1.x < v2.x)
			|| (v1.y < v2.y)
			|| (v1.z < v2.z));
	}

	inline glm::dvec3 allMin(const glm::dvec3 &v1, const glm::dvec3 &v2) {
		return glm::dvec3(
			std::min(v1.x, v2.x),
			std::min(v1.y, v2.y),
			std::min(v1.z, v2.z)
			);
	}

	inline glm::dvec3 allMax(const glm::dvec3 &v1, const glm::dvec3 &v2) {
		return glm::dvec3(
			std::max(v1.x, v2.x),
			std::max(v1.y, v2.y),
			std::max(v1.z, v2.z)
			);
	}

	inline glm::dvec3 allCeil(const glm::dvec3 &vec) {
		return glm::dvec3(
			std::ceil(vec.x),
			std::ceil(vec.y),
			std::ceil(vec.z)
			);
	}

	inline bool insideBox(const glm::dvec3 &point, const glm::dvec3 &minCorner, const glm::dvec3 &extent) {
		return !(anyLess(point, minCorner) || anyLess(minCorner + extent, point));
	}

}
