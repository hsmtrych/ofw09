//
//  DrawGrid.cpp
//  0913
//
//  Created by hsmtrychMBA on 2018/09/15.
//

#include "DrawGrid.hpp"

void DrawGrid::draw(){
ofPushStyle();
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofDrawGrid(100.0f, 100.0f, true, false, false, true);
    //ofDrawGrid(float stepSize=1.25f, size_t numberOfSteps, bool labels=false, bool x=true, bool y=true, bool z=true)
    ofPopMatrix();
ofPopStyle();
}