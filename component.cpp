//
//  component.cpp
//  0913
//
//  Created by hsmtrychMBA on 2018/09/14.
//

#include "component.hpp"

void component::setup(){
    colR = 0xff0000;
    colG = 0x00ff00;
    colB = 0x0000ff;
    hexCol = colB;

    radius = radiusDflt;
    radiusExp = 0.8;

    mouseMvd = false;
    mouseDrg = false;
    mouseMvdString = "false";
}

void component::update(){
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
    if (radius <= radiusDflt*2 ){
      radius += radiusExp;
    }
  }else {
    if (radius >= radiusDflt ){
      radius -= radiusExp;
    }
  }
}

void component::draw(){
  ofSetHexColor(hexCol);
  ofDrawRectangle(circlePos.x,circlePos.y, radius*2, radius*2);
  // ofDrawCircle(circlePos.x, circlePos.y, radius*2);
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
}

void component::mousePressed(int x, int y, int button){
    mouseMvd = false;
    diffPos = circlePos - movePos;
    float length_x = diffPos.x;
    float length_y = diffPos.y;
    if (-radiusDflt < length_x && length_x < radiusDflt && -radiusDflt < length_y && length_y < radiusDflt ){
      mouseDrg = true;
    }
}

void component::mouseReleased(int x, int y, int button){
  mouseDrg = false;
}
