#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
//     ofSetupOpenGL(1024,768,OF_WINDOW);            // <-------- setup the GL context

    //ウインドウ枠非表示
    ofGLFWWindowSettings windowSettings;
    windowSettings.decorated = false;
    windowSettings.width = 1024;
    windowSettings.height = 768;
    ofCreateWindow(windowSettings);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
