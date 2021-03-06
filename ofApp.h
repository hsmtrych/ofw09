#pragma once

#include "ofMain.h"
#include "component.hpp"
#include "DrawGrid.hpp"

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
	  // ofVec2f movePos;
	  // ofVec2f circlePos;
	  // ofVec2f diffPos;
	  // ofColor circleCol;
	  // float radiusDflt,colR,colG,colB;
	  // float angle;
	  // bool mouseMvd,mouseDrg,mouseHit;
	  // string mouseMvdString;
	  ofVec2f minCursor;
	  // bool keyPressedR;
	  float angleSet,angleRelease,angleSave;
    ofPoint mouse;
    ofPoint prev_mouse;
    ofPoint target;

	  //クラス
	  component newComponent; // クラスcomponentをインスタンス化(実体化)
	  DrawGrid newGrid;
};
