#include "../../idlib/precompiled.h"
#pragma hdrstop

/*
||||||||||||||||||||
 CUSTOM TIMING: BPM (ME)
 |||||||||||||||||||
*/

#include <corecrt_math.h>
#include "judgement.h"

bool started = false;
int starttime = 0;
int guicombo = 0;

int beatTiming(int input/*, int BPM */) {
	int BPM = 160;
	int beatDuration = 60000 / BPM; // the duration of a beat in ms
	return abs(input % beatDuration - beatDuration / 2);  // the absolute difference between the player's input timing and the middle of the beat duration (this formula might be modified again)
}	

Performance Judgement(int input) {
	
	int timing = beatTiming(input);

	Performance result;
	result.perfectCount = 0;
	result.greatCount = 0;
	result.goodCount = 0;
	result.missCount = 0;
	result.comboCount = 0;

	if (timing <= 75) {
		result.comboCount++;
		result.perfectCount++;
	}
	else if (timing <= 100) {
		result.comboCount++;
		result.greatCount++;
	}
	else if (timing <= 125) {
		result.comboCount++;
		result.goodCount++;
	}
	else {
		result.comboCount = 0;
		result.missCount++;
	}

	return result;
}