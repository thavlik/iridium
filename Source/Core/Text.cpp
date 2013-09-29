#include "Text.h"

namespace Ir {
	Text::Text(Object* parent)
		: Element(parent) {
		CONTROL_PROPERTY( AFFECTS_LAYOUT, Content );
	}

	void Text::RequestSize(Measure& width, Measure& height) const {
	}
}