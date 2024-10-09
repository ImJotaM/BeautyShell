#include <raylib.h>
#include <iostream>
#include <vector>
#include <string>

struct Screen_Text {
	std::string Text = "";
	Vector2 Pos = { 0, 0 };
	Color color = WHITE;
};

int main() {

	InitWindow(500, 600, "MySole");
	SetTargetFPS(60);

	std::vector<Screen_Text> OutputText;

	OutputText.push_back({ "Bem-vindo ao BeautyShell!", {10, 10}, GREEN });
	OutputText.push_back({ "Linha de comando: ", {10, 28}, WHITE });

	Screen_Text InputText;
	InputText.Pos = { (float)(OutputText.back().Text.size() * 8 + 8), 28 };

	Font arial = LoadFontEx("assets/fonts/CascadiaCode.ttf", 32, NULL, 250);

	while (!WindowShouldClose()) {
		
		int key = GetCharPressed();

		if (key >= 32 && key <= 125) {
			InputText.Text += (char) key;
		}

		if (IsKeyPressed(KEY_BACKSPACE) && !InputText.Text.empty()) {
			InputText.Text.pop_back();
		}

		BeginDrawing();

		ClearBackground(BLACK);

		for (auto OutText : OutputText) {
			DrawTextEx(arial, OutText.Text.c_str(), OutText.Pos, 16, 0, OutText.color);
		}

		DrawTextEx(arial, InputText.Text.c_str(), InputText.Pos, 16, 0, InputText.color);

		EndDrawing();

	}

	UnloadFont(arial);
	CloseWindow();

	return 0;
}