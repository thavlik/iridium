#pragma once

#include <cstring>

#include "../../Common/StringHash.h"
#include "../Event.h"
#include "../Object.h"

namespace Ir {
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
	class Property : public DependencyObject {
		friend class DependencyObject;
	public:
		virtual ~Property() { }

	public:
		Event<Property*> OnChanged;

		const char* getName() const { return _name; }

		StringHash getNameHash() const { return _nameHash; }

	protected:
		Property()
			: _name(nullptr) { }

	private:		
		const char* _name;

		StringHash _nameHash;
	};

	template<class T>
	class ValueProperty : public Property {
	public:
		ValueProperty(const T& val = T())
			: _value(val) { }

		operator const T() const { return _value; }

		operator T() { return _value; }

		ValueProperty<T>& operator=(const T& v) { _value = v; OnChanged(this); return *this; }

	protected:
		T _value;
	};
}