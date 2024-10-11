#pragma once
#include "KeyHandler.h"

void ConsoleLoadFont(FontData& font) {
	font.font = LoadFontEx(font.font_path.c_str(), 32, nullptr, 250);
}

void ConsoleUnloadFont(FontData& font) {
	UnloadFont(font.font);
}

void ConsoleDrawText(ConsoleText& text) {

	Vector2 NormalizedPosition = { text.Position.x * ScreenGridOffset.x, text.Position.y * ScreenGridOffset.y };

	DrawTextEx(CnslFont::CurrentFont.font, text.Text.c_str(), NormalizedPosition, CnslFont::FontSize, CnslFont::Spacing, text.color);
}

void ConsoleDrawCursor(Vector2 Position) {
	Vector2 NormalizedPosition = { Position.x * ScreenGridOffset.x , Position.y * ScreenGridOffset.y };
	DrawRectangle(static_cast<int>(NormalizedPosition.x), static_cast<int>(NormalizedPosition.y),
				  CnslCursor::ConsoleCursorSize.Width, CnslCursor::ConsoleCursorSize.Height, 
				  CnslCursor::color);
}

void StartBeautyShell() {

	InitWindow(MainConsole.Size.Width, MainConsole.Size.Width, MainConsole.Title.c_str());
	SetTargetFPS(MainConsole.FPS);

	ConsoleLoadFont(CnslFont::CurrentFont);

	OutputText.push_back({ "Bem-vindo ao BeautyShell!", {1, 1}, GREEN });
	OutputText.push_back({ "Linha de comando: ", {1, 2}, WHITE });

	InputText.Position = { (float)(OutputText.back().Text.size() + 1), 2 };

	while (!WindowShouldClose()) {

		CnslTime::currentTime = CnslTime::GetCurrentTime();

		int key = GetCharPressed();

		if (key >= 32 && key <= 125) {
			InputText.Text += (char)key;
		}

		KeyHandler::KeyEvents(key);

		BeginDrawing();

		ClearBackground(MainConsole.Background);

		for (auto OutText : OutputText) {
			ConsoleDrawText(OutText);
		}

		ConsoleDrawText(InputText);
		
		if (CnslTime::ConvertTimeDifToMs(CnslTime::currentTime - CnslCursor::StartBlinkRate) >= CnslCursor::BlinkRate) {
			ConsoleDrawCursor({ InputText.Position.x + InputText.Text.length(), InputText.Position.y });
			if (CnslTime::ConvertTimeDifToMs(CnslTime::currentTime - CnslCursor::StartBlinkRate) >= CnslCursor::BlinkRate * 2) {
				CnslCursor::StartBlinkRate = CnslTime::currentTime;
			}
		}

		EndDrawing();
	}

	ConsoleUnloadFont(CnslFont::CurrentFont);
	CloseWindow();

}
