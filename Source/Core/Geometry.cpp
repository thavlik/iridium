#include "Geometry.h"

namespace Ir {
	Geometry::Geometry(Object* parent)
		: Object(parent) {
		OBJECT_PROPERTY(Transform);
	}
}