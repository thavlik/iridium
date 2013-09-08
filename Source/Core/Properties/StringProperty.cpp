#include "StringProperty.h"

namespace Ir {
	StringProperty::StringProperty(const char* str)
		: _length(0)
		, _value(nullptr) {
		setString(str);
	}

	void StringProperty::setString(const char* v) {
		delete[] _value;
		if(v) {
			_length = strlen(v);
			_value = new char[_length + 1]; 
			memcpy(_value, v, _length + 1);
		} else {
			_length = 0;
			_value = nullptr;
		}
	}
}