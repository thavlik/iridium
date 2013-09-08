#pragma once

#include "Properties.h"
#include "../Presentation/LayoutEngine.h"

/** */
#define INIT_VISUAL_PROPERTY(name) do { \
	INIT_PROPERTY(name); \
	_AddPixelInvalidator(&##name##); \
} while(false)

/** */
#define INIT_LAYOUT_PROPERTY(name) do { \
	INIT_PROPERTY(name); \
	_AddLayoutInvalidator(&##name##); \
} while(false)

namespace Ir {
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
	class Element : public Object {
	public:
		Element(Object* parent);

		Event<>
			OnMouseEnter,
			OnMouseLeave,
			OnMouseOver,
			OnMouseDown,
			OnMouseUp,
			OnMouseDrag,
			OnClick;

	public:
		virtual void UpdateVisual(LayoutEngine* engine) const = 0;

		virtual const Visual* getVisual() const { return &_visual; }

	protected:
		int _visualStatus;

		mutable Visual _visual;

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
	};
}