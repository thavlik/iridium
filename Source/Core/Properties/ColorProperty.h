#pragma once

#include "Property.h"
#include "../../Common/Color.h"

namespace Ir {
	class ColorProperty : public Property {
	public:
		ColorProperty();

		ColorProperty(float r, float g, float b, float a);

		Color4 getValue() const { return Color4(_r, _g, _b, _a); }

		void setValue(float r, float g, float b, float a) {
			_r = r;
			_g = g;
			_b = b;
			_a = a;
			OnChanged(this);
		}

	private:
		float _r, _g, _b, _a;
	};
}