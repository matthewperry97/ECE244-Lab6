//
//  Rectangle.h
//  Lab6
//
//  Created by Matthew Perry on -0212-2016.
//  Copyright © 2016 Matthew Perry. All rights reserved.
//

#ifndef Rectangle_h
#define Rectangle_h


#include <assert.h>

#include "Shape.h"
#include "easygl.h"

#define PRINTDEBUG 1

class Rectangle : public Shape {
private:
    float _width;
    float _height;
public:    
    Rectangle(string name, string colour, float xcen, float ycen, float width, float height);
    Rectangle(const Rectangle& that);
    virtual ~Rectangle();
    
    //From Shape class
    virtual void print () const;
    virtual void scale (float scaleFac);
    virtual float computeArea () const;
    virtual float computePerimeter () const;
    virtual void draw (easygl* window) const;
    virtual bool pointInside (float x, float y) const;
};

#endif /* Rectangle_h */
