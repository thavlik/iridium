#include "LayoutEngine.h"
#include "Visual.h"
#include "../Core/Control.h"

namespace Ir {
	LayoutEngine::LayoutEngine(unsigned maxVisuals)
		: _visuals(maxVisuals) {
	}

	void LayoutEngine::ClearControl(Visuals::Control& c) {
		delete[] c.Children;
	}

	void LayoutEngine::ClearText(Visuals::Text& t) {
		delete[] t.str;
		t.str = nullptr;
	}

	void LayoutEngine::ClearShape(Visuals::Shape& s) {

	}

	void LayoutEngine::ClearImage(Visuals::Image& img) {

	}

	void LayoutEngine::ClearVisual(Visual& visual) {
		switch(visual.Type) {
		case EVisualType::Control:
			ClearControl(visual.Control);
			break;
		case EVisualType::Shape:
			ClearShape(visual.Shape);
			break;
		case EVisualType::Text:
			ClearText(visual.Text);
			break;
		case EVisualType::Image:
			ClearImage(visual.Image);
			break;
		}
	}
}