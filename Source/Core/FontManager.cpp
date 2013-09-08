#include "FontManager.h"

namespace Ir {
	FontManager::FontManager() {

	}

	FontManager::~FontManager() {
		for(FontMap::iterator it = _fonts.begin(); it != _fonts.end(); ++it) {
			delete it->second;
		}
	}

	FontFamily const* FontManager::Find(StringHash name) const {
		FontMap::const_iterator it = _fonts.find(name);
		return it == _fonts.end() ? nullptr : it->second;
	}

	FontFamily* FontManager::Find(StringHash name) {
		FontMap::iterator it = _fonts.find(name);
		return it == _fonts.end() ? nullptr : it->second;
	}
}