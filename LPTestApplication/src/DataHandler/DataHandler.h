#ifndef _DataHandler 
#define _DataHandler 
#include "ofMain.h" 
#include "ofxHttpUtils.h"
#include "ofxJSON.h"

class DataHandler {

public:

	void setup();
	void update();
	void draw();

	DataHandler();

	//events
	ofEvent<ofxJSONElement> onResultInitial;
	ofEvent<ofxJSONElement> onResultstoreResponse;

	//methods
	void getQuestionsDataAndConfig();
	void storeResponse();

	void newResponse(ofxHttpResponse & response);

	ofxHttpUtils httpUtils;
	int counter;
	string responseStr;
	string requestStr;
	string action_url;

	ofxJSONElement result;

	string webServiceCalled;

private:
};
#endif