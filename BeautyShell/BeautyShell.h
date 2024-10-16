#pragma once
#include "CnslTypes.h"

namespace Cnsl {

	/* Window section */
	//
	extern int windowWidth; // Defines the width of the window
	extern int windowHeight; // Defines the height of the window
	extern std::string windowTitle; // Defines the title of the window
	extern int windowFPS; // Defines the max FPS of the window
	extern ConfigFlags windowFlags; // Defines flags of the window
	extern Color windowColorBG; // Defines the background color of the window
	//
	inline bool shouldClose = false;
	inline std::thread ConsoleThread;
	//
	extern void InitializeConsole(); // Initializes the window
	extern void Console();
	extern void TerminateConsole(); // Terminates the window
	//
	/* Window section */

}

namespace CnslMouse {

	// Checks if the cursor is over the rect
	inline bool IsMouseOver(Rectangle rect) {
		Position_f mousePosition = GetMousePosition();
		return CheckCollisionPointRec(mousePosition, rect);
	}

}

namespace CnslFont {

	extern const std::string FONTS_PATH;

	extern FontData Arial;
	extern FontData CascadiaCode;
	extern FontData SegoeUI;

	extern FontData CurrentFont;
	extern float FontSize;
	extern float Spacing;

	extern void CnslLoadFont(FontData& font);

	extern void CnslUnloadFont(FontData& font);

}

namespace CnslTitlebar {

	/* Conteiner section */
	//
	extern Size conteinerSize; // Defines the size of the titlebar, based on the width of the window
	extern Color conteinerColor; // Defines the color of the titlebar
	//
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
	//
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
	extern int closeIconSize;
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

	/* Titlebar section */
	//
	extern void DrawTitleBar(); // Draws complete Titlebar
	extern void EventHandler(); // Titlebar event handler
	//
	/* Titlebar section */

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
