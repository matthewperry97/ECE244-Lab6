//
//  Rectangle.cpp
//  Lab6
//
//  Created by Matthew Perry on -0212-2016.
//  Copyright © 2016 Matthew Perry. All rights reserved.
//

#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(){
#if PRINTDEBUG
    cout << "Rectangle CTOR: " << this << '\n';
#endif
}

Rectangle::Rectangle(const Rectangle& that_){
#if PRINTDEBUG
    cout << "Rectangle CCTOR: " << this << '\n';
#endif
}

Rectangle::~Rectangle(){
#if PRINTDEBUG
    cout << "Rectangle DTOR: " << this << '\n';
#endif
}

void Rectangle::print () const {
}


void Rectangle::scale (float scaleFac) {
}


float Rectangle::computeArea () const {
    float area;
    return area;
}


float Rectangle::computePerimeter () const {
    float perimeter = 0;
    float sideLength;
    return perimeter;
}


void Rectangle::draw (easygl* window) const {
}


bool Rectangle::pointInside (float x, float y) const {
    return false;
}
