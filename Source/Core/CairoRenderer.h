#pragma once

#include "Renderer.h"

namespace Ir {
	class CairoRenderer : public Renderer {
	public:
		CairoRenderer(WindowHelper*);
		
		~CairoRenderer();

	public:
		virtual void SetBrush(const Brush*);
		virtual void SetStrokeRadius(float);
		virtual void SetLineCap(ELineCap::Enum);
		virtual void SetLineJoin(ELineJoin::Enum);
		virtual void SetFillRule(EFillRule::Enum);
		virtual void SetOperation(EOperation::Enum);
		virtual void SetTransform(float sx, float sy, float tx, float ty, float rot);
		virtual void Rectangle(float x, float y, float w, float h);		
		virtual void Ellipse(float x, float y, float rx, float ry);
		virtual void PathMoveTo(float x, float y);
		virtual void PathLineTo(float x, float y);
		virtual void PathArcTo(float x0, float y0, float x1, float y1);
		virtual void PathCurveTo(float x0, float y0, float x1, float y1, float x2, float y2);
		virtual void PathClose();		
		virtual void Fill();
		virtual void Stroke();

	private:
		struct Impl;
		Impl* _impl;
	};
}