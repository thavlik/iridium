#pragma once

namespace Ir {
	class FontFamily {
	public:
		FontFamily(const char* name);

		~FontFamily();

		bool isLoaded() const { return _loaded; }

		void CalcBounds(float& width, float& height, float fontSize);

	private:		
		void Load() const;

		struct Impl;
		Impl* _impl;

		char* _name;

		bool _loaded;
	};
}