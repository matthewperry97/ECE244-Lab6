//
//  Circle.cpp
//  Lab6
//
//  Created by Matthew Perry on -0212-2016.
//  Copyright © 2016 Matthew Perry. All rights reserved.
//

#include <iostream>
#include <cmath>

#include "easygl.h"
#include "Circle.h"

using namespace std;

Circle::Circle(string name, string colour, float xcen, float ycen, float radius):Shape (name, colour, xcen, ycen), _radius(radius){
#if PRINTDEBUG
    cout << "Circle CTOR: " << this << '\n';
#endif
}

Circle::Circle(const Circle& that){
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
    Shape::print();
    cout << "circle radius: " << _radius << '\n';
}


void Circle::scale (float scaleFac) {
    _radius = _radius * scaleFac;
}


float Circle::computeArea () const {
    return PI * pow(_radius, 2);//πr^2
}


float Circle::computePerimeter () const {
    return 2 * PI * _radius;//2πr
}


void Circle::draw (easygl* window) const {
    window->gl_setcolor(getColour());
    window->gl_fillarc(getXcen(), getYcen(), _radius, 0, 360);
}


bool Circle::pointInside (float x, float y) const {
    t_point center;
    center.x = getXcen();
    center.y = getYcen();
    
    t_point click;
    click.x = x;
    click.y = y;
    
    t_point distanceToPt = getVecBetweenPoints(center, click);
    
    bool inShape = getMagnitude(distanceToPt.x, distanceToPt.y) < _radius;//Compare vector magnitude to radius
    
    return inShape;
}

float Circle::getMagnitude(float x, float y) const{
    return sqrt(pow(x, 2) + pow(y, 2));
}

t_point Circle::getVecBetweenPoints (t_point start, t_point end) const{
    t_point vec;
    vec.x = end.x - start.x;
    vec.y = end.y - start.y;
    
    return  vec;
}
