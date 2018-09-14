#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetCircleResolution(64);

    // circlePos = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
    newComponent.circlePos = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);

    colR =30;
    colG =60;
    colB =255;
    circleCol.r = colR;
    circleCol.g = colG;
    circleCol.b = colB;
    radiusDflt = 20;
    // radius = radiusDflt;
    newComponent.radius = radiusDflt;
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
    newComponent.radius = 30;
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
  // ofDrawCircle(circlePos.x, circlePos.y, radius*2);
  newComponent.draw();


  //変数確認
  ofSetHexColor(0xffffff);
  ofDrawBitmapString("movePos.x : " + ofToString(movePos.x), 10, 10);
  ofDrawBitmapString("movePos.y : " + ofToString(movePos.y), 10, 30);
  ofDrawBitmapString("mouseMvd : " + ofToString(mouseMvdString), 10, 50);
  ofDrawBitmapString("circlePos.x : " + ofToString(newComponent.circlePos.x), 10, 70);
  ofDrawBitmapString("circlePos.y : " + ofToString(newComponent.circlePos.y), 10, 90);
  ofDrawBitmapString("diffPos.x : " + ofToString(diffPos.x), 10, 110);
  ofDrawBitmapString("diffPos.y : " + ofToString(diffPos.y), 10, 130);
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
  // mouseDrg = true;
   if (mouseDrg){
    newComponent.circlePos = ofVec2f(x, y);
  }

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
   mouseMvd = false;
    diffPos = newComponent.circlePos - movePos;
    float length_x = diffPos.x;
    float length_y = diffPos.y;
    if (-40 < length_x && length_x < 40 && -40 < length_y && length_y < 40 ){
      mouseDrg = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  newComponent.radius = radiusDflt;
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
