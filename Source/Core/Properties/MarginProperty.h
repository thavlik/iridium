#pragma once

#include "Property.h"
#include "../../Common/Metric.h"

namespace Ir {
	class MarginProperty : public Property {
	public:
		MarginProperty();

		void setValue(Metric all);

		void setValue(Metric vertical, Metric horizontal);

		void setValue(Metric top, Metric right, Metric bottom, Metric left);
		
		Metric getTop() const { return _top; }

		void setTop(Metric m) { _top = m; OnChanged(this); }

		Metric getRight() const { return _right; }

		void setRight(Metric m) { _right = m; OnChanged(this); }

		Metric getBottom() const { return _bottom; }

		void setBottom(Metric m) { _bottom = m; OnChanged(this); }

		Metric getLeft() const { return _left; }

		void setLeft(Metric m) { _left = m; OnChanged(this); }

	private:
		Metric _top, _right, _bottom, _left;
	};
}