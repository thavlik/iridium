#pragma once

#include "Geometry.h"

namespace Ir {
	class RectangleGeometry : public Geometry {
	public:
		RectangleGeometry(Object* parent);

	public:
		FloatProperty Top, Right, Bottom, Left;

	public:
		virtual bool ContainsPoint(vec2f point) const;
	};
}