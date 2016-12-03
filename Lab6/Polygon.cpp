//
//  Polygon.cpp
//  Lab6
//
//  Created by Matthew Perry on -0212-2016.
//  Copyright © 2016 Matthew Perry. All rights reserved.
//

#include "Polygon.h"

using namespace std;

Polygon::Polygon(){
#if PRINTDEBUG
    cout << "Polygon CTOR: " << this << '\n';
#endif
}

Polygon::Polygon(const Polygon& that_){
#if PRINTDEBUG
    cout << "Polygon CCTOR: " << this << '\n';
#endif
}

Polygon::~Polygon(){
#if PRINTDEBUG
    cout << "Polygon DTOR: " << this << '\n';
#endif
}

void Polygon::print () const {
}


void Polygon::scale (float scaleFac) {
}


float Polygon::computeArea () const {
    float area;
    return area;
}


float Polygon::computePerimeter () const {
    float perimeter = 0;
    float sideLength;
    return perimeter;
}


void Polygon::draw (easygl* window) const {
}


bool Polygon::pointInside (float x, float y) const {
    return false;
}
