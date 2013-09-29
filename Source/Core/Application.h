#pragma once

#include "Object.h"

#include "../Common/WindowHelper.h"

#include "../Presentation/LayoutEngine.h"

namespace Ir
{
	//////////////////////////////////////////////////////////////////////////
	///
	/// Application
	///
	/// Wrapper class for all functionalities related to running a program.
	///
	///
	//////////////////////////////////////////////////////////////////////////
	class Application : public Object {
	public:
		Application(bool multithread);

		void Update(double dt);

	public:
		bool getExit() const { return _exit; }

		WindowHelper& getWindow() { return _window; }

	private:
		bool _exit;

		WindowHelper _window;

		LayoutEngine _layout;
	};
}