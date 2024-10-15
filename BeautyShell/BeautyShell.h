#pragma once
#include "KeyHandler.h"

void ConsoleDrawText(ConsoleText& text) {

	Vector2 NormalizedPosition = { text.Position.x * ScreenGridOffset.x, text.Position.y * ScreenGridOffset.y };

	DrawTextEx(CnslFont::CurrentFont.font, text.Text.c_str(), 
			   NormalizedPosition, 
			   CnslFont::FontSize, CnslFont::Spacing, text.color);
}

void ConsoleDrawCursor(Vector2 Position) {
	Vector2 NormalizedPosition = { Position.x * ScreenGridOffset.x , Position.y * ScreenGridOffset.y + 12};
	DrawRectangle(static_cast<int>(NormalizedPosition.x), static_cast<int>(NormalizedPosition.y),
				  CnslCursor::ConsoleCursorSize.Width, CnslCursor::ConsoleCursorSize.Height, 
				  CnslCursor::color);
}

void StartBeautyShell() {

	while (!WindowShouldClose()) {

		CnslTitlebar::EventHandler();

		CnslTime::currentTime = CnslTime::GetCurrentTime();

		int key = GetCharPressed();

		if (key >= 32 && key <= 125) {
			InputText.Text += (char)key;
		}

		KeyHandler::KeyEvents(key);

		BeginDrawing();
		ClearBackground(Cnsl::windowColorBG);

		CnslTitlebar::DrawTitleBar();


		for (auto OutText : OutputText) {
			ConsoleDrawText(OutText);
		}

		ConsoleDrawText(InputText);
		
		/*if (CnslTime::ConvertTimeDifToMs(CnslTime::currentTime - CnslCursor::StartBlinkRate) >= CnslCursor::BlinkRate) {
			ConsoleDrawCursor({ InputText.Position.x + InputText.Text.length(), InputText.Position.y });
			if (CnslTime::ConvertTimeDifToMs(CnslTime::currentTime - CnslCursor::StartBlinkRate) >= CnslCursor::BlinkRate * 2) {
				CnslCursor::StartBlinkRate = CnslTime::currentTime;
			}
		}*/

		EndDrawing();
	}

}
