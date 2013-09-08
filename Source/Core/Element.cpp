#include "Element.h"

namespace Ir {
	Element::Element(Object* parent)
		: Object(parent)
		, _visualStatus(EVisualStatus::InvalidLayout) {
		INIT_EVENT( OnMouseEnter );
		INIT_EVENT( OnMouseLeave );
		INIT_EVENT( OnMouseOver );
		INIT_EVENT( OnMouseDown );
		INIT_EVENT( OnMouseUp );
		INIT_EVENT( OnMouseDrag );
		INIT_EVENT( OnClick );

		memset(&_visual, 0, sizeof(Visual));
	}
}