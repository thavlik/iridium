#pragma once

#include "../Common/Color.h"
#include "Object.h"
#include "Property.h"

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
	class GradientStop : public Object
	{
	public:
		FloatProperty Offset;
		ColorProperty Color;

	public:
		GradientStop()
			: Object(nullptr)
		{
			INIT_PROPERTY( Offset );
			INIT_PROPERTY( Color );
		}
	};

	//////////////////////////////////////////////////////////////////////////
	///
	/// Brush
	///
	/// Base class for all brush objects. 
	///
	//////////////////////////////////////////////////////////////////////////
	class Brush : public Object {
	public:
		FloatProperty Opacity;

	protected:
		Brush(Object* parent)
			: Object(parent)
		{
			INIT_PROPERTY( Opacity );
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
			: Brush(parent)
		{
			INIT_PROPERTY( Color );
		}
	};

	//////////////////////////////////////////////////////////////////////////
	///
	/// LinearGradientBrush
	///
	//////////////////////////////////////////////////////////////////////////
	class LinearGradientBrush : public Brush {
	public:
		ArrayProperty<GradientStop> Stops;
		Float2Property EndPoint, StartPoint;

	public:
		LinearGradientBrush(Object* parent)
			: Brush(parent)
		{
			INIT_PROPERTY( Stops );
			INIT_PROPERTY( EndPoint );
			INIT_PROPERTY( StartPoint );
		}
	};

	//////////////////////////////////////////////////////////////////////////
	///
	/// RadialGradientBrush
	///
	//////////////////////////////////////////////////////////////////////////
	class RadialGradientBrush : public Brush {
	public:
		ArrayProperty<GradientStop> Stops;
		Float2Property Center, Radius;

	public:
		RadialGradientBrush(Object* parent)
			: Brush(parent)
		{
			INIT_PROPERTY( Stops );
			INIT_PROPERTY( Center );
			INIT_PROPERTY( Radius );
		}
	};
}