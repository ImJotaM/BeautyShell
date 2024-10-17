#include "BeautyShell.h"

namespace Cnsl {

	// Console propeties
	int windowWidth = 600;
	int windowHeight = 400;
	std::string windowTitle = "BeautyShell";
	int windowFPS = 60;
	ConfigFlags windowFlags = FLAG_WINDOW_UNDECORATED;
	Color windowColorBG = { 12, 12, 12 };

	void InitializeWindow() {

		InitWindow(windowWidth, windowHeight, windowTitle.c_str());
		SetTargetFPS(windowFPS);
		SetWindowState(windowFlags);

	}

	// Initializes the console
	void InitializeConsole() {
		ConsoleThread = std::thread(Console);
	}

	void Console() {

		InitializeWindow();

		CnslTitlebar::LoadTitlefont();
		CnslFont::CnslLoadFont(CnslFont::CurrentFont);

		CnslTitlebar::iconImage = LoadImage("assets/icons/icon.png");
		CnslTitlebar::iconTexture = LoadTextureFromImage(CnslTitlebar::iconImage);
		UnloadImage(CnslTitlebar::iconImage);

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

		UnloadTexture(CnslTitlebar::iconTexture);

		CloseWindow();

	}

	// Terminates the console
	void TerminateConsole() {
		ConsoleThread.join();
	}

}