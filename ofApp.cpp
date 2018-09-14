#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetCircleResolution(64);

    newComponent.circlePos = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
    newComponent.radiusDflt = 20;
    newComponent.setup();


}

//--------------------------------------------------------------
void ofApp::update(){
  newComponent.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

  newComponent.draw();


  //変数確認
  ofSetHexColor(0xffffff);
  ofDrawBitmapString("movePos.x : " + ofToString(newComponent.movePos.x), 10, 10);
  ofDrawBitmapString("movePos.y : " + ofToString(newComponent.movePos.y), 10, 30);
  ofDrawBitmapString("mouseMvd : " + ofToString(newComponent.mouseMvdString), 10, 50);
  ofDrawBitmapString("circlePos.x : " + ofToString(newComponent.circlePos.x), 10, 70);
  ofDrawBitmapString("circlePos.y : " + ofToString(newComponent.circlePos.y), 10, 90);
  ofDrawBitmapString("diffPos.x : " + ofToString(newComponent.diffPos.x), 10, 110);
  ofDrawBitmapString("diffPos.y : " + ofToString(newComponent.diffPos.y), 10, 130);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
  // movePos = ofVec2f(x, y);
  // mouseMvd = true;
  // mouseDrg = false;
  newComponent.mouseMoved(x, y );
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
  // mouseMvd = false;
  // mouseDrg = true;
  //  if (mouseDrg){
  //   newComponent.circlePos = ofVec2f(x, y);
  // }
  newComponent.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
   // mouseMvd = false;
   //  diffPos = newComponent.circlePos - movePos;
   //  float length_x = diffPos.x;
   //  float length_y = diffPos.y;
   //  if (-40 < length_x && length_x < 40 && -40 < length_y && length_y < 40 ){
   //    mouseDrg = true;
   //  }
  newComponent.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  // newComponent.radius = radiusDflt;
  // mouseDrg = false;
  newComponent.mouseReleased(x, y, button);
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
