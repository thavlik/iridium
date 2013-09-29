#include "PathGeometry.h"

namespace Ir {
	PathGeometry::PathGeometry(Object* parent)
		: Geometry(parent) {
	}

	bool PathGeometry::ContainsPoint(vec2f point) const {
		return false;
	}
}