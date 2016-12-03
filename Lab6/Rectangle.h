//
//  Rectangle.h
//  Lab6
//
//  Created by Matthew Perry on -0212-2016.
//  Copyright © 2016 Matthew Perry. All rights reserved.
//

#ifndef Rectangle_h
#define Rectangle_h

#include <iostream>
#include <assert.h>

#include "Shape.h"

class Rectangle : public Shape {
private:
public:
    Rectangle();
    Rectangle(const Rectangle& that_);
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
