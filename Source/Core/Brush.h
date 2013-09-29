#pragma once

#include "../Common/Color.h"
#include "DependencyObject.h"
#include "Properties.h"

namespace Ir
{
	//////////////////////////////////////////////////////////////////////////
	///
	/// GradientStop
	///
	/// This is an object that represents stops on a gradient. It is to be
	/// instanced by-value.
	///
	//////////////////////////////////////////////////////////////////////////
	class GradientStop : public DependencyObject
	{
	public:
		FloatProperty Offset;
		ColorProperty Color;

	public:
		GradientStop() {
			OBJECT_PROPERTY( Offset );
			OBJECT_PROPERTY( Color );
		}
	};

	//////////////////////////////////////////////////////////////////////////
	///
	/// Brush
	///
	/// Base class for all brush objects. 
	///
	//////////////////////////////////////////////////////////////////////////
	class Brush
		: public Object
		, public DependencyObject {
	public:
		FloatProperty Opacity;

	protected:
		Brush(Object* parent)
			: Object(parent) {
			OBJECT_PROPERTY( Opacity );
		}
	};

	//////////////////////////////////////////////////////////////////////////
	///
	/// SolidColorBrush
	///
	//////////////////////////////////////////////////////////////////////////
	class SolidColorBrush : public Brush {
	public:
		ColorProperty Color;

	public:
		SolidColorBrush(Object* parent)
			: Brush(parent) {
			OBJECT_PROPERTY( Color );
		}
	};

	//////////////////////////////////////////////////////////////////////////
	///
	/// LinearGradientBrush
	///
	//////////////////////////////////////////////////////////////////////////
	class LinearGradientBrush : public Brush {
	public:
		//ArrayProperty<GradientStop> Stops;
		Vec2Property EndPoint, StartPoint;

	public:
		LinearGradientBrush(Object* parent)
			: Brush(parent) {
			//OBJECT_PROPERTY( Stops );
			OBJECT_PROPERTY( EndPoint );
			OBJECT_PROPERTY( StartPoint );
		}
	};

	//////////////////////////////////////////////////////////////////////////
	///
	/// RadialGradientBrush
	///
	//////////////////////////////////////////////////////////////////////////
	class RadialGradientBrush : public Brush {
	public:
		//ArrayProperty<GradientStop> Stops;
		Vec2Property Center, Radius;

	public:
		RadialGradientBrush(Object* parent)
			: Brush(parent) {
			//OBJECT_PROPERTY( Stops );
			OBJECT_PROPERTY( Center );
			OBJECT_PROPERTY( Radius );
		}
	};
}