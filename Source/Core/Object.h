#pragma once

#include <vector>
#include <algorithm>
#include <string>
#include <map>

#include "../Common/StringHash.h"

#include "EventObject.h"
#include "Event.h"

#define __IPROPERTY_STRING(name) #name

/** */
#define INIT_PROPERTY(name) \
	this->InitProperty( &##name##, __IPROPERTY_STRING(name) )

/** */
#define INIT_EVENT(name) \
	this->RegisterEvent( &##name##, __IPROPERTY_STRING(name) )

namespace Ir {
	class Property;

	struct Visual;

	//////////////////////////////////////////////////////////////////////////
	///
	/// Object
	///
	/// Base class for all polymorphic entities. This class has simple hierarchal
	/// GC mechanisms built in, as well as properties and event handlers.
	///
	//////////////////////////////////////////////////////////////////////////
	class Object {
	public:
		Object(Object* parent);

		virtual ~Object();

		/** */
		const Property* FindProperty(StringHash name) const;
		Property* FindProperty(StringHash name);
		const Property* FindProperty(const char* name) const;
		Property* FindProperty(const char* name);

		/** To be overridden in Element */
		virtual const Visual* getVisual() const { return nullptr; }

	public:
		StringHash getName() const { return _name; }

		const Object* getParent() const { return _parent; }
		Object* getParent() { return _parent; }

		const std::vector<Object*>& getChildren() const { return _children; }
		std::vector<Object*>& getChildren() { return _children; }

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

			prop->_parent = this;
			prop->_name = name;
			prop->_nameHash = h;

			return *prop;
		}

		/** */
		template<class T>
		void RegisterEvent(T* e, const char* name) {
			const StringHash h(name);

			if(_events.find(h) != _events.end()) {
				// Maybe a warning?
			}

			// No need to delete existing events.
			_events[h] = e;
		}

	private:
		StringHash _name;

		Object* _parent;
		std::vector<Object*> _children;

		typedef std::map<StringHash, Event<EventObject*>* > EventMap;
		EventMap _events;

		typedef std::map<StringHash, Property*> PropertyMap;
		PropertyMap _properties;		
	};
}