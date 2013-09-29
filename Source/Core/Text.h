#pragma once

#include "Element.h"

namespace Ir {
	class Text : public Element {
	public:
		Text(Object* parent);

	public:		
		StringProperty Content;

	public:
		void RequestSize(Measure& width, Measure& height) const;
	};
}