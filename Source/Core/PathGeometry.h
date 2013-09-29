#pragma once

#include "Geometry.h"

namespace Ir {
	class PathGeometry : public Geometry {
	public:
		PathGeometry(Object* parent);

	public:

	public:
		virtual bool ContainsPoint(vec2f point) const;
	};
}