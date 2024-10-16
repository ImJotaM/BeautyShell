#include "BeautyShell.h"

namespace CnslTitlebar {

	// Conteiner properties
	Size conteinerSize = { Cnsl::windowWidth , 32 };
	Color conteinerColor = BLACK;

	// Draws only the Titlebar conteiner
	void DrawConteiner() {
		DrawRectangle(0, 0, conteinerSize.Width, conteinerSize.Height, conteinerColor);
	}

	// Title properties
	Font titleFont = {};
	float titleSize = 16;
	Position titlePosition = { 0, conteinerSize.Height / 4 };
	float titleSpacing = 1;
	Color titleColor = WHITE;

	// Loads title font
	void LoadTitlefont() {
		titleFont = LoadFontEx("assets/fonts/SegoeUI.ttf", 16, nullptr, 250);
	}

	// Draws only the Titlebar title
	void DrawTitle() {
		DrawTextEx(titleFont, "BeautyShell", titlePosition.ToVector2(), titleSize, titleSpacing, titleColor);
	}

	// Close button properties
	Size closebtnSize = { 45 , conteinerSize.Height };
	Position closebtnPosition = { conteinerSize.Width - closebtnSize.Width, 0 };
	Rectangle closebtnRect = {
		closebtnPosition.ToVector2().x, closebtnPosition.ToVector2().y,
		closebtnSize.ToSize_f().Width, closebtnSize.ToSize_f().Height
	};
	Color closebtnColor = BLACK;

	// Close button icon properties
	int closeIconSize = 10;
	Line closeIconComp_1 = {
		closebtnPosition.x + 18,
		closebtnPosition.y + 12,
		closeIconComp_1.Start.x + closeIconSize,
		closeIconComp_1.Start.y + closeIconSize
	};
	Line closeIconComp_2 = {
		closeIconComp_1.End.x,
		closeIconComp_1.Start.y,
		closeIconComp_1.Start.x,
		closeIconComp_1.End.y
	};
	Color closeIconColor = { 255, 255, 255, 215 };

	// Draws only the Titlebar close button
	void DrawClosebtn() {
		DrawRectangleRec(closebtnRect, closebtnColor);
		DrawLineEx(closeIconComp_1.Start.ToVector2(), closeIconComp_1.End.ToVector2(), 1, closeIconColor);
		DrawLineEx(closeIconComp_2.Start.ToVector2(), closeIconComp_2.End.ToVector2(), 1, closeIconColor);
	}

	// Maximize button properties
	Size maximizebtnSize = { 45, conteinerSize.Height };
	Position maximizebtnPosition = { closebtnPosition.x - maximizebtnSize.Width - 1, 0 };
	Rectangle maximezebtnRect = {
		maximizebtnPosition.ToVector2().x , maximizebtnPosition.ToVector2().y,
		maximizebtnSize.ToSize_f().Width, maximizebtnSize.ToSize_f().Height
	};
	Color maximizebtnColor = BLACK;

	// Maximize button icon properties
	int maximizeIconSize = 10;
	Rect maximizeIconComp_1 = {
		maximizebtnPosition.x + 18,
		maximizebtnPosition.y + 12,
		maximizeIconSize,
		maximizeIconSize
	};
	Color maximizeIconColor = WHITE;

	// Draws only the TitleBar maximize button
	void DrawMaximizebtn() {
		DrawRectangleRec(maximezebtnRect, maximizebtnColor);
		DrawRectangleLines(
			maximizeIconComp_1.x, maximizeIconComp_1.y,
			maximizeIconComp_1.Width, maximizeIconComp_1.Height,
			maximizeIconColor
		);
	}

	// Minimize button properties
	Size minimizebtnSize = { 45, conteinerSize.Height };
	Position minimizebtnPosition = { maximizebtnPosition.x - minimizebtnSize.Width - 1, 0 };
	Rectangle minimizebtnRect = {
		minimizebtnPosition.ToVector2().x , minimizebtnPosition.ToVector2().y,
		minimizebtnSize.ToSize_f().Width, minimizebtnSize.ToSize_f().Height
	};
	Color minimizebtnColor = BLACK;

	// Minimize button icon properties
	int minimizeIconSize = 10;
	Line minimizeIconComp_1 = {
		minimizebtnPosition.x + 18,
		minimizebtnPosition.y + 18,
		minimizeIconComp_1.Start.x + minimizeIconSize,
		minimizeIconComp_1.Start.y
	};
	Color minimizeIconColor = WHITE;

	// Draws only the TitleBar minimize button
	void DrawMinimizebtn() {
		DrawRectangleRec(minimizebtnRect, minimizebtnColor);
		DrawLineEx(
			minimizeIconComp_1.Start.ToVector2(), minimizeIconComp_1.End.ToVector2(),
			1, minimizeIconColor
		);
	}

	// Draws complete Titlebar
	void DrawTitleBar() {
		DrawConteiner();
		DrawTitle();
		DrawMinimizebtn();
		DrawMaximizebtn();
		DrawClosebtn();
	}

	// Titlebar event handler
	void EventHandler() {
		if (CnslMouse::IsMouseOver(minimizebtnRect)) {
			minimizebtnColor = { 130, 130, 130, 80 };
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				MinimizeWindow();
			}
		}
		else { minimizebtnColor = BLACK; }
		if (CnslMouse::IsMouseOver(maximezebtnRect)) {
			maximizebtnColor = { 130, 130, 130, 80 };
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				MaximizeWindow();
			}
		}
		else { maximizebtnColor = BLACK; }
		if (CnslMouse::IsMouseOver(closebtnRect)) {
			closebtnColor = RED;
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				Cnsl::shouldClose = true;
			}
		}
		else { closebtnColor = BLACK; }

	}

}