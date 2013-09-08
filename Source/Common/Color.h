#pragma once

namespace Ir
{
	class Color4
	{
	public:
		static Color4 FromString(const char*)
		{
			return Color4();
		}

		Color4()
			: r(1.0f)
			, g(1.0f)
			, b(1.0f)
			, a(1.0f) { }

		Color4(float R, float G, float B, float A)
			: r(R)
			, g(G)
			, b(B)
			, a(A) { }

		float r, g, b, a;
	};
}