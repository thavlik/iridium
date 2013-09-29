#pragma once

#include "Shape.h"

namespace Ir {
	class Path : public Shape {
	public:
		Path(Object* parent);

	public:
		GeometryProperty Data;

	public:
		virtual void RequestSize(Measure& width, Measure& height) const;
	};
}