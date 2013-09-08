#pragma once

#include "Property.h"

namespace Ir {
	class ContentProperty : public Property {
	public:
		ContentProperty();

		void Add(Control*);

		void Remove(Control*);

		void Clear();

		int getSize() const { return _children.size(); }

		const Control* operator[](int i) const { return _children[i]; }

		Control* operator[](int i) { return _children[i]; }

	private:
		std::vector<Control*> _children;
	};
}