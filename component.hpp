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
    void draw();

    ofVec2f circlePos;
    // ofVec2f diffPos;
    float radius;
};

#endif /* component_hpp */
