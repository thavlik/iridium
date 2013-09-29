#pragma once

#include <vector>
#include <algorithm>
#include <string>
#include <map>

#include "../Common/StringHash.h"

#include "DependencyObject.h"
#include "EventObject.h"
#include "Event.h"

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

		virtual Object* Duplicate() const { return nullptr; }

	public:
		StringHash getName() const { return _name; }

		const Object* getParent() const { return _parent; }
		Object* getParent() { return _parent; }

		const std::vector<Object*>& getChildren() const { return _children; }

		std::vector<Object*>& getChildren() { return _children; }		

	private:
		StringHash _name;

		Object* _parent;
		std::vector<Object*> _children;
	};
}