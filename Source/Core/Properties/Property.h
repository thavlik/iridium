#pragma once

#include <cstring>

#include "../../Common/StringHash.h"
#include "../Event.h"
#include "../Object.h"

namespace Ir
{
	class Object;
	class Control;
	class Brush;

	//////////////////////////////////////////////////////////////////////////
	///
	/// Property
	///
	/// Base class for all object properties. Properties are objects themselves
	/// with (always) a null parent. Properties are to be instanced on the stack.
	///
	//////////////////////////////////////////////////////////////////////////
	class Property {
		friend class Object;
	public:
		virtual ~Property() { }

	public:
		Event<Property*> OnChanged;

		Object const* getParent() const { return _parent; }
		Object* getParent() { return _parent; }

		const char* getName() const { return _name; }

		StringHash getNameHash() const { return _nameHash; }

	protected:
		Property()
			: _parent(nullptr)
			, _name(nullptr) { }

	private:
		Object* _parent;
		
		const char* _name;

		StringHash _nameHash;
	};

	template<class T>
	class ValueProperty : public Property {
	public:
		ValueProperty(const T& val = T())
			: _value(val) { }

		operator T() const { return _value; }

		ValueProperty<T>& operator=(const T& v) { _value = v; OnChanged(this); return *this; }

	protected:
		T _value;
	};
}