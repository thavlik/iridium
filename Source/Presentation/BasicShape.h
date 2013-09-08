#pragma once

namespace Ir {
	namespace BasicShapes {
		struct Rect {
			struct {
				float TopLeft, TopRight, BottomLeft, BottomRight;
			} CornerRadius;
		};
	}

	struct BasicShape {
		int Type; 

		float Mins[2], Maxs[2];

		union {
			BasicShapes::Rect Rectangle;
		};
	};
}