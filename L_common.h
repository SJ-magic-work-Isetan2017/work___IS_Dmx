#pragma once

/************************************************************
************************************************************/
#include "stdio.h"

/************************************************************
************************************************************/
typedef int (*PFUNC_SHORTPATTERN)(const int Progress);

enum SYMMETRIC_TYPE{
	SYMMETRY_RANDOM,
	SYMMETRY_LINE,
	SYMMETRY_RIGID,
};

enum DEVICE_CH_TYPE{
	DEVICE_CH_TYPE__FIX_STAGE_LIGHT,
	
	NUM_DEVICE_CH_TYPE,
};


/************************************************************
************************************************************/

/******************************
******************************/
template <typename ... Args>
void fprintf_Log_forTestCode(FILE* fp, const char *format, Args const & ... args)
{
	fprintf(fp, format, args ...);
}
void fprintf_Log_forTestCode(FILE* fp, const char *format)
{
	fprintf(fp, "%s", format);
}
