#ifndef _SnapShotManager
#define _SnapShotManager
#include "ofMain.h" 

class SnapShotManager {

public:

	void setup();
	void update();
	void draw();

	void SaveImage();

	SnapShotManager();

	ofVideoGrabber vidGrabber;
	ofTexture videoTexture;
	ofPixels videoInverted;
	int camWidth;
	int camHeight;

	ofImage 			img;
	ofImage 			imgToSave;
	bool 				bSnapshot;
	bool 				showCam;

	ofShader shaderBlurX;
	ofShader shaderBlurY;

	ofFbo fboBlurOnePass;
	ofFbo fboBlurTwoPass;

	//timers
	float timerSnapshot;

	//counters
	int imageCounter;

private:
};
#endif