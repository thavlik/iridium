#pragma once

#include "../Property.h"

namespace Ir
{
	class Effect;
	class EffectsProperty : public Property {
	public:
		EffectsProperty(StringHash name)
			: Property(name) { }

	private:
		std::vector<Effect*> _effects;
	};
}