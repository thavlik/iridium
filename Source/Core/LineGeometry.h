#pragma once

#include "Geometry.h"

namespace Ir {
	class LineGeometry : public Geometry {
	public:
		LineGeometry(Object* parent);

	public:
		Vec2Property Start, End;

	public:
		virtual bool ContainsPoint(vec2f point) const;
	};
}