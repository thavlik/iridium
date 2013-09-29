#pragma once

#include "Properties.h"

namespace Ir {
	class Element;

	class ControlTemplate : public Object {
	public:
		ControlTemplate(Object* parent);

	public:
		Element const* getRoot() const { return _root; }

		Element* getRoot() { return _root; }

		void setRoot(Element* root) { _root = root; }

	public:
		Element* CreateInstance() const;

	private:
		Element* _root;
	};
}