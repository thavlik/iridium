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

		MetricProperty MinWidth, MaxWidth, Width;

		MetricProperty MinHeight, MaxHeight, Height;

		ContentProperty Content;

		FloatProperty Opacity;

		GeometryProperty Clip;

		VisibilityProperty Visibility;

		TransformProperty LayoutTransform, RenderTransform;

	public:
		Event<>
			OnKeyDown, OnKeyUp,
			OnFocus, OnBlur;

	public:
		virtual void RequestSize(Measure& width, Measure& height) const;

	private:
	};
}