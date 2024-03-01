#include "../../idlib/precompiled.h"
#pragma hdrstop

/*
||||||||||||||||||||
 CUSTOM TIMING: BPM (ME)
 |||||||||||||||||||
*/

// ME: note that a library called portaudio.h can apparently extract BPM

// the plan:
// weapon.cpp has a method that gets the ammo count of a weapon
// it does this by making a method in weapon.cpp that does stuff
// player.cpp uses the value from this to make changes to the gui
// if i can get the player input timing from any weapon, give it to weapon.cpp, (give it to judgement.cpp?), then give it to player.cpp,
// could i use that value to update the gui? like the same functionality as judgement.cpp but instead depending on what the value it it
// changes the string value and runs a script in the gui to change it to perfect great good miss rather than having an individual file for each of them

// ME: my current problem: why wont my mod actually mod the game? re check the videos becuase this seems like a stupid issue
// ^ fixed ME: note you can start runnning music via console commands. dont forget how useful console commands are
// SOUND ISSUE FIXES: apparently if the file isnt exaclty like the sound file they used then it wont work
// for example it has to be specificall mono and something number amount of HZ 
// idk if thatst he actual reason but it works when i do that so i guess it is
// OMG YOU CAN PRESS TAB IN CONSOLE TO AUTO FILL COMMANDS THAT WOULVE BEEN USFUL TO KNOW BEFORE ACCOMPLISHING NOTHING FOR 6H OURS STRAIGHT
// im pretty sure all of this judgement functionality should be in something like weapon.cpp ....
// never mind

#include <corecrt_math.h>
#include "judgement.h"

bool started = false;
int starttime = 0;
int guicombo = 0;

int beatTiming(int input/*, int BPM */) {
	int BPM = 160;
	int BPMS = 1 / (BPM / 60);
	int beatDuration = 60000 / BPM;
	return abs(input % beatDuration - beatDuration / 2); 
}	

Performance Judgement(int input) {
	
	int timing = beatTiming(input);

	Performance result;
	result.perfectCount = 0;
	result.greatCount = 0;
	result.goodCount = 0;
	result.missCount = 0;
	result.comboCount = 0;

	if (timing <= 50) {
		result.comboCount++;
		result.perfectCount++;
	}
	else if (timing <= 100) {
		result.comboCount++;
		result.greatCount++;
	}
	else if (timing <= 200) {
		result.comboCount++;
		result.goodCount++;
	}
	else {
		result.comboCount = 0;
		result.missCount++;
	}

	return result;
}