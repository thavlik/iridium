#pragma once

#include "FloatProperty.h"
#include "../../Common/Color.h"

namespace Ir {
	class ColorProperty : public Property {
	public:
		ColorProperty() {
			OBJECT_PROPERTY(R);
			OBJECT_PROPERTY(G);
			OBJECT_PROPERTY(B);
			OBJECT_PROPERTY(A);
		}

	public:
		FloatProperty R, G, B, A;

		operator Color4() const { return Color4(R, G, B, A); }

		void operator=(const Color4& c) {
			R = c.r;
			G = c.g;
			B = c.b;
			A = c.a;
		}

	private:
	};
}