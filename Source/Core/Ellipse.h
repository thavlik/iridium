#pragma once

#include "Shape.h"

namespace Ir {
	class Ellipse : public Shape {
	public:
		Ellipse(Object* parent);

	public:
		FloatProperty RadiusX, RadiusY;

	public:
		virtual void RequestSize(Measure& width, Measure& height) const;
	};
}