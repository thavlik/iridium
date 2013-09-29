#include "Element.h"

namespace Ir {
	Element::Element(Object* parent)
		: Object(parent)
		, _visualStatus(EVisualStatus::InvalidLayout) {
		OBJECT_PROPERTY(ActualWidth);
		OBJECT_PROPERTY(ActualHeight);
		OBJECT_PROPERTY(ActualX);
		OBJECT_PROPERTY(ActualY);
		INIT_EVENT(OnMouseEnter);
		INIT_EVENT(OnMouseLeave);
		INIT_EVENT(OnMouseOver);
		INIT_EVENT(OnMouseDown);
		INIT_EVENT(OnMouseUp);
		INIT_EVENT(OnMouseDrag);
		INIT_EVENT(OnClick);
	}
}