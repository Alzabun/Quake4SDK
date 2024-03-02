#pragma once
#ifndef JUDGEMENT_H
#define JUDGEMENT_H
using namespace std;

/*
||||||||||||||||||||
 CUSTOM TIMING: BPM (ME) 
 |||||||||||||||||||
*/

extern int starttime;
extern bool started;
extern int guicombo;
extern int songduration;
extern int currenttime;

struct Performance {
	int perfectCount = 0;
	int greatCount = 0;
	int goodCount = 0;
	int missCount = 0;
	int comboCount = 0;
};

extern Performance result;

int beatTiming(int input);

Performance Judgement(int input);

#endif
