#include "BeautyShell.h"

namespace CnslFont {

	const std::string FONTS_PATH = "assets/fonts/";

	FontData Arial = { {}, FONTS_PATH + "arial.ttf" };
	FontData CascadiaCode = { {}, FONTS_PATH + "CascadiaCode.ttf" };
	FontData SegoeUI = { {}, FONTS_PATH + "SegoeUI.ttf" };
	
	FontData CurrentFont = CascadiaCode;
	float FontSize = 16;
	float Spacing = 0;
	
	void CnslLoadFont(FontData& font) {
		font.font = LoadFontEx(font.font_path.c_str(), 32, nullptr, 250);
	}

	void CnslUnloadFont(FontData& font) {
		UnloadFont(font.font);
	}

}