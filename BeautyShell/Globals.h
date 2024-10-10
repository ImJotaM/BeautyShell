#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

struct FontData {

	Font font = {};
	std::string font_path = {};
};

struct ConsoleText {

	std::string Text = "";
	Vector2 Position = { 0, 0 };
	Color color = WHITE;
};

struct ConsoleData {

	int Width = 500;
	int Height = 600;
	std::string Title = "Beauty Shell";
	int FPS = 60;
	Color Background = WHITE;
};

inline const std::string FONTS_PATH = "assets/fonts/";

inline FontData Arial = { {}, FONTS_PATH + "arial.ttf" };
inline FontData CascadiaCode = { {}, FONTS_PATH + "CascadiaCode.ttf" };

inline ConsoleData MainConsole = {
	500, 600, "BeautyShell", 60, BLACK
};

inline std::vector<ConsoleText> OutputText;
inline ConsoleText InputText;

inline Vector2 ScreenGridOffset = { 8, 16 };

inline std::chrono::steady_clock::time_point currentTime;

namespace CnslFont {

	inline FontData CurrentFont = CascadiaCode;
	inline float FontSize = 16;
	inline float Spacing = 0;

}

namespace CnslTime {
	
	inline auto GetCurrentTime() {
		return std::chrono::steady_clock::now();
	}

	inline int ConvertTimeDifToMs(std::chrono::steady_clock::duration duration) {
		return static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(duration).count());
	}
}

namespace CnslCursor {
	
	inline bool ConsoleShowCursor = true;
	inline Vector2 ConsoleCursorSize = { 8, 16 };
	inline Vector2 Position = {0, 0};
	Color color = WHITE;
}