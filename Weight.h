#pragma once

/************************************************************
************************************************************/
#include "sj_common.h"

/************************************************************
************************************************************/

/******************************
******************************/
static const int W_BlockGrouping[NUM_STATES][NUM_GROUPTYPES] = {
	{ // STATE_NONE
	},
	{ // STATE_FFT
		0, // "GP__CH6",
		0, // "GP__CH3",
		0, // "GP__CH3_DIRECTION",
		0, // "GP__CH3_SYMMETRY",
		0, // "GP__CH2",
		1, // "GP__CH1",
	},
	{ // STATE_NORMAL
		3, // "GP__CH6",
		1, // "GP__CH3",
		1, // "GP__CH3_DIRECTION",
		1, // "GP__CH3_SYMMETRY",
		0, // "GP__CH2",
		0, // "GP__CH1",
	},
	{ // STATE_SPEED
		2, // "GP__CH6",
		1, // "GP__CH3",
		1, // "GP__CH3_DIRECTION",
		0, // "GP__CH3_SYMMETRY",
		0, // "GP__CH2",
		0, // "GP__CH1",
	},
	{ // STATE_STROBE
		2, // "GP__CH6",
		1, // "GP__CH3",
		1, // "GP__CH3_DIRECTION",
		1, // "GP__CH3_SYMMETRY",
		2, // "GP__CH2",
		0, // "GP__CH1",
	},
	{ // STATE_BEAT
		0, // "GP__CH6",
		1, // "GP__CH3",
		1, // "GP__CH3_DIRECTION",
		1, // "GP__CH3_SYMMETRY",
		2, // "GP__CH2",
		2, // "GP__CH1",
	},
	{ // STATE_ON
		0, // "GP__CH6",
		0, // "GP__CH3",
		0, // "GP__CH3_DIRECTION",
		0, // "GP__CH3_SYMMETRY",
		0, // "GP__CH2",
		1, // "GP__CH1",
	},
	{ // STATE_OFF
		0, // "GP__CH6",
		0, // "GP__CH3",
		0, // "GP__CH3_DIRECTION",
		0, // "GP__CH3_SYMMETRY",
		0, // "GP__CH2",
		1, // "GP__CH1",
	},
};

