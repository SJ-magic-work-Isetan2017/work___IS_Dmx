/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"

#include "ofxNetwork.h"

#include "sj_common.h"
#include "sj_Osc.h"
#include "Light.h"

/************************************************************
************************************************************/

/**************************************************
**************************************************/
class ofApp : public ofBaseApp{
private:
	/****************************************
	****************************************/
	enum{
		UDP_RECEIVE_PORT = 12351,
		SIZE_UPD = 100000,
	};
	enum{
		NUM_FFT_VERTS = 4 * 4,
	};
	
	/****************************************
	****************************************/
	OSC_TARGET Osc_MusicPlayer;
	
	ofTrueTypeFont font;
	
	/********************
	********************/
	ofxUDPManager udpConnection;
	bool b_NoUdpMessageYet;
	
	int N;
	
	ofVbo Vbo;
	ofVec3f VboVerts[NUM_FFT_VERTS];
	ofFloatColor VboColor[NUM_FFT_VERTS];
	
	vector<float> fft_Gain;
	vector<float> AudioSample_Rev;
	
	/********************
	********************/
	LIGHT Light;
	
	
	/****************************************
	****************************************/
	void update_OscFrom_MusicPlayer();
	void draw_time();
	void RefreshVerts();
	void Refresh_BarColor();
	void setup_on_1stMessage();
	void update_UdpFrom_Analyzer();
	void draw_fftBar();
	
public:
	/****************************************
	****************************************/
	ofApp(int _BootMode);
	~ofApp();
	
	void exit();
	
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
};
