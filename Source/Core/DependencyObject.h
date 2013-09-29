#pragma once

#include <vector>
#include <algorithm>
#include <string>
#include <map>

#include "../Common/StringHash.h"

#define __IPROPERTY_STRING(name) #name

/** */
#define OBJECT_PROPERTY(name) \
	this->InitProperty( &##name##, __IPROPERTY_STRING(name) )

/** */
#define INIT_EVENT(name) \
	this->RegisterEvent( &##name##, __IPROPERTY_STRING(name) )

namespace Ir {
	class Property;

	class DependencyObject {
	public:
		const Property* FindProperty(StringHash name) const;

		Property* FindProperty(StringHash name);

		const Property* FindProperty(const char* name) const;

		Property* FindProperty(const char* name);		

	protected:
		/** */
		template<class T>
		T& InitProperty(T* prop, const char* name) {
			const StringHash h(name);

			PropertyMap::iterator it = _properties.find(h);
			if(it != _properties.end()) {
				// Maybe a warning?
				printf("Warning: duplicate property '%s'\n", name);
			}

			_properties[h] = prop;

			//prop->_parent = this;
			prop->_name = name;
			prop->_nameHash = h;

			return *prop;
		}

	private:
		typedef std::map<StringHash, Property*> PropertyMap;
		PropertyMap _properties;		
	};
}