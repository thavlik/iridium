#include "DependencyObject.h"

namespace Ir { 
	const Property* DependencyObject::FindProperty(StringHash h) const {
		PropertyMap::const_iterator it = _properties.find( h );
		return it == _properties.end() ? nullptr : it->second;
	}

	const Property* DependencyObject::FindProperty(const char* name) const {
		return FindProperty( StringHash(name) );
	}

	Property* DependencyObject::FindProperty(StringHash h) {
		PropertyMap::iterator it = _properties.find( h );
		return it == _properties.end() ? nullptr : it->second;
	}

	Property* DependencyObject::FindProperty(const char* name) {
		return FindProperty( StringHash(name) );
	}
}