//
//  component.cpp
//  0913
//
//  Created by hsmtrychMBA on 2018/09/14.
//

#include "component.hpp"

component::component(){
  //int
    colR = 0xff0000;
    colG = 0x00ff00;
    colB = 0x0000ff;
    hexCol = colB;

  //float
    radiusDflt = 25;
    radius = radiusDflt;
    radiusExp = 2;
    angle = 0;
    angleDiff = 0;

 //bool
    mouseMvd = false;
    mouseDrg = false;
    keyPressedR = false;
    mouseAngle = false;

  //string
    mouseMvdString = "false";

    circlePos = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);

}

void component::update(){

  //角度
  if (keyPressedR && mouseAngle) {
    angleDiff = angleGet.y - angleSet.y;
    angle = angleRelease + angleDiff;
    if (angleSet.x < ofGetWidth() / 2) {
      angle = angleRelease - angleDiff;
    }
  }

  // angle += 0.1;
  // if (angle >= 360) angle = 0;

  //カラー
  if (mouseMvd && !mouseDrg){
    hexCol = colG;
    mouseMvd = false;
    mouseMvdString = "true";
  }else if(mouseDrg && !mouseMvd) {
    hexCol = colR;
    mouseMvd = false;
    mouseMvdString = "false";
  }else {
    hexCol = colB;
    mouseMvdString = "false";
  }

  //サイズ
  if(mouseDrg && !mouseMvd) {
    if (radius <= radiusDflt*1.2 ){
      radius += radiusExp;
    }
  }else {
    if (radius >= radiusDflt ){
      radius -= radiusExp;
    }
  }
}

void component::draw(){

ofPushMatrix();
ofTranslate(circlePos.x, circlePos.y);
ofRotateZ(360.0 * angle / ofGetHeight() );

  ofSetHexColor(hexCol);
  ofDrawRectangle(0,0, radius*2, radius*2);
  // ofDrawCircle(circlePos.x, circlePos.y, radius*2);

ofPopMatrix();
}

void component::keyPressed(int key){
    if (key =='r') {
      keyPressedR = true;
    }
}
void component::keyReleased(int key){
  if (key =='r') {
    keyPressedR = false;
    mouseAngle = false;
    angleRelease = angle;
  }
}

void component::mouseMoved(int x, int y ){
  mouseMvd = true;
  mouseDrg = false;
  movePos = ofVec2f(x, y);

    diffPos = circlePos - movePos;
    float length_x = diffPos.x;
    float length_y = diffPos.y;
    if (-radiusDflt < length_x && length_x < radiusDflt && -radiusDflt < length_y && length_y < radiusDflt ){
      mouseMvd = false;
    }
}

void component::mouseDragged(int x, int y, int button){
  mouseMvd = false;
   if (mouseDrg){
    movePos = ofVec2f(x, y);
    circlePos = ofVec2f(x, y);
  }
  if (keyPressedR) {
    mouseAngle = true;
    angleGet = ofVec2f(x, y);
  }
}

void component::mousePressed(int x, int y, int button){
    mouseMvd = false;
    diffPos = circlePos - movePos;
    float length_x = diffPos.x;
    float length_y = diffPos.y;
    if (-radiusDflt < length_x && length_x < radiusDflt && -radiusDflt < length_y && length_y < radiusDflt ){
      mouseDrg = true;
    }

  if (keyPressedR) {
    angleSet = ofVec2f(x, y);
  }
}

void component::mouseReleased(int x, int y, int button){
  mouseDrg = false;
  mouseAngle = false;
}
