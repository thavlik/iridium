#include "FontFamily.h"
#include <string.h>

namespace Ir {
	struct FontFamily::Impl {
	};

	FontFamily::FontFamily(const char* name)
		: _impl(new Impl())
		, _name(nullptr) {
		const size_t len = strlen(name) + 1;
		_name = new char[len];
		memcpy(_name, name, len);
	}

	FontFamily::~FontFamily() {
		delete _impl;
		_impl = nullptr;

		delete[] _name;
		_name = nullptr;		
	}

	void FontFamily::CalcBounds(float& width, float& height, float fontSize) {
	}
}