#include "Control.h"

namespace Ir {
	Control::Control(Object* parent)
		: Element(parent) {
		CONTROL_PROPERTY( AFFECTS_NOTHING, Name );
		
		CONTROL_PROPERTY( AFFECTS_RENDERING, FillBrush );
		CONTROL_PROPERTY( AFFECTS_RENDERING, BorderBrush );
		CONTROL_PROPERTY( AFFECTS_RENDERING, Opacity );

		CONTROL_PROPERTY( AFFECTS_LAYOUT, Style );
		CONTROL_PROPERTY( AFFECTS_LAYOUT, Padding );
		CONTROL_PROPERTY( AFFECTS_LAYOUT, Margin );		
		CONTROL_PROPERTY( AFFECTS_LAYOUT, BorderThickness );
		CONTROL_PROPERTY( AFFECTS_LAYOUT, MinWidth );
		CONTROL_PROPERTY( AFFECTS_LAYOUT, MinHeight );
		CONTROL_PROPERTY( AFFECTS_LAYOUT, MaxWidth );
		CONTROL_PROPERTY( AFFECTS_LAYOUT, MaxHeight );
		CONTROL_PROPERTY( AFFECTS_LAYOUT, Content );

		INIT_EVENT( OnKeyDown );
		INIT_EVENT( OnKeyUp );
		INIT_EVENT( OnFocus );
		INIT_EVENT( OnBlur );
	}

	void Control::RequestSize(Measure& width, Measure& height) const {
		const Metric w = Width;

		const Metric h = Height;

		if(w.getType() == Metric::UNITS) {
			width = Measure(Measure::FIXED, w.getAmount());
		} else if(w.getType() == Metric::PERCENT) {
			width = Measure(Measure::PERCENT, w.getAmount());
		} else {

		}

		if(h.getType() == Metric::UNITS) {
			height = Measure(Measure::FIXED, h.getAmount());
		} else if(h.getType() == Metric::PERCENT) {
			height = Measure(Measure::PERCENT, h.getAmount());
		} else {
		}

		for(unsigned i = 0; i < getChildren().size(); ++i) {
			if(const Element* child = dynamic_cast<const Element*>(getChildren()[i])) {
				Measure cw, ch;
				child->RequestSize(cw, ch);
			}
		}
	}
}