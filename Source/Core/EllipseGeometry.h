#pragma once

#include "Geometry.h"

namespace Ir {
	class EllipseGeometry : public Geometry {
	public:
		EllipseGeometry(Object* parent);

	public:
		Vec2Property Center;

		FloatProperty RadiusX, RadiusY;

	public:
		virtual bool ContainsPoint(vec2f point) const;
	};
}