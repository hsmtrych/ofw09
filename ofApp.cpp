#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetCircleResolution(64);

    for (int i = 0; i < NUM; i++) {
      circlePos[i] = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    }
    // circlePos = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
    // ofVec2f boundingBox;
    // boundingBox = ofVec2f(radiusDflt);
    // boundingPosMax = ofVec2f(circlePos.x +  );
    // boundingMaxX = circlePos.x + (radius / 2);
    // boundingMinX = circlePos.x - (radius / 2);
    // boundingMaxY = circlePos.y + (radius / 2);
    // boundingMinY = circlePos.y - (radius / 2);

    colR =30;
    colG =60;
    colB =255;
    circleCol.r = colR;
    circleCol.g = colG;
    circleCol.b = colB;
    radiusDflt = 20;
    radius = radiusDflt;
    mouseMvd = false;
    mouseDrg = false;
    mouseMvdString = "false";
}

//--------------------------------------------------------------
void ofApp::update(){

  if (mouseMvd && !mouseDrg){
    circleCol.r = colR;
    circleCol.g = colG;
    circleCol.b = colB;
    mouseMvdString = "true";
    mouseMvd = false;
  }else if(mouseDrg && !mouseMvd) {
    circleCol.r = 255;
    circleCol.g = 60;
    circleCol.b = 30;
    radius = 30;
    mouseMvdString = "false";
    mouseMvd = false;
  }else {
    circleCol.r = 127;
    circleCol.g = 127;
    circleCol.b = 127;
    mouseMvdString = "false";
  }
}

//--------------------------------------------------------------
void ofApp::draw(){

  ofSetColor(circleCol.r, circleCol.g, circleCol.b);
    for (int i = 0; i < NUM; i++) {
      ofDrawCircle(circlePos[i].x, circlePos[i].y, radius*2);
    }


  //変数確認
  ofSetHexColor(0xffffff);
  ofDrawBitmapString("movePos.x : " + ofToString(movePos.x), 10, 10);
  ofDrawBitmapString("movePos.y : " + ofToString(movePos.y), 10, 30);
  ofDrawBitmapString("mouseMvd : " + ofToString(mouseMvdString), 10, 50);
  ofDrawBitmapString("circlePos[0].x : " + ofToString(circlePos[0].x), 10, 70);
  ofDrawBitmapString("circlePos[1].x : " + ofToString(circlePos[1].x), 10, 90);
  ofDrawBitmapString("circlePos[2].x : " + ofToString(circlePos[2].x), 10, 110);
  ofDrawBitmapString("circlePos[3].x : " + ofToString(circlePos[3].x), 10, 130);
  ofDrawBitmapString("circlePos[4].x : " + ofToString(circlePos[4].x), 10, 150);

  ofDrawBitmapString("length_x[0] : " + ofToString(length_x[0]), 10, 170);
  ofDrawBitmapString("length_x[1] : " + ofToString(length_x[1]), 10, 190);
  ofDrawBitmapString("length_x[2] : " + ofToString(length_x[2]), 10, 210);

  // ofDrawBitmapString("circlePos.x : " + ofToString(circlePos.x), 10, 70);
  // ofDrawBitmapString("circlePos.y : " + ofToString(circlePos.y), 10, 90);
  // ofDrawBitmapString("diffPos.x : " + ofToString(diffPos.x), 10, 110);
  // ofDrawBitmapString("diffPos.y : " + ofToString(diffPos.y), 10, 130);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    // movePos.x = x;
    // movePos.y = y;
  movePos = ofVec2f(x, y);

  mouseMvd = true;
  mouseDrg = false;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
  mouseMvd = false;
  mouseDrg = true;

  // if (mouseDrg){
  //   for (int i = 0; i < NUM; i++) {
  //     circlePos[i] = ofVec2f(x, y);
  //   }
  //   // circlePos[i] = ofVec2f(x, y);
  // }
    for (int i = 0; i < NUM; i++) {
      circlePos[i] = ofVec2f(x, y);
    }

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mouseMvd = false;
    for (int i = 0; i < NUM; i++) {
      diffPos[i] = circlePos[i] - movePos;
      length_x[i] = diffPos[i].x;
      length_y[i] = diffPos[i].y;
    }
    // diffPos = circlePos - movePos;
    // float length_x = diffPos[i].x;
    // float length_y = diffPos[i].y;
    // if (-40 < length_x && length_x < 40 && -40 < length_y && length_y < 40 ){
    //   mouseDrg = true;
    // }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  radius = radiusDflt;
  mouseDrg = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
