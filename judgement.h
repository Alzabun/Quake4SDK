#pragma once
#ifndef JUDGEMENT_H
#define JUDGEMENT_H
using namespace std;

/*
||||||||||||||||||||
 CUSTOM TIMING: BPM (ME) 
 |||||||||||||||||||
*/

extern int timing;

struct Performance {
	int perfectCount;
	int greatCount;
	int goodCount;
	int missCount;
	int comboCount;
};

int beatTiming(int input);

Performance Judgement(int input);

#endif
