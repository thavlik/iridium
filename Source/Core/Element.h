#pragma once

#include "Properties.h"
#include "Measure.h"

/** macro for initializing control properties */
#define CONTROL_PROPERTY( flags, name ) do { \
	OBJECT_PROPERTY( name ); \
	if((flags & AFFECTS_LAYOUT) != 0) { \
		_AddLayoutInvalidator( &##name ); \
	} else if((flags & AFFECTS_RENDERING) != 0) { \
		_AddPixelInvalidator( &##name ); \
	} \
} while(false); \
	(name)

namespace Ir {
	class Renderer;

	namespace EVisualStatus {
		enum Type {
			Valid			= 0,
			InvalidPixels	= (1<<0),
			InvalidLayout	= (1<<1) | InvalidPixels
		};
	}

	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	class Element
		: public Object
		, public DependencyObject {
	public:
		FloatProperty ActualWidth, ActualHeight, ActualX, ActualY;

	public:
		Event<>
			OnMouseEnter,
			OnMouseLeave,
			OnMouseOver,
			OnMouseDown,
			OnMouseUp,
			OnMouseDrag,
			OnClick;

		virtual void Draw(Renderer*) const { }

		virtual void RequestSize(Measure& width, Measure& height) const = 0;

	protected:
		Element(Object* parent);

	protected:
		enum {
			AFFECTS_NOTHING		= (0),
			AFFECTS_LAYOUT		= (1<<0),
			AFFECTS_RENDERING	= (1<<1)
		};

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

	protected:
		void _AddPixelInvalidator(Property* p) {
			//p->OnChanged += Subscriber<Property*>::FromMethod<Control, &Control::_InvalidatePixels>(this);
		}
		void _AddLayoutInvalidator(Property* p) {
			//p->OnChanged += Subscriber<Property*>::FromMethod<Control, &Control::_InvalidateLayout>(this);
		}

		void _ValidateVisual() { _visualStatus = EVisualStatus::Valid; }
		void _InvalidateLayout(Property*) { _visualStatus |= EVisualStatus::InvalidLayout; }
		void _InvalidatePixels(Property*) { _visualStatus |= EVisualStatus::InvalidPixels; }	

	private:
		int _visualStatus;

		typedef std::map<StringHash, Event<EventObject*>* > EventMap;

		EventMap _events;
	};
}