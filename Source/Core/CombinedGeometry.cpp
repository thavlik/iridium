#include "CombinedGeometry.h"

namespace Ir {
	CombinedGeometry::CombinedGeometry(Object* parent)
		: Geometry(parent) {
		OBJECT_PROPERTY(ShapeA);
		OBJECT_PROPERTY(ShapeB);
		OBJECT_PROPERTY(Mode);
	}

	bool CombinedGeometry::ContainsPoint(vec2f point) const {
		for(unsigned i = 0; i < getChildren().size(); ++i) {
			if(dynamic_cast<const Geometry*>(getChildren()[i])->ContainsPoint(point)) {
				return true;
			}
		}
		return false;
	}
}