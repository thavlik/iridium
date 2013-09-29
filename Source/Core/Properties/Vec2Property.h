#pragma once

#include "Property.h"
#include "../../Common/Vectors.h"

namespace Ir {
	class Vec2Property : public Property {
	public:
		FloatProperty X, Y;

		Vec2Property() {
			OBJECT_PROPERTY( X );
			OBJECT_PROPERTY( Y );
		}

		operator vec2f() const { return vec2f((float)X, (float)Y); }
	};
}