#include "ContentProperty.h"

namespace Ir {
	ContentProperty::ContentProperty() {

	}

	void ContentProperty::Add(Control* control) {
		for(unsigned i = 0; i < _children.size(); ++i) {
			if(_children[i] == control) {
				return;
			}
		}
		_children.push_back(control);
		OnChanged(this);
	}

	void ContentProperty::Remove(Control* control) {
		int found = -1;
		for(unsigned i = 0; i < _children.size(); ++i) {
			if(_children[i] == control) {
				found = (int)i;
				break;
			}
		}
		if(found != -1) {
			_children.erase(_children.begin() + found);
			OnChanged(this);
		}
	}

	void ContentProperty::Clear() {
		if(_children.size() > 0) {
			_children.clear();
			OnChanged(this);
		}
	}
}