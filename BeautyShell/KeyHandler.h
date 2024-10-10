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
				StartBackspacePress = currentTime;
			}
			if (CnslTime::ConvertTimeDifToMs(currentTime - StartBackspacePress) >= EreaseStartDelay) {
				if (!RepeatActive) {
					RepeatActive = true;
					StartRepeatRate = currentTime;
				}
				if (CnslTime::ConvertTimeDifToMs(currentTime - StartRepeatRate) >= EreaseRepeatRate) {
					InputText.Text.pop_back();
					StartRepeatRate = currentTime;
				}
			}
		}
		else {
			BackspaceActive = false;
			RepeatActive = false;
		}

	}
}