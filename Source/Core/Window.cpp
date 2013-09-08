#include "Window.h"
#include <string.h>

namespace Ir
{
	Window::Window(Object* parent, const char* title, int x, int y, int width, int height)
		: Control(parent)
	{
		INIT_PROPERTY( Title ) = title;
		INIT_PROPERTY( X ) = x;
		INIT_PROPERTY( Y ) = y;
	}
}
