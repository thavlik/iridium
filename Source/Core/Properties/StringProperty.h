#pragma once

#include "Property.h"

namespace Ir {
	class StringProperty : public Property {
	public:
		StringProperty(const char* str = nullptr);

		int getLength() const { return _length; }

		operator const char*() const { return _value; }

		StringProperty& operator=(const char* str) {
			setString(str);
			OnChanged(this);
			return *this;
		}

	private:
		void setString(const char*);

		int _length;

		char* _value;
	};
}