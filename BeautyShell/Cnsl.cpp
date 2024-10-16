#include "BeautyShell.h"

namespace Cnsl {

	// Console propeties
	int windowWidth = 500;
	int windowHeight = 600;
	std::string windowTitle = "BeautyShell";
	int windowFPS = 60;
	ConfigFlags windowFlags = FLAG_WINDOW_UNDECORATED;
	Color windowColorBG = { 12, 12, 12 };

	// Initializes the console
	void InitializeConsole() {
		ConsoleThread = std::thread(Console);
	}

	void Console() {

		InitWindow(windowWidth, windowHeight, windowTitle.c_str());
		SetTargetFPS(windowFPS);
		SetWindowState(windowFlags);

		CnslTitlebar::LoadTitlefont();
		CnslFont::CnslLoadFont(CnslFont::CurrentFont);

		while (!shouldClose) {

			CnslTitlebar::EventHandler();

			CnslTime::currentTime = CnslTime::GetCurrentTime();

			BeginDrawing();

			ClearBackground(Cnsl::windowColorBG);

			CnslTitlebar::DrawTitleBar();

			EndDrawing();

		}

		UnloadFont(CnslTitlebar::titleFont);

		CnslFont::CnslUnloadFont(CnslFont::CurrentFont);
		CnslFont::CnslUnloadFont(CnslFont::SegoeUI);

		CloseWindow();

	}

	// Terminates the console
	void TerminateConsole() {
		ConsoleThread.join();
	}

}