#include "Globals.h"

namespace Cnsl {

	// Console propeties
	int windowWidth = 500;
	int windowHeight = 600;
	std::string windowTitle = "BeautyShell";
	int windowFPS = 60;
	ConfigFlags windowFlags = FLAG_WINDOW_UNDECORATED;
	Color windowColorBG = { 12, 12, 12 };

	// Initializes the console

	void InitilizeConsole() {

		InitWindow(windowWidth, windowHeight, windowTitle.c_str());
		SetTargetFPS(windowFPS);
		SetWindowState(windowFlags);

		CnslTitlebar::LoadTitlefont();
		CnslFont::CnslLoadFont(CnslFont::CurrentFont);
	}

	// Terminates the console

	void TerminateConsole() {

		UnloadFont(CnslTitlebar::titleFont);

		CnslFont::CnslUnloadFont(CnslFont::CurrentFont);
		CnslFont::CnslUnloadFont(CnslFont::SegoeUI);

		CloseWindow();
	}

}