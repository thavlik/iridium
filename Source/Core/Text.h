#pragma once

#include "Element.h"

namespace Ir {
	class Text : public Element {
	public:
		Text(Object* parent);

		FontProperty Font;
		StringProperty Content;

		virtual void UpdateVisual(LayoutEngine* engine) const;

	private:
	};
}