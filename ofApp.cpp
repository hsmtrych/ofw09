#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetCircleResolution(64);
    ofHideCursor(); //マウスカーソル非表示
    ofSetRectMode(OF_RECTMODE_CENTER); //矩形の中心が原点

  //bool
    keyPressedR = false;
}

//--------------------------------------------------------------
void ofApp::update(){
  // float angle = 360.0 * mouseY / ofGetHeight();
  if (keyPressedR) {
    newComponent.angleDiff = mouseY - angleRelease;
    newComponent.angle = angleSet;

  } else if ((keyPressedR && newComponent.mouseMvd)) {

    angleSave = ofGetPreviousMouseY();
    newComponent.angle = mouseY - ofGetPreviousMouseY();
  } else {
    newComponent.angle = angleRelease;
  }

  newComponent.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  newComponent.draw();
  newGrid.draw();


  //変数確認
  ofSetHexColor(0xffffff);
  ofDrawCircle(minCursor.x,minCursor.y, 2);
  // ログの表示
  ofSetHexColor(0xffffff);
  string info;
  info = "FPS = " + ofToString(ofGetFrameRate(), 2) + "\n";
  info += "movePos.x : " + ofToString(newComponent.movePos.x) + "\n";
  info += "movePos.y : " + ofToString(newComponent.movePos.y) + "\n";
  info += "mouseMvd : " + ofToString(newComponent.mouseMvdString) + "\n";
  info += "circlePos.x : " + ofToString(newComponent.circlePos.x) + "\n";
  info += "circlePos.y : " + ofToString(newComponent.circlePos.y) + "\n";
  info += "diffPos.x : " + ofToString(newComponent.diffPos.x) + "\n";
  info += "diffPos.y : " + ofToString(newComponent.diffPos.y) + "\n";
  info += "mouseY : " + ofToString(mouseY) + "\n";
  info += "angleSet : " + ofToString(angleSet) + "\n";
  info += "angleRelease : " + ofToString(angleRelease) + "\n";
  // info += "angleAdd : " + ofToString(newComponent.angleAdd) + "\n";
  info += "angleDiff : " + ofToString(newComponent.angleDiff) + "\n";
  info += "angle : " + ofToString(newComponent.angle) + "\n";
  info += "angleSave : " + ofToString(angleSave) + "\n";
  ofDrawBitmapString(info, 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key =='r') {
      keyPressedR = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
  if (key =='r') {
    keyPressedR = false;
    angleRelease = mouseY;
  }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
  newComponent.mouseMoved(x, y );
  minCursor = ofVec2f(x,y);

  if (keyPressedR) {
    angleSet = y;
  }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
  newComponent.mouseDragged(x, y, button);
  minCursor = ofVec2f(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  newComponent.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
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
