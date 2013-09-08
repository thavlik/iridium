#pragma once

#include "Element.h"

namespace Ir {
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	class Control : public Element {
	public:
		Control(Object* parent);

	public:
		StringProperty Name, Style;
		BrushProperty FillBrush, BorderBrush;
		MarginProperty Padding, Margin, BorderThickness;		
		MetricProperty Width, MinWidth, MaxWidth;
		MetricProperty Height, MinHeight, MaxHeight;
		ContentProperty Content;
		FloatProperty Opacity;

		Event<>
			OnKeyDown, OnKeyUp,
			OnFocus, OnBlur;

		virtual void UpdateVisual(LayoutEngine* engine) const;
	};
}