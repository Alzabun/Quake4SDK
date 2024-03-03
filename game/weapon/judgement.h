#pragma once
#ifndef JUDGEMENT_H
#define JUDGEMENT_H
using namespace std;

/*
||||||||||||||||||||
 CUSTOM TIMING: BPM (ME) 
 |||||||||||||||||||
*/

extern int guicombo;

extern bool started;
extern bool missed;
extern bool musicpending; // refer to Cmd_prepareMusic_f

struct Performance {
	int perfectCount = 0;
	int greatCount = 0;
	int goodCount = 0;
	int badCount = 0;
	int missCount = 0;
	int comboCount = 0;
};

extern Performance result;

int beatTiming(int input);

Performance Judgement(int input);
float updateAccuracy(const Performance& performance);


#endif
