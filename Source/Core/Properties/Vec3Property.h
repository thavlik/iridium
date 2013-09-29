#pragma once

#include "Property.h"
#include "../../Common/Vectors.h"

namespace Ir {
	class Vec3Property : public Property {
	public:
		FloatProperty X, Y, Z;

		Vec3Property() {
			OBJECT_PROPERTY( X );
			OBJECT_PROPERTY( Y );
			OBJECT_PROPERTY( Z );
		}
	};
}