/************************************************************
************************************************************/
#pragma once

#include "sj_common.h"
#include "L_common.h"

/************************************************************
************************************************************/
enum{
	MAX_CHS_IN_A_BLOCK = 7,
	MAX_SHORTPATTERN_INDEX = 30, // 1種類の block pattern内のshort pattern並び
};

struct BLOCK_PATTERN{
	char name[BUF_SIZE];
	
	double Speed;
	int StartPatternId_Candidate; // 0:start from 0. 1:start from 0 or 1.
	
	const PFUNC_SHORTPATTERN pShortPattern[MAX_SHORTPATTERN_INDEX][MAX_CHS_IN_A_BLOCK];
	enum SYMMETRIC_TYPE SymmetricType;
	
	int Weight[NUM_DEVICE_CH_TYPE][NUM_STATES];
};


/************************************************************
************************************************************/
extern const struct BLOCK_PATTERN Bp_1[];
extern const struct BLOCK_PATTERN Bp_2[];
extern const struct BLOCK_PATTERN Bp_3[];
extern const struct BLOCK_PATTERN Bp_4[];
extern const struct BLOCK_PATTERN Bp_5[];
extern const struct BLOCK_PATTERN Bp_6[];
extern const struct BLOCK_PATTERN Bp_7[];



