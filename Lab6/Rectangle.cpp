//
//  Rectangle.cpp
//  Lab6
//
//  Created by Matthew Perry on -0212-2016.
//  Copyright © 2016 Matthew Perry. All rights reserved.
//

#include <iostream>
#include <cmath>

#include "easygl.h"
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(string name, string colour, float xcen, float ycen, float width, float height):Shape(name, colour, xcen, ycen), _width(width), _height(height){
#if PRINTDEBUG
    cout << name << '\n';
    cout << colour << '\n';
    cout << "Rectangle CTOR: " << this << '\n';
#endif
}

Rectangle::Rectangle(const Rectangle& that){
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
    Shape::print();
    cout << "rectangle width: " << _width << " height: " << _height << '\n';
}


void Rectangle::scale (float scaleFac) {
    _width = _width * scaleFac;
    _height = _height * scaleFac;
}


float Rectangle::computeArea () const {
    return _width * _height;
}


float Rectangle::computePerimeter () const {
    return (2 * _width) + (2 * _height);
}


void Rectangle::draw (easygl* window) const {
    //Gets corner points in x,y reference
    t_point topLeft;
    topLeft.x = getXcen() - _width / 2;
    topLeft.y = getYcen() - _height / 2;
    
    t_point btmRight;
    btmRight.x = getXcen() + _width / 2;
    btmRight.y = getYcen() + _height / 2;
    
    window->gl_setcolor(getColour());
    window->gl_fillrect(topLeft.x, topLeft.y, btmRight.x, btmRight.y);
}


bool Rectangle::pointInside (float x, float y) const {
    //Compares max x,y offset of rectangle to the click location
    t_point centerOffset;//To click location
    centerOffset.x = abs(x - getXcen());
    centerOffset.y = abs(y - getYcen());
    
    bool inShape = ((centerOffset.x < (_width / 2)) && (centerOffset.y < (_height / 2)));//Check if x and y displacement less then width and height, respectively
    
    return inShape;
}
