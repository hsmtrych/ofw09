//
//  component.cpp
//  0913
//
//  Created by hsmtrychMBA on 2018/09/14.
//

#include "component.hpp"

component::component(){

    ofVec2f getCenter = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
    mouseDragPos = getCenter;
    drawingPos = getCenter;
    drawedPos = getCenter;
    mousePressPos = getCenter;

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
    scaleRelease = scale;

 //bool
    mouseMvd = false;
    mouseDrg = false;
    mouseAngle = false;
    mouseScale = false;
    keyPressedR = false;
    keyPressedS = false;

  //string
    mouseMvdString = "false";

}

void component::update(){
  //ドラッグ
  // size = drawingPos * (scale*0.1);



  //角度
  if (keyPressedR && mouseAngle) {
    angleDiff = transformDragPos.y - transformPressPos.y;
    angle = angleRelease + angleDiff;
    if (transformPressPos.x < mouseDragPos.x) {
      angle = angleRelease - angleDiff;
    }
  }

  //サイズ
  if (keyPressedS && mouseScale) {
    scaleDiff = transformDragPos.x - transformPressPos.x;
    scale = scaleRelease + scaleDiff;
    if (transformPressPos.x < mouseDragPos.x) {
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
ofTranslate(drawingPos.x, drawingPos.y);
ofRotateZ(360.0 * angle / ofGetHeight() );
ofScale(scale*0.1, scale*0.1, 1.0);

  ofSetHexColor(hexCol);
  ofDrawRectangle(0, 0, radius, radius);
  // ofDrawCircle(mouseDragPos.x, mouseDragPos.y, radius*2);

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
  mouseMovePos = ofVec2f(x, y);

    mouseDiffPos = mouseDragPos - mouseMovePos;
    // testDiffLength = abs(mouseDiffPos) - abs(drawDiffPos);
    // float length_x = testDiffLength.x;
    // float length_y = testDiffLength.y;

    length_x = fabs(mouseDiffPos.x) - fabs(drawDiffPos.x);
    length_y = fabs(mouseDiffPos.y) - fabs(drawDiffPos.y);

    float size = radius/2 * (scale*0.1);
    //
    sized = radius/2 * (scale*0.1);
    //
    if (-size < length_x && length_x < size && -size < length_y && length_y < size ){
      mouseMvd = false;
    }
}

void component::mouseDragged(int x, int y, int button){
  mouseMvd = false;
   if (mouseDrg){
    mouseMovePos = ofVec2f(x, y);
    mouseDragPos = ofVec2f(x, y);
    drawingPos = mouseDragPos + drawDiffPos;
  } else if (keyPressedR) {
    mouseAngle = true;
    transformDragPos = ofVec2f(x, y);
  } else if (keyPressedS) {
    mouseScale = true;
    transformDragPos = ofVec2f(x, y);
  }
}

void component::mousePressed(int x, int y, int button){
    mouseMvd = false;

    // mouseDiffPos = mouseDragPos - mouseMovePos;
    // float length_x = mouseDiffPos.x;
    // float length_y = mouseDiffPos.y;

    mouseDiffPos = mouseDragPos - mouseMovePos;

    length_x = fabs(mouseDiffPos.x) - fabs(drawDiffPos.x);
    length_y = fabs(mouseDiffPos.y) - fabs(drawDiffPos.y);

    float size = radius/2 * (scale*0.1);
    if (-size < length_x && length_x < size && -size < length_y && length_y < size ){
      mouseDrg = true;
    }

  if (keyPressedR) {
    transformPressPos = ofVec2f(x, y);
  } else if (keyPressedS) {
    transformPressPos = ofVec2f(x, y);
  }

  mousePressPos = ofVec2f(x,y);
  drawDiffPos = drawedPos - mousePressPos;
}

void component::mouseReleased(int x, int y, int button){
  mouseDrg = false;
  mouseAngle = false;
  mouseScale = false;

  drawedPos = drawingPos;
}
