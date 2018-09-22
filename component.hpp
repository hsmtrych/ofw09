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

    ofVec2f mouseMovePos, mouseDragPos, mouseDiffPos, mousePressPos;
    float radius;
    // ofVec2f angleGet,angleSet;
    // ofVec2f scaleGet,scaleSet;
    ofVec2f drawingPos, drawedPos, drawDiffPos;
    ofVec2f transformDragPos, transformPressPos;
    float angle,angleDiff,angleRelease;
    float scale,scaleDiff,scaleRelease;

    ofColor circleCol;
    int hexCol,colR,colG,colB;

    bool mouseMvd,mouseDrg,mouseAngle,mouseScale;
    bool keyPressedR,keyPressedS;
    string mouseMvdString;
    float sized;
    float length_x, length_y;

};

#endif /* component_hpp */
