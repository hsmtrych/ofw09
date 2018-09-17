//
//  component.hpp
//  0913
//
//  Created by hsmtrychMBA on 2018/09/14.
//

#ifndef component_hpp
#define component_hpp

#include <stdio.h>

#pragma once
#include "ofMain.h"
class component {
public:
    // void setup();
    component();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

    ofVec2f movePos, circlePos, diffPos;
    ofVec2f angleGet,angleSet;
    float radius,radiusDflt,radiusExp;
    float angle,angleDiff,angleRelease;
    ofColor circleCol;
    int hexCol,colR,colG,colB;
    bool mouseMvd,mouseDrg,keyPressedR,mouseAngle;
    string mouseMvdString;
};

#endif /* component_hpp */
