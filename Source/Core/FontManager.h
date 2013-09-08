#pragma once

#include <unordered_map>
#include "FontFamily.h"
#include "../Common/StringHash.h"

namespace Ir {
	class FontManager {
	public:
		typedef std::unordered_map<StringHash, FontFamily*, StringHash::Hasher> FontMap;

		FontManager();

		~FontManager();

		FontFamily const* Find(StringHash name) const;

		FontFamily* Find(StringHash name);

	private:
		FontMap _fonts;
	};
}