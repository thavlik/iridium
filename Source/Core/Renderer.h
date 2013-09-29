#pragma once

#include "../Common/WindowHelper.h"

namespace Ir {
	class Brush;

	namespace ELineCap {
		typedef int Enum;
		enum {
			Butt,
			Round,
			Square
		};
	}

	namespace ELineJoin {
		typedef int Enum;
		enum {
			Miter,
			Round,
			Bevel
		};
	}

	namespace EFillRule {
		typedef int Enum;
		enum {
			Winding,
			EvenOdd
		};
	}

	namespace EOperation {
		typedef int Enum;
		enum {
			Clear,
			Source,
			Over,
			In,
			Out,
			Atop,
			Dest,
			DestOver,
			DestIn,
			DestOut,
			DestAtop,
			Xor,
			Add,
			Saturate,
			Multiply,
			Screen,
			Overlay,
			Darken,
			Lighten,
			ColorDodge,
			ColorBurn,
			HardLight,
			SoftLight,
			Difference,
			Exclusion,
			HSLHue,
			HSLSaturation,
			HSLColor,
			HSLLuminosity
		};
	}

	class Renderer {
	public:
		virtual ~Renderer() { }

	public:
		virtual void SetBrush(const Brush*) = 0;
		virtual void SetStrokeRadius(float) = 0;
		virtual void SetLineCap(ELineCap::Enum) = 0;
		virtual void SetLineJoin(ELineJoin::Enum) = 0;
		virtual void SetFillRule(EFillRule::Enum) = 0;
		virtual void SetOperation(EOperation::Enum) = 0;
		virtual void SetTransform(float sx, float sy, float tx, float ty, float rot) = 0;
		virtual void Rectangle(float x, float y, float w, float h) = 0;		
		virtual void Ellipse(float x, float y, float rx, float ry) = 0;
		virtual void PathMoveTo(float x, float y) = 0;
		virtual void PathLineTo(float x, float y) = 0;
		virtual void PathArcTo(float x0, float y0, float x1, float y1) = 0;
		virtual void PathCurveTo(float x0, float y0, float x1, float y1, float x2, float y2) = 0;
		virtual void PathClose() = 0;		
		virtual void Fill() = 0;
		virtual void Stroke() = 0;

	protected:
		Renderer() { }
	};
}