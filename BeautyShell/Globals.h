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

struct FontData {
	Font font = {};
	std::string font_path = {};
	float spacing = 0;
};

struct ConsoleText {
	std::string Text = "";
	Vector2 Position = { 0, 0 };
	Color color = WHITE;
};

struct ConsoleData {
	Size Size = { 800, 600 };
	std::string Title = "Beauty Shell";
	int FPS = 60;
	Color Background = WHITE;
};

inline ConsoleData MainConsole = {
	{500, 600}, "BeautyShell", 60, {12, 12, 12}
};

inline std::vector<ConsoleText> OutputText;
inline ConsoleText InputText;

inline Vector2 ScreenGridOffset = { 8, 16 };

namespace CnslMouse {

	// Checks if the cursor is over the rect
	inline bool IsMouseOver(Rectangle rect) {
		Position_f mousePosition = GetMousePosition();
		return CheckCollisionPointRec(mousePosition, rect);
	}

}

namespace CnslFont {

	inline const std::string FONTS_PATH = "assets/fonts/";

	inline FontData Arial = { {}, FONTS_PATH + "arial.ttf" };
	inline FontData CascadiaCode = { {}, FONTS_PATH + "CascadiaCode.ttf" };
	inline FontData SegoeUI = { {}, FONTS_PATH + "SegoeUI.ttf" };

	inline FontData CurrentFont = CascadiaCode;
	inline float FontSize = 16;
	inline float Spacing = 0;
}

namespace CnslTitlebar {

	// Conteiner properties
	inline Size conteinerSize = { MainConsole.Size.Width , 32 };
	inline Color conteinerColor = BLACK;

	// Draw only the Titlebar conteiner
	inline void DrawConteiner() {
		DrawRectangle(0, 0, conteinerSize.Width, conteinerSize.Height, conteinerColor);
	}

	// Title properties
	inline Font titleFont = {};
	inline float titleSize = 16;
	inline Position titlePosition = {0, conteinerSize.Height / 4 };
	inline float titleSpacing = 1;
	inline Color titleColor = WHITE;

	// Load title font
	inline void LoadTitlefont() {
		titleFont = LoadFontEx("assets/fonts/SegoeUI.ttf", 16, nullptr, 250);
	}

	// Draw only the Titlebar title
	inline void DrawTitle() {
		DrawTextEx(titleFont, "BeautyShell", titlePosition.ToVector2(), titleSize, titleSpacing, titleColor);
	}

	// Close button properties
	inline Size closebtnSize = { 45 , conteinerSize.Height };
	inline Position closebtnPosition = {conteinerSize.Width - closebtnSize.Width, 0};
	inline Rectangle closebtnRect = { 
		closebtnPosition.ToVector2().x, closebtnPosition.ToVector2().y,
		closebtnSize.ToSize_f().Width, closebtnSize.ToSize_f().Height
	};
	inline Color closebtnColor = BLACK;

	// Close button icon properties
	inline int closeIconSize = 10;
	inline Line closeIconComp_1 = {
		closebtnPosition.x + 18,
		closebtnPosition.y + 12,
		closeIconComp_1.Start.x + closeIconSize,
		closeIconComp_1.Start.y + closeIconSize
	};
	inline Line closeIconComp_2 = {
		closeIconComp_1.End.x,
		closeIconComp_1.Start.y,
		closeIconComp_1.Start.x,
		closeIconComp_1.End.y
	};
	inline Color closeIconColor = { 255, 255, 255, 215 };

	// Draw only the Titlebar close button
	inline void DrawClosebtn() {
		DrawRectangleRec(closebtnRect, closebtnColor);
		DrawLineEx(closeIconComp_1.Start.ToVector2(), closeIconComp_1.End.ToVector2(), 1, closeIconColor);
		DrawLineEx(closeIconComp_2.Start.ToVector2(), closeIconComp_2.End.ToVector2(), 1, closeIconColor);
	}

	// Maximize button properties
	inline Size maximizebtnSize = { 45, conteinerSize.Height };
	inline Position maximizebtnPosition = { closebtnPosition.x - maximizebtnSize.Width - 1, 0 };
	inline Rectangle maximezebtnRect = {
		maximizebtnPosition.ToVector2().x , maximizebtnPosition.ToVector2().y,
		maximizebtnSize.ToSize_f().Width, maximizebtnSize.ToSize_f().Height
	};
	inline Color maximizebtnColor = BLACK;

	// Maximize button icon properties
	inline int maximizeIconSize = 10;
	inline Rect maximizeIconComp_1 = {
		maximizebtnPosition.x + 18,
		maximizebtnPosition.y + 12,
		maximizeIconSize,
		maximizeIconSize
	};
	inline Color maximizeIconColor = WHITE;

	// Draw only the TitleBar maximize button
	inline void DrawMaximizebtn() {
		DrawRectangleRec(maximezebtnRect, maximizebtnColor);
		DrawRectangleLines(
			maximizeIconComp_1.x, maximizeIconComp_1.y,
			maximizeIconComp_1.Width, maximizeIconComp_1.Height,
			maximizeIconColor
		);
	}

	// Minimize button properties
	inline Size minimizebtnSize = { 45, conteinerSize.Height };
	inline Position minimizebtnPosition = { maximizebtnPosition.x - minimizebtnSize.Width - 1, 0 };
	inline Rectangle minimizebtnRect = {
		minimizebtnPosition.ToVector2().x , minimizebtnPosition.ToVector2().y,
		minimizebtnSize.ToSize_f().Width, minimizebtnSize.ToSize_f().Height
	};
	inline Color minimizebtnColor = BLACK;

	// Minimize button icon properties
	inline int minimizeIconSize = 10;
	inline Line minimizeIconComp_1 = {
		minimizebtnPosition.x + 18, 
		minimizebtnPosition.y + 18,
		minimizeIconComp_1.Start.x + minimizeIconSize,
		minimizeIconComp_1.Start.y
	};
	inline Color minimizeIconColor = WHITE;

	// Draw only the TitleBar minimize button
	inline void DrawMinimizebtn() {
		DrawRectangleRec(minimizebtnRect, minimizebtnColor);
		DrawLineEx(
			minimizeIconComp_1.Start.ToVector2(), minimizeIconComp_1.End.ToVector2(),
			1, minimizeIconColor
		);
	}

	// Draw complete Titlebar
	inline void DrawTitleBar() {
		DrawConteiner();
		DrawTitle();
		DrawMinimizebtn();
		DrawMaximizebtn();
		DrawClosebtn();
	}

	// Titlebar event handler
	inline void EventHandler() {
		if (CnslMouse::IsMouseOver(minimizebtnRect)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				MinimizeWindow();
			}
		}
		if (CnslMouse::IsMouseOver(maximezebtnRect)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				MaximizeWindow();
			}
		}
		if (CnslMouse::IsMouseOver(closebtnRect)) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				CloseWindow();
			}
		}
	}

}

namespace CnslTime {
	
	inline std::chrono::steady_clock::time_point currentTime;

	inline auto GetCurrentTime() {
		return std::chrono::steady_clock::now();
	}

	inline int ConvertTimeDifToMs(std::chrono::steady_clock::duration duration) {
		return static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(duration).count());
	}
}

namespace CnslCursor {
	
	inline bool ConsoleShowCursor = true;
	inline Size ConsoleCursorSize = { 8, 2 };
	inline Vector2 Position = {0, 0};
	inline Color color = WHITE;
	inline int BlinkRate = 500;
	inline auto StartBlinkRate = CnslTime::GetCurrentTime();
}

namespace Cnsl {

	inline void Out(std::string text) {
		OutputText.push_back({text});
	}

}
