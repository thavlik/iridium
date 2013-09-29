#include "LineGeometry.h"

namespace Ir {
	LineGeometry::LineGeometry(Object* parent)
		: Geometry(parent) {
		OBJECT_PROPERTY( Start );
		OBJECT_PROPERTY( End );
	}

	bool LineGeometry::ContainsPoint(vec2f point) const {
		return false;
	}
}