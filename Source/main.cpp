#include "Core/Application.h"
#include "Core/Window.h"
#include "Common/Timer.h"
#include "Common/WindowHelper.h"
#include "Core/CairoRenderer.h"
#include "Core/Brush.h"

int main(int ac, char** av) {
	using namespace Ir;

	Application app(false);
	
	Window* win = new Window(&app, "Test!", 0, 0, 800, 600);

	CairoRenderer cairo(&app.getWindow());

	SolidColorBrush brush(nullptr);
	brush.Color = Color4(1.0, 1.0, 0.0, 1.0);
	cairo.SetBrush(&brush);
	cairo.Rectangle(0, 0, 700, 500);
	cairo.Fill();

	double t0 = 0.0, t1 = 0.0, dt = 0.0;

	Timer timer;

	while(!app.getExit()) {
		t0 = timer.Stop();

		app.Update(dt);

		Sleep(0);

		t1 = timer.Stop();

		dt = t1 - t0;
	}

	return 0;
}