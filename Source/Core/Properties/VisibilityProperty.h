#pragma once

#include "Property.h"

namespace Ir {
	namespace EVisibility {
		enum Value {
			Collapsed,
			Hidden,
			Visible
		};
	}

	typedef ValueProperty<EVisibility::Value> VisibilityProperty;
}