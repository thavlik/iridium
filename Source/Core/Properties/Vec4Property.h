#pragma once

#include "Property.h"
#include "../../Common/Vectors.h"

namespace Ir {
	class Vec4Property : public Property {
	public:
		FloatProperty X, Y, Z, W;

		Vec4Property() {
			OBJECT_PROPERTY( X );
			OBJECT_PROPERTY( Y );
			OBJECT_PROPERTY( Z );
			OBJECT_PROPERTY( W );
		}
	};
}