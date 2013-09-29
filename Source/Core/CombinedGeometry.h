#pragma once

#include "Geometry.h"

namespace Ir {
	class CombinedGeometry : public Geometry {
	public:
		CombinedGeometry(Object* parent);

	public:
		GeometryProperty ShapeA, ShapeB;

		CombineModeProperty Mode;

	public:
		enum Mode {
			SUBSTRACT,
			INTERSECT,
			UNION,
			XOR
		};

	public:
		virtual bool ContainsPoint(vec2f point) const;
	};
}