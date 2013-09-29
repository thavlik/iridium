#pragma once

#include "Control.h"

namespace Ir {
	class Shape : public Control {
	public:
		Shape(Object* parent);

	public:
		GeometryProperty RendererdGeometry;

	public:
		virtual void Draw(Renderer*) const;
	};
}