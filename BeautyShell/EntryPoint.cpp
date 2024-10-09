#include <raylib.h>
#include <iostream>
#include <string>

int main() {

	InitWindow(500, 600, "MySole");
	SetTargetFPS(60);

	std::string Message = "Bem-vindo ao MySole!";
	Vector2 MessagePos = {10, 10};

	Font arial = LoadFontEx("assets/fonts/CascadiaCode.ttf", 32, NULL, 250);

	while (!WindowShouldClose()) {
		
		BeginDrawing();

		ClearBackground(BLACK);

		DrawTextEx(arial, Message.c_str(), MessagePos, 16, 0, GREEN);

		EndDrawing();

	}

	CloseWindow();

	return 0;
}