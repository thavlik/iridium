#include "RectangleGeometry.h"

namespace Ir {
	RectangleGeometry::RectangleGeometry(Object* parent)
		: Geometry(parent) {
		OBJECT_PROPERTY( Top );
		OBJECT_PROPERTY( Right );
		OBJECT_PROPERTY( Bottom );
		OBJECT_PROPERTY( Left );
	}

	bool RectangleGeometry::ContainsPoint(vec2f point) const {
		return false;
	}
}