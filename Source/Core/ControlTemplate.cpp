#include "ControlTemplate.h"
#include "Element.h"

namespace Ir {
	ControlTemplate::ControlTemplate(Object* parent)
		: Object(parent) {
	}

	Element* ControlTemplate::CreateInstance() const {
		Object* obj = _root->Duplicate();
		if(!obj) {
			return nullptr;
		} else {
			if(Element* el = dynamic_cast<Element*>(obj)) {
				return el;
			} else {
				delete obj;
				return nullptr;
			}
		}
	}
}