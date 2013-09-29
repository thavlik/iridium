#pragma once

#include "Shape.h"

namespace Ir {
	class Rectangle : public Shape {
	public:
		Rectangle(Object* parent);
		
	public:
		FloatProperty Width, Height;

	public:
		virtual void RequestSize(Measure& width, Measure& height) const;
	};
}