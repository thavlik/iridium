#pragma once

#include <vector>

namespace Ir
{
	template<class ArgTy>
	class Subscriber
	{
	public:
		Subscriber() : _object(nullptr), _stub(nullptr) { }

		void operator()(ArgTy a1) const { return (*_stub)(_object, a1); }

		template<class T, void (T::*TMethod)(ArgTy) >
		static Subscriber FromMethod(T* object) {
			Subscriber d;
			d._object = object;
			d._stub = &EventStub< T, TMethod >::Stub; // #1
			return d;
		}

		bool operator==(const Subscriber& a) const { return _object == a._object && _stub == a._stub; }
		bool operator!=(const Subscriber& a) const { return _object != a._object || _stub != a._stub; }

	private:
		typedef void (*stub_type)(void* object, ArgTy arg);
		void* _object;
		stub_type _stub;

		template<class T, void (T::*TMethod)(ArgTy)>
		struct EventStub {
			static void Stub(void* object, ArgTy a1) {
				T* p = static_cast< T* >(object);
				return (p->*TMethod)(a1);
			}
		};
	};

	template<class ArgTy = EventObject*>
	class Event
	{
	public:
		void operator()(ArgTy arg)
		{
			for(unsigned i = 0; i < _subscribers.size(); ++i)
				_subscribers[i](arg);
		}

		void operator+=(Subscriber<ArgTy> s)
		{
			_subscribers.push_back(s);
		}

		void operator-=(Subscriber<ArgTy> s)
		{
			_subscribers.erase(std::find(_subscribers.begin(), _subscribers.end(), s));
		}

	private:
		std::vector< Subscriber<ArgTy> > _subscribers;
	};
}