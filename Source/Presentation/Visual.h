#pragma once

#include <vector>
#include "../Common/StringHash.h"
#include "../Common/Vectors.h"

namespace Ir {
	namespace EVisualType {
		enum Type {
			Control,
			Shape,
			Text,
			Image
		};
	}

	namespace EShapeType {
		enum Type {
			Ellipse,
			Line,
			Path,
			Polygon,
			Rectangle
		};
	}

	struct Visual;

	namespace Visuals {
		struct Control {
			float Opacity;

			/** A brush that can be applied as a mask */
			hash_t OpacityMask;

			/** Number of children */
			int ChildCount;

			/** The children of this control */
			Visual const** Children;

			/** Name of the fill brush */
			hash_t BackgroundBrush;

			/** Name of the foreground (text) brush */
			hash_t ForegroundBrush;

			/** Name of the border brush */
			hash_t BorderBrush;

			/** */
			hash_t FontFamily;

			/** */
			float FontSize;

			/** Width metrics */
			float MinWidth, MaxWidth, Width;

			/** Height metrics */
			float MinHeight, MaxHeight, Height;

			struct {
				float Top, Right, Bottom, Left;
			} Margin, Padding, BorderThickness;

			struct {
				float TopRight, BottomRight, BottomLeft, TopLeft;
			} CornerRadius;

			float Transform[9];
		};

		struct Shape {
			unsigned short Type;
			unsigned short StrokeStyle;
			hash_t Stroke;
			float StrokeThickness;
			hash_t Fill;
			float Transform[9];
			union
			{
				struct
				{
					float RadiusX, RadiusY;
				} Ellipse;
				struct
				{
					float x1, x2, y1, y2;
				} Line;
				struct
				{
					int CommandsOfs, CommandCount;
				} Path;
				struct
				{
					int NumSides;
				} Polygon;
				struct
				{
					float Width, Height;
					struct
					{
						float TopRight, BottomRight, BottomLeft, TopLeft;
					} CornerRadius;
				} Rectangle;
			};
		};

		struct Text {
			int length;
			char* str;
		};

		struct Image {
			/** Hash of the resource path */
			hash_t Resource;
			float Transform[9];
		};
	}

	struct Visual {
		unsigned Index, Next;

		/** See EVisualType::Type */
		int Type;

		/** */
		const Visual* Parent;

		/** Calculated during rendering */
		float ActualWidth, ActualHeight;

		union
		{
			Visuals::Control Control;

			Visuals::Text Text;

			Visuals::Shape Shape;

			Visuals::Image Image;
		};
	};
}