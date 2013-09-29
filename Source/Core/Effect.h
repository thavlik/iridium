#pragma once

#include "Object.h"

namespace Ir {
	class Effect : public Object {
	public:
		Effect(Object* parent)
			: Object(parent) { }

	private:
	};
}