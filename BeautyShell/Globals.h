#pragma once
#include "CnslTypes.h"

namespace Cnsl {
	
	// Console propeties

	extern int windowWidth; // Defines the width of the window
	extern int windowHeight; // Defines the height of the window
	extern std::string windowTitle; // Defines the title of the window
	extern int windowFPS; // Defines the max FPS of the window
	extern ConfigFlags windowFlags; // Defines flags of the window
	extern Color windowColorBG; // Defines the background color of the window

	// Console functions
	
	extern void InitilizeConsole(); // Initializes the window
	extern void TerminateConsole(); // Terminates the window

}


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

	inline void CnslLoadFont(FontData& font) {
		font.font = LoadFontEx(font.font_path.c_str(), 32, nullptr, 250);
	}

	inline void CnslUnloadFont(FontData& font) {
		UnloadFont(font.font);
	}

}

namespace CnslTitlebar {

	/* Conteiner section */
	//
	extern Size conteinerSize; // Defines the size of the titlebar, based on the width of the window
	extern Color conteinerColor; // Defines the color of the titlebar
	
	extern void DrawConteiner(); // Draws only the Titlebar conteiner
	//
	/* Conteiner section */


	/* Title section */
	//
	extern Font titleFont; // Defines the font of the title
	extern float titleSize; // Defines the size of the title
	extern Position titlePosition; // Defines the position of the title
	extern float titleSpacing; // Defines the spacing of title
	extern Color titleColor; // Defines the color of the title

	extern void LoadTitlefont(); // Loads title font
	extern void DrawTitle(); // Draws only the titlebar title
	//
	/* Title section */


	/* Close button section */
	//
	extern Size closebtnSize;
	extern Position closebtnPosition;
	extern Rectangle closebtnRect;
	extern Color closebtnColor;
	//
	extern int closeIconSize = 10;
	extern Line closeIconComp_1;
	extern Line closeIconComp_2;
	extern Color closeIconColor;
	//
	extern void DrawClosebtn(); // Draws only the Titlebar close button
	//
	/* Close button section */


	/* Maximize button section */
	//
	extern Size maximizebtnSize;
	extern Position maximizebtnPosition;
	extern Rectangle maximezebtnRect;
	extern Color maximizebtnColor;
	//
	extern int maximizeIconSize;
	extern Rect maximizeIconComp_1;
	extern Color maximizeIconColor;
	//
	extern void DrawMaximizebtn(); // Draws only the TitleBar maximize button
	//
	/* Maximize button section */


	/* Minimize button section */
	//
	extern Size minimizebtnSize;
	extern Position minimizebtnPosition;
	extern Rectangle minimizebtnRect;
	extern Color minimizebtnColor;
	//
	extern int minimizeIconSize;
	extern Line minimizeIconComp_1;
	extern Color minimizeIconColor;
	//
	extern void DrawMinimizebtn(); // Draws only the TitleBar minimize button
	//
	/* Minimize button section */

	/* TO BE USED */
	//
	inline void DrawTitleBar(); // Draws complete Titlebar
	inline void EventHandler(); // Titlebar event handler
	//
	/* TO BE USED */

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

