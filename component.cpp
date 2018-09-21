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
    radius = 50;
    angle = 0;
    angleDiff = 0;
    scale = 10;
    scaleDiff = 1;

 //bool
    mouseMvd = false;
    mouseDrg = false;
    mouseAngle = false;
    mouseScale = false;
    keyPressedR = false;
    keyPressedS = false;

  //string
    mouseMvdString = "false";

    circlePos = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);

}

void component::update(){

  //角度
  if (keyPressedR && mouseAngle) {
    angleDiff = angleGet.y - angleSet.y;
    angle = angleRelease + angleDiff;
    if (angleSet.x < circlePos.x) {
      angle = angleRelease - angleDiff;
    }
  }

  //サイズ
  if (keyPressedS && mouseScale) {
    scaleDiff = scaleGet.x - scaleSet.x;
    scale = scaleRelease + scaleDiff;
    if (scaleSet.x < circlePos.x) {
      scale = scaleRelease - scaleDiff;
    }
  }

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

}

void component::draw(){

ofPushMatrix();
ofTranslate(circlePos.x, circlePos.y);
ofRotateZ(360.0 * angle / ofGetHeight() );
ofScale(scale*0.1, scale*0.1, 1.0);

  ofSetHexColor(hexCol);
  ofDrawRectangle(0,0, radius, radius);
  // ofDrawCircle(circlePos.x, circlePos.y, radius*2);

ofPopMatrix();
}

void component::keyPressed(int key){
    switch (key) {
      case 'r' :
        keyPressedR = true;
        break;
      case 's' :
        keyPressedS = true;
        break;
      case 'f' :
        // ofSetFullscreen(true);
        ofSetWindowShape(1440, 900);
        break;
    }
}
void component::keyReleased(int key){
    switch (key) {
      case 'r' :
        keyPressedR = false;
        mouseAngle = false;
        angleRelease = angle;
        break;
      case 's' :
        keyPressedS = false;
        mouseScale = false;
        scaleRelease = scale;
        break;
      case 'f' :
        ofSetWindowShape(1024, 768);
        break;
    }
}

void component::mouseMoved(int x, int y ){
  mouseMvd = true;
  mouseDrg = false;
  movePos = ofVec2f(x, y);

    diffPos = circlePos - movePos;
    float length_x = diffPos.x;
    float length_y = diffPos.y;
    float size = radius/2 * (scale*0.1);
    if (-size < length_x && length_x < size && -size < length_y && length_y < size ){
      mouseMvd = false;
    }
}

void component::mouseDragged(int x, int y, int button){
  mouseMvd = false;
   if (mouseDrg){
    movePos = ofVec2f(x, y);
    circlePos = ofVec2f(x, y);
  } else if (keyPressedR) {
    mouseAngle = true;
    angleGet = ofVec2f(x, y);
  } else if (keyPressedS) {
    mouseScale = true;
    scaleGet = ofVec2f(x, y);
  }
}

void component::mousePressed(int x, int y, int button){
    mouseMvd = false;
    diffPos = circlePos - movePos;
    float length_x = diffPos.x;
    float length_y = diffPos.y;
    float size = radius/2 * (scale*0.1);
    if (-size < length_x && length_x < size && -size < length_y && length_y < size ){
      mouseDrg = true;
    }

  if (keyPressedR) {
    angleSet = ofVec2f(x, y);
  } else if (keyPressedS) {
    scaleSet = ofVec2f(x, y);
  }
}

void component::mouseReleased(int x, int y, int button){
  mouseDrg = false;
  mouseAngle = false;
  mouseScale = false;
}
