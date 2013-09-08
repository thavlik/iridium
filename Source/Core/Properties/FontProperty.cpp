#include "FontProperty.h"

namespace Ir {
	FontProperty::FontProperty()
		: _fontFamily(nullptr) {
			(*this) = "Times New Roman";
	}

	FontProperty::~FontProperty() {
		delete[] _fontFamily;
		_fontFamily = nullptr;
	}

	FontProperty& FontProperty::operator=(const char* str) {
		delete[] _fontFamily;

		if(str) {
			size_t len = strlen(str) + 1;
			_fontFamily = new char[len];
			memcpy(_fontFamily, str, len);
		} else {
			_fontFamily = nullptr;
		}

		LoadFont();

		return *this;
	}

	void FontProperty::LoadFont() {
	}
}