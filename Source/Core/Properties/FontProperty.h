#pragma once

#include "Property.h"

namespace Ir {
	class FontProperty : public Property {
	public:
		FontProperty();

		~FontProperty();

		FontProperty& operator=(const char*);

	private:
		void LoadFont();

		char* _fontFamily;
	};
}