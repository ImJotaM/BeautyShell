#pragma once
#include "Globals.h"

namespace KeyHandler {

	inline auto StartBackspacePress = CnslTime::GetCurrentTime();
	inline int EreaseStartDelay = 350;
	inline auto StartRepeatRate = CnslTime::GetCurrentTime();
	inline int EreaseRepeatRate = 25;
	inline bool BackspaceActive = false;
	inline bool RepeatActive = false;

	inline void KeyEvents(char Key) {

		if (IsKeyPressed(KEY_BACKSPACE) && !InputText.Text.empty()) {
			InputText.Text.pop_back();
		}
		else if (IsKeyDown(KEY_BACKSPACE) && !InputText.Text.empty()) {
			if (!BackspaceActive) {
				BackspaceActive = true;
				StartBackspacePress = CnslTime::currentTime;
			}
			if (CnslTime::ConvertTimeDifToMs(CnslTime::currentTime - StartBackspacePress) >= EreaseStartDelay) {
				if (!RepeatActive) {
					RepeatActive = true;
					StartRepeatRate = CnslTime::currentTime;
				}
				if (CnslTime::ConvertTimeDifToMs(CnslTime::currentTime - StartRepeatRate) >= EreaseRepeatRate) {
					InputText.Text.pop_back();
					StartRepeatRate = CnslTime::currentTime;
				}
			}
		}
		else {
			BackspaceActive = false;
			RepeatActive = false;
		}

	}
}