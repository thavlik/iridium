#include "Rectangle.h"

namespace Ir {
	Rectangle::Rectangle(Object* parent)
		: Shape(parent) {
		OBJECT_PROPERTY(Width);
		OBJECT_PROPERTY(Height);
	}

	void Rectangle::RequestSize(Measure& width, Measure& height) const {
	}
}