#pragma once

#include "Object.h"
#include "Target.h"

namespace Ir
{
	class Setter : public Object {
	public:
		Setter(Object* parent);

		const Target& getTarget() const { return _target; }

		StringHash getProperty() const { return _property; }

		const Object* getValue() const { return _value; }

	private:
		Target _target;

		StringHash _property;

		Object* _value;
	};
}