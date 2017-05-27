/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "stdio.h"

#include "ofMain.h"
#include "ofxGui.h"

/************************************************************
************************************************************/
#define ERROR_MSG(); printf("Error in %s:%d\n", __FILE__, __LINE__);

enum{
	WIDTH = 400,
	HEIGHT = 300,
};

enum{
	BUF_SIZE = 2000,
};

enum{
	THREAD_TIMETABLE__EVENT,
	THREAD_TIMETABLE__COLOR,
	
	NUM_THREAD_TIMETABLE,
};

enum BOOT_MODE{
	BOOT_MODE__TEST,
	
	BOOT_MODE__AUTOPLAY,
	BOOT_MODE__REC,
};

enum STATE{
	STATE_NONE,
	
	STATE_FFT,
	STATE_NORMAL,
	STATE_SPEED,
	STATE_STROBE,
	STATE_BEAT,
	
	STATE_ON,
	STATE_OFF,
	
	NUM_STATES,
};


/************************************************************
************************************************************/
/**************************************************
**************************************************/
class GUI_PARAM{
private:
	/****************************************
	****************************************/
	
public:
	/****************************************
	****************************************/
	void setup(string GuiName, string FileName = "gui.xml", float x = 10, float y = 10);
	
	/****************************************
	****************************************/
	ofxPanel gui;
	
	ofxFloatSlider Alpha_FixedLed;
	
	ofxFloatSlider fftGain_Range;
	
	/* */
	ofxGuiGroup GuiGroup_Test;
	ofxIntSlider LedId;
	ofxColorSlider TestColor;
};

/************************************************************
************************************************************/
extern void fopen_LogFile();
extern void fclose_LogFile();
extern void fprint_debug_Log(char* message, int FileId);

/************************************************************
************************************************************/
extern float ElapsedTime;
extern int MusicTime;
extern BOOT_MODE BootMode;
extern GUI_PARAM* Gui_Param;
