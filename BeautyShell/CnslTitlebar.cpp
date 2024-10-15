#include "Globals.h"

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
	inline void LoadTitlefont() {
		titleFont = LoadFontEx("assets/fonts/SegoeUI.ttf", 16, nullptr, 250);
	}

	// Draws only the Titlebar title
	inline void DrawTitle() {
		DrawTextEx(titleFont, "BeautyShell", titlePosition.ToVector2(), titleSize, titleSpacing, titleColor);
	}

	// Close button properties
	inline Size closebtnSize = { 45 , conteinerSize.Height };
	inline Position closebtnPosition = { conteinerSize.Width - closebtnSize.Width, 0 };
	inline Rectangle closebtnRect = {
		closebtnPosition.ToVector2().x, closebtnPosition.ToVector2().y,
		closebtnSize.ToSize_f().Width, closebtnSize.ToSize_f().Height
	};
	inline Color closebtnColor = BLACK;

	// Close button icon properties
	inline int closeIconSize = 10;
	inline Line closeIconComp_1 = {
		closebtnPosition.x + 18,
		closebtnPosition.y + 12,
		closeIconComp_1.Start.x + closeIconSize,
		closeIconComp_1.Start.y + closeIconSize
	};
	inline Line closeIconComp_2 = {
		closeIconComp_1.End.x,
		closeIconComp_1.Start.y,
		closeIconComp_1.Start.x,
		closeIconComp_1.End.y
	};
	inline Color closeIconColor = { 255, 255, 255, 215 };

	// Draws only the Titlebar close button
	inline void DrawClosebtn() {
		DrawRectangleRec(closebtnRect, closebtnColor);
		DrawLineEx(closeIconComp_1.Start.ToVector2(), closeIconComp_1.End.ToVector2(), 1, closeIconColor);
		DrawLineEx(closeIconComp_2.Start.ToVector2(), closeIconComp_2.End.ToVector2(), 1, closeIconColor);
	}

	// Maximize button properties
	inline Size maximizebtnSize = { 45, conteinerSize.Height };
	inline Position maximizebtnPosition = { closebtnPosition.x - maximizebtnSize.Width - 1, 0 };
	inline Rectangle maximezebtnRect = {
		maximizebtnPosition.ToVector2().x , maximizebtnPosition.ToVector2().y,
		maximizebtnSize.ToSize_f().Width, maximizebtnSize.ToSize_f().Height
	};
	inline Color maximizebtnColor = BLACK;

	// Maximize button icon properties
	inline int maximizeIconSize = 10;
	inline Rect maximizeIconComp_1 = {
		maximizebtnPosition.x + 18,
		maximizebtnPosition.y + 12,
		maximizeIconSize,
		maximizeIconSize
	};
	inline Color maximizeIconColor = WHITE;

	// Draws only the TitleBar maximize button
	inline void DrawMaximizebtn() {
		DrawRectangleRec(maximezebtnRect, maximizebtnColor);
		DrawRectangleLines(
			maximizeIconComp_1.x, maximizeIconComp_1.y,
			maximizeIconComp_1.Width, maximizeIconComp_1.Height,
			maximizeIconColor
		);
	}

	// Minimize button properties
	inline Size minimizebtnSize = { 45, conteinerSize.Height };
	inline Position minimizebtnPosition = { maximizebtnPosition.x - minimizebtnSize.Width - 1, 0 };
	inline Rectangle minimizebtnRect = {
		minimizebtnPosition.ToVector2().x , minimizebtnPosition.ToVector2().y,
		minimizebtnSize.ToSize_f().Width, minimizebtnSize.ToSize_f().Height
	};
	inline Color minimizebtnColor = BLACK;

	// Minimize button icon properties
	inline int minimizeIconSize = 10;
	inline Line minimizeIconComp_1 = {
		minimizebtnPosition.x + 18,
		minimizebtnPosition.y + 18,
		minimizeIconComp_1.Start.x + minimizeIconSize,
		minimizeIconComp_1.Start.y
	};
	inline Color minimizeIconColor = WHITE;

	// Draws only the TitleBar minimize button
	inline void DrawMinimizebtn() {
		DrawRectangleRec(minimizebtnRect, minimizebtnColor);
		DrawLineEx(
			minimizeIconComp_1.Start.ToVector2(), minimizeIconComp_1.End.ToVector2(),
			1, minimizeIconColor
		);
	}

	// Draws complete Titlebar
	inline void DrawTitleBar() {
		DrawConteiner();
		DrawTitle();
		DrawMinimizebtn();
		DrawMaximizebtn();
		DrawClosebtn();
	}

	// Titlebar event handler
	inline void EventHandler() {
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
				CloseWindow();
			}
		}
		else { closebtnColor = BLACK; }

	}

}