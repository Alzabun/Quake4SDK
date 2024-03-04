#pragma once
#ifndef JUDGEMENT_H
#define JUDGEMENT_H
using namespace std;

/*
||||||||||||||||||||
 CUSTOM TIMING: BPM (ME) 
 |||||||||||||||||||
*/

extern int BPM;
extern int guicombo;

extern bool started;
extern bool comboup;
extern bool missed;
extern bool bad;
extern bool musicpending; // refer to Cmd_prepareMusic_f

extern bool gavequad;
extern bool gavehaste;
extern bool gaveregen;

struct Performance {
	int perfectCount = 0;
	int greatCount = 0;
	int goodCount = 0;
	int badCount = 0;
	int missCount = 0;
	int comboCount = 0;
};

extern Performance result;

int beatTiming(int input, int BPM);

Performance Judgement(int input);
float updateAccuracy(const Performance& performance);


#endif
