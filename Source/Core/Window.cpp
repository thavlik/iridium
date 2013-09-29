#include "Window.h"
#include <string.h>

namespace Ir
{
	Window::Window(Object* parent, const char* title, int x, int y, int width, int height)
		: Control(parent)
	{
		CONTROL_PROPERTY( AFFECTS_RENDERING, Title ) = title;
		CONTROL_PROPERTY( AFFECTS_RENDERING, X ) = x;
		CONTROL_PROPERTY( AFFECTS_RENDERING, Y ) = y;
	}
}
