#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

const std::string FONTS_PATH = "assets/fonts/";

auto StartBackspacePress = std::chrono::steady_clock::now();
int EreaseStartDelay = 500;
auto StartRepeatRate = std::chrono::steady_clock::now();
int EreaseRepeatRate = 25;

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

void ConsoleLoadFont(FontData& font) {
	font.font = LoadFontEx(font.font_path.c_str(), 32, nullptr, 250);
}

void ConsoleUnloadFont(FontData& font) {
	UnloadFont(font.font);
}

int ConvertTimeDifToMs(std::chrono::steady_clock::duration duration) {
	return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

FontData Arial = { {}, FONTS_PATH + "arial.ttf" };
FontData CascadiaCode = { {}, FONTS_PATH + "CascadiaCode.ttf" };

void StartBeautyShell() {

	ConsoleData MainConsole = {
		500, 600, "BeautyShell", 60, BLACK
	};

	InitWindow(MainConsole.Width, MainConsole.Height, MainConsole.Title.c_str());
	SetTargetFPS(MainConsole.FPS);

	ConsoleLoadFont(CascadiaCode);

	FontData CurrentFont = CascadiaCode;

	std::vector<ConsoleText> OutputText;

	OutputText.push_back({ "Bem-vindo ao BeautyShell!", {10, 10}, GREEN });
	OutputText.push_back({ "Linha de comando: ", {10, 28}, WHITE });

	ConsoleText InputText;
	InputText.Position = { (float)(OutputText.back().Text.size() * 8 + 8), 28 };

	bool BackspaceActive = false;
	bool RepeatActive = false;

	while (!WindowShouldClose()) {

		int key = GetCharPressed();

		if (key >= 32 && key <= 125) {
			InputText.Text += (char)key;
		}

		auto currentTime = std::chrono::steady_clock::now();

		if (IsKeyPressed(KEY_BACKSPACE) && !InputText.Text.empty()) {
			InputText.Text.pop_back();
		} else if (IsKeyDown(KEY_BACKSPACE) && !InputText.Text.empty()) {
			if (!BackspaceActive) {
				BackspaceActive = true;
				StartBackspacePress = currentTime;
			}
			if (ConvertTimeDifToMs(currentTime - StartBackspacePress) >= EreaseStartDelay) {
				if (!RepeatActive) {
					RepeatActive = true;
					StartRepeatRate = currentTime;
				}
				if (ConvertTimeDifToMs(currentTime - StartRepeatRate) >= EreaseRepeatRate) {
					InputText.Text.pop_back();
					StartRepeatRate = currentTime;
				}
			}
		} else {
			BackspaceActive = false;
			RepeatActive = false;
		}

		BeginDrawing();

		ClearBackground(MainConsole.Background);

		for (auto OutText : OutputText) {
			DrawTextEx(CurrentFont.font, OutText.Text.c_str(), OutText.Position, 16, 0, OutText.color);
		}

		DrawTextEx(CurrentFont.font, InputText.Text.c_str(), InputText.Position, 16, 0, InputText.color);

		EndDrawing();

	}

	ConsoleUnloadFont(CurrentFont);
	CloseWindow();

}
