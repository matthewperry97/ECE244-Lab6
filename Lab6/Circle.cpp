//
//  Circle.cpp
//  Lab6
//
//  Created by Matthew Perry on -0212-2016.
//  Copyright © 2016 Matthew Perry. All rights reserved.
//

#include "Circle.h"

using namespace std;

Circle::Circle(){
#if PRINTDEBUG
    cout << "Circle CTOR: " << this << '\n';
#endif
}

Circle::Circle(const Circle& that_){
#if PRINTDEBUG
    cout << "Circle CCTOR: " << this << '\n';
#endif
}

Circle::~Circle(){
#if PRINTDEBUG
    cout << "Circle DTOR: " << this << '\n';
#endif
}

void Circle::print () const {
}


void Circle::scale (float scaleFac) {
}


float Circle::computeArea () const {
    float area;
    return area;
}


float Circle::computePerimeter () const {
    float perimeter = 0;
    float sideLength;
    return perimeter;
}


void Circle::draw (easygl* window) const {
}


bool Circle::pointInside (float x, float y) const {
    return false;
}
