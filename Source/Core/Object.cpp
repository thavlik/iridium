#include "Object.h"

namespace Ir
{
	Object::Object(Object* parent)
		: _parent(parent) {
		if(parent)
			_parent->_children.push_back(this);
	}

	Object::~Object() {
		for(unsigned i = 0; i < _children.size(); ++i)
			delete _children[i];

		if(_parent)
			_parent->_children.erase( std::find( _parent->_children.begin(), _parent->_children.end(), this ) );
	}
}