#pragma once

#include "ofMain.h"
#include "DataHandler/DataHandler.h"
#include "SnapShotManager/SnapShotManager.h"
#include "ofxCustomButton.h"

class ofApp : public ofBaseApp{

	public:
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

		void onInitialResponseHandler(ofxJSONElement & data);
		void onResultstoreResponseHandler(ofxJSONElement & data);

		void askNextQuestion();

		DataHandler dataHandler;
		SnapShotManager snapShotManager;

		string responseStr;
		string currentQuestion;

		string databaseRowIndex;
		int currentQuestionIndex;

		

		//data
		ofxJSONElement localData;
		int numQuestions;

		//states
		bool doAskNextQuestion;
		bool doDrawButtons;

		//buttons
		ofxCustomButton yesButton;
		ofxCustomButton noButton;
		
};
