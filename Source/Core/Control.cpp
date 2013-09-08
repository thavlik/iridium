#include "Control.h"

namespace Ir {
	Control::Control(Object* parent)
		: Element(parent) {
		INIT_VISUAL_PROPERTY( Name );
		INIT_VISUAL_PROPERTY( Style );
		INIT_VISUAL_PROPERTY( FillBrush );
		INIT_VISUAL_PROPERTY( BorderBrush );
		INIT_VISUAL_PROPERTY( Opacity );

		INIT_LAYOUT_PROPERTY( Padding );
		INIT_LAYOUT_PROPERTY( Margin );		
		INIT_LAYOUT_PROPERTY( BorderThickness );
		INIT_LAYOUT_PROPERTY( Width );
		INIT_LAYOUT_PROPERTY( Height );
		INIT_LAYOUT_PROPERTY( Content );

		INIT_EVENT( OnKeyDown );
		INIT_EVENT( OnKeyUp );
		INIT_EVENT( OnFocus );
		INIT_EVENT( OnBlur );
	}

	void Control::UpdateVisual(LayoutEngine* engine) const {
		engine->ClearVisual(_visual);

		_visual.Type = EVisualType::Control;
		
		Visuals::Control& c = _visual.Control;

		c.Opacity = Opacity;
		c.OpacityMask = 0;

		c.ChildCount = Content.getSize();
		c.Children = new const Visual*[c.ChildCount];
		for(int i = 0; i < Content.getSize(); ++i) {
			Content[i]->UpdateVisual(engine);
			c.Children[i] = Content[i]->getVisual();
		}

		c.BackgroundBrush = 0;
		c.ForegroundBrush = 0;
		c.BorderBrush = 0;

		c.FontFamily = 0;
		c.FontSize = 0;

		c.MinWidth = 0;
		c.MaxWidth = 0;
		c.Width = 0;

		c.MinHeight = 0;
		c.MaxHeight = 0;
		c.Height = 0;

		c.Margin.Top = 0;
		c.Margin.Right = 0;
		c.Margin.Bottom = 0;
		c.Margin.Left = 0;

		c.Padding.Top = 0;
		c.Padding.Right = 0;
		c.Padding.Bottom = 0;
		c.Padding.Left = 0;

		c.BorderThickness.Top = 0;
		c.BorderThickness.Right = 0;
		c.BorderThickness.Bottom = 0;
		c.BorderThickness.Left = 0;

		c.CornerRadius.TopLeft = 0;
		c.CornerRadius.TopRight = 0;
		c.CornerRadius.BottomLeft = 0;
		c.CornerRadius.BottomRight = 0;
	}
}