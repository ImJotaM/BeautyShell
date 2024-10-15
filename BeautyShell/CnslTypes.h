#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

struct Size_f {
	float Width = 0;
	float Height = 0;
};

struct Size {
	int Width = 0;
	int Height = 0;
	Size_f ToSize_f() {
		return { static_cast<float>(Width), static_cast<float>(Height) };
	}
};

typedef Vector2 Position_f;

struct Position {
	int x = 0;
	int y = 0;
	Position_f ToVector2() {
		return { static_cast<float>(x), static_cast<float>(y) };
	}
};

struct Line {
	Position Start = { 0, 0 };
	Position End = { 0 , 0 };
};

typedef Rectangle Rect_f;

struct Rect {
	int x = 0;
	int y = 0;
	int Width = 0;
	int Height = 0;
	Rect_f ToRect_f() {
		return {
			static_cast<float>(x), static_cast<float>(y),
			static_cast<float>(Width), static_cast<float>(Height)
		};
	}
};