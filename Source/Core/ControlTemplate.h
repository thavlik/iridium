#pragma once

#include "Properties.h"

namespace Ir
{
	class ControlTemplate : public Object {
	public:
		ContentProperty Content;

	public:
		ControlTemplate(Object* parent)
			: Object(parent) {
			INIT_PROPERTY( Content );
		}
	};
}