#include "EllipseGeometry.h"

namespace Ir {
	EllipseGeometry::EllipseGeometry(Object* parent)
		: Geometry(parent) {
		OBJECT_PROPERTY( Center );
		OBJECT_PROPERTY( RadiusX );
		OBJECT_PROPERTY( RadiusY );
	}

	bool EllipseGeometry::ContainsPoint(vec2f point) const {
		return false;
	}
}