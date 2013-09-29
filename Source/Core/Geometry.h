#pragma once

#include "Object.h"
#include "Properties.h"

namespace Ir {
	class Geometry
		: public Object
		, public DependencyObject {
	public:
		TransformProperty Transform;

	public:
		virtual bool ContainsPoint(vec2f point) const = 0;

	protected:
		Geometry(Object* parent);
	};
}