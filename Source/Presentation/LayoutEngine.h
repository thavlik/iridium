#pragma once

#include "../Common/LinkedList.h"
#include "Visual.h"

namespace Ir
{
	class Control;

	struct Visual;
		
	class LayoutEngine {
	public:
		LayoutEngine(unsigned maxVisuals = 8192);

		void ClearVisual(Visual&);

	private:
		LinkedList<Visual> _visuals;

		void ClearControl(Visuals::Control&);
		void ClearText(Visuals::Text&);
		void ClearShape(Visuals::Shape&);
		void ClearImage(Visuals::Image&);
	};
}