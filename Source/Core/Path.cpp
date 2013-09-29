#include "Path.h"

namespace Ir {
	Path::Path(Object* parent)
		: Shape(parent) {
		CONTROL_PROPERTY(AFFECTS_LAYOUT, Data);
	}

	void Path::RequestSize(Measure& width, Measure& height) const {
	}
}