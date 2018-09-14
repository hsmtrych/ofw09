#pragma once

#include "ofMain.h"

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

	  //変数
	  ofVec2f movePos;
	  ofColor circleCol;
	  float radius,radiusDflt,colR,colG,colB;
	  bool mouseMvd,mouseDrg,mouseHit;
	  string mouseMvdString;

	  static const int NUM = 5;
	  ofVec2f circlePos[NUM];
	  ofVec2f diffPos[NUM];
    float length_x[NUM];
    float length_y[NUM];
};
