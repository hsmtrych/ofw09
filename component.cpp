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

    mouseMvd = false;
    mouseDrg = false;
    mouseMvdString = "false";
}

void component::update(){
  if (mouseMvd && !mouseDrg){
    hexCol = colG;
    mouseMvdString = "true";
    mouseMvd = false;
  }else if(mouseDrg && !mouseMvd) {
    hexCol = colR;
    radius = 30;
    mouseMvdString = "false";
    mouseMvd = false;
  }else {
    hexCol = colB;
    mouseMvdString = "false";
  }
}

void component::draw(){
  ofSetHexColor(hexCol);
  ofDrawCircle(circlePos.x, circlePos.y, radius*2);
}

void component::mouseMoved(int x, int y ){
  mouseMvd = true;
  mouseDrg = false;

  movePos = ofVec2f(x, y);
}

void component::mouseDragged(int x, int y, int button){
  mouseMvd = false;
   if (mouseDrg){
    circlePos = ofVec2f(x, y);
  }
}

void component::mousePressed(int x, int y, int button){
    mouseMvd = false;
    diffPos = circlePos - movePos;
    float length_x = diffPos.x;
    float length_y = diffPos.y;
    if (-40 < length_x && length_x < 40 && -40 < length_y && length_y < 40 ){
      mouseDrg = true;
    }
}

void component::mouseReleased(int x, int y, int button){
  radius = radiusDflt;
  mouseDrg = false;
}