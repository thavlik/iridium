#include "Text.h"

namespace Ir {
	Text::Text(Object* parent)
		: Element(parent) {
		INIT_LAYOUT_PROPERTY( Font );
		INIT_LAYOUT_PROPERTY( Content );
	}

	void Text::UpdateVisual(LayoutEngine* engine) const {
		// Make sure we free the memory used last time
		engine->ClearVisual(_visual);

		// Do some initial setup
		_visual.Type = EVisualType::Text;
		_visual.Parent = getParent()->getVisual();

		Visuals::Text& t = _visual.Text;
		t.length = Content.getLength();
		t.str = new char[t.length + 1];
		memcpy(t.str, Content, t.length + 1);

		// Calculate the actual width and height of the text
		//((FontFamily*)Font).CalcBounds(_visual.ActualWidth, _visual.ActualHeight);
	}
}