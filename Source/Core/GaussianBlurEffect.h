#pragma once

#include "Effect.h"
#include "Properties.h"

namespace Ir
{
	class GaussianBlurEffect : public Effect {
	public:
		GaussianBlurEffect(Object* parent)
			: Effect(parent)
		{
			INIT_PROPERTY( Sigma );
			INIT_PROPERTY( Radius );
		}

		FloatProperty
			Sigma,
			Radius;

	private:
	};
}