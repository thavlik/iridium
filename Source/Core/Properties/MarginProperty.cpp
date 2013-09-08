#include "MarginProperty.h"

namespace Ir {
	MarginProperty::MarginProperty() {
	}

	void MarginProperty::setValue(Metric all) {
		_top = _right = _left = _bottom = all;
		OnChanged(this);
	}

	void MarginProperty::setValue(Metric vertical, Metric horizontal) {
		_top = _bottom = vertical;
		_right = _left = horizontal;
		OnChanged(this);
	}

	void MarginProperty::setValue(Metric top, Metric right, Metric bottom, Metric left) {
		_top = top;
		_right = right;
		_bottom = bottom;
		_left = left;
		OnChanged(this);
	}
}