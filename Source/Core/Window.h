#pragma once

#include "Control.h"

namespace Ir {
	class Window : public Control {
		friend class Application;
	public:
		Window(Object* parent, const char* title, int x, int y, int width, int height);

	public:
		StringProperty Title;
		IntProperty X, Y;
	};
}