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
bool missed = false;
bool bad = false;
bool musicpending = false;
bool comboup = true;

bool gavequad = false;
bool gavehaste = false;
bool gaveregen = false;

int starttime = 0;
int guicombo = 0;
int songduration = 0; // in MS
int currenttime = 0;

int taps = 0;
int taplimit = 100;
int BPM = 160; // default value for devil trigger
int taptime[maxtaps];
bool BPMCalculation = false;

int beatTiming(int input, int BPM) {
	int beatDuration = 60000 / BPM; // the duration of a beat in ms
	return abs(input % beatDuration - beatDuration * 0.75);  // the absolute difference between the player's input timing and the middle of the beat duration (this formula might be modified again)
}	

Performance result;

Performance Judgement(int input) { // score rankings added depending on beat closeness. the most important part of this whole mod
	
	int timing = beatTiming(input, BPM);

	if (started) {
		if (timing <= 75) {
			result.comboCount++;
			result.perfectCount++;
			comboup = true;
		}
		else if (timing <= 100) {
			result.comboCount++;
			result.greatCount++;
			comboup = true;
		}
		else if (timing <= 125) {
			result.comboCount++;
			result.goodCount++;
			comboup = true;
		}
		else if (timing <= 150) {
			result.comboCount++;
			result.badCount++;
			bad = true; // not technically a miss but will decrease your armor instead (if you have any)
			comboup = true;
		}
		else {
			result.comboCount = 0;
			result.missCount++;
			missed = true;
		}

		return result;
	}
	
}

float updateAccuracy(const Performance& performance) { // calculates accuracy like how most rhythm games would. meant for the 10 rewards / perks earned through performance
	int weightcalculation = performance.perfectCount * 3 + performance.greatCount * 2 + performance.goodCount;
	int otherperformance = weightcalculation + performance.badCount + performance.missCount;

	if (otherperformance == 0) {
		return 100.0f; // nothing happened yet
	}

	float accuracy = static_cast<float>(weightcalculation) / otherperformance * 100.0f; // this is out of 100.00%
	return roundf(accuracy * 100.0f) / 100.0f; // formula to reduce to 2 decimal points (doesnt work???)
}

void calculateBPM() {
	
	int timedifference[maxtaps];
	for (int i = 0; i < taps - 1; i++) {
		timedifference[i] = taptime[i + 1] - taptime[i];
	}

	int totaldifference = 0;
	for (int i = 0; i < taps - 1; i++) {
		totaldifference += timedifference[i];
	}

	int averagedifference = totaldifference / (taps - 1);

	BPM = 60000 / averagedifference;
}