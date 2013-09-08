#pragma once

#include <algorithm>
#include <string>
#include <map>

#include "../../Common/StringHash.h"

namespace Ir
{
	class DependencyObject {
	public:

	private:
		typedef std::map<StringHash, DependencyProperty*> PropertyMap;
		PropertyMap _properties;
	};
}