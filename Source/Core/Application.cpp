#include "Application.h"
#include "Window.h"

namespace Ir
{
	Application::Application(bool multithread)
		: Object(nullptr)
		, _exit(false)
		, _window("Iridium", 800, 600, 400, 200)
	{
	}

	void Application::Update(double dt) {
		_window.ProcessMessages();
		_exit = _window.Escape();
	}
}