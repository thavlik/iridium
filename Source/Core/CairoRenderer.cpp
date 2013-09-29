#include "CairoRenderer.h"
#include "Brush.h"
#include <windows.h>
#include <cairo.h>
#include <cairo-win32.h>

namespace Ir {
	struct CairoRenderer::Impl {
		cairo_surface_t* surface;
		cairo_t* cr;
	};

	CairoRenderer::CairoRenderer(WindowHelper* win)
		: _impl(new CairoRenderer::Impl()) {
		HDC hdc = GetDC(win->Handle());


		//_impl->surface = cairo_win32_printing_surface_create(GetDC(win->Handle()));
		_impl->surface = cairo_win32_surface_create_with_ddb(hdc, CAIRO_FORMAT_ARGB32, win->Width(), win->Height());
		ReleaseDC(win->Handle(), hdc);
		
		_impl->cr = cairo_create(_impl->surface);
	}

	CairoRenderer::~CairoRenderer() {
		delete _impl;
		_impl = nullptr;
	}

	void CairoRenderer::SetBrush(const Brush* brush) {
		if(const SolidColorBrush* solid = dynamic_cast<const SolidColorBrush*>(brush)) {
			const Color4 col = solid->Color;
			cairo_set_source_rgba(_impl->cr, col.r, col.g, col.b, col.a);
		} else if(const LinearGradientBrush* linear = dynamic_cast<const LinearGradientBrush*>(brush)) {
			//const vec2f start = linear->StartPoint;
			//const vec2f end = linear->EndPoint;
			//cairo_pattern_t* pattern = cairo_pattern_create_linear(start.x, start.y, end.x, end.y);
			//cairo_pattern_add_color_stop_rgba(pattern, );
			//cairo_set_source(_impl->cr, pattern);
		} else if(const RadialGradientBrush* radial = dynamic_cast<const RadialGradientBrush*>(brush)) {
		}
	}

	void CairoRenderer::SetStrokeRadius(float s) {
		cairo_set_line_width(_impl->cr, s * 0.5f);
	}

	void CairoRenderer::SetLineCap(ELineCap::Enum v) {
		cairo_set_line_cap(_impl->cr, (cairo_line_cap_t)v);
	}

	void CairoRenderer::SetLineJoin(ELineJoin::Enum v) {
		cairo_set_line_join(_impl->cr, (cairo_line_join_t)v);
	}

	void CairoRenderer::SetFillRule(EFillRule::Enum v) {
		cairo_set_fill_rule(_impl->cr, (cairo_fill_rule_t)v);
	}

	void CairoRenderer::SetOperation(EOperation::Enum v) {
		cairo_set_operator(_impl->cr, (cairo_operator_t)v);
	}

	void CairoRenderer::SetTransform(float sx, float sy, float tx, float ty, float rot) {
		cairo_scale(_impl->cr, sx, sy);
		cairo_translate(_impl->cr, tx, ty);
		cairo_rotate(_impl->cr, rot);
	}

	void CairoRenderer::Rectangle(float x, float y, float w, float h) {
		cairo_rectangle(_impl->cr, x, y, w, h);
	}
		
	void CairoRenderer::Ellipse(float x, float y, float rx, float ry) {
		//cairo_save(_impl->cr);
		cairo_arc(_impl->cr, x, y, 1.0, 0.0, 2.0 * 3.1459);
		cairo_scale(_impl->cr, rx, ry);
		//cairo_restore(_impl->cr);
	}

	void CairoRenderer::PathMoveTo(float x, float y) {
		cairo_move_to(_impl->cr, x, y);
	}

	void CairoRenderer::PathLineTo(float x, float y) {
		cairo_line_to(_impl->cr, x, y);
	}

	void CairoRenderer::PathArcTo(float x0, float y0, float x1, float y1) {
	}

	void CairoRenderer::PathCurveTo(float x0, float y0, float x1, float y1, float x2, float y2) {
		cairo_curve_to(_impl->cr, x0, y0, x1, y1, x2, y2);
	}

	void CairoRenderer::PathClose() {
		cairo_close_path(_impl->cr);
	}
		
	void CairoRenderer::Fill() {
		cairo_fill(_impl->cr);
		cairo_surface_flush(_impl->surface);
	}

	void CairoRenderer::Stroke() {
		cairo_stroke(_impl->cr);
	}
}