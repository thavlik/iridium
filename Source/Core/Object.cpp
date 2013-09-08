#include "Object.h"

namespace Ir
{
	Object::Object(Object* parent)
		: _parent(parent)
	{
		if(parent)
			_parent->_children.push_back(this);
	}

	Object::~Object()
	{
		for(unsigned i = 0; i < _children.size(); ++i)
			delete _children[i];

		if(_parent)
			_parent->_children.erase( std::find( _parent->_children.begin(), _parent->_children.end(), this ) );
	}

	const Property* Object::FindProperty(StringHash h) const {
		PropertyMap::const_iterator it = _properties.find( h );
		return it == _properties.end() ? nullptr : it->second;
	}
	const Property* Object::FindProperty(const char* name) const {
		return FindProperty( StringHash(name) );
	}
	Property* Object::FindProperty(StringHash h) {
		PropertyMap::iterator it = _properties.find( h );
		return it == _properties.end() ? nullptr : it->second;
	}
	Property* Object::FindProperty(const char* name) {
		return FindProperty( StringHash(name) );
	}
}