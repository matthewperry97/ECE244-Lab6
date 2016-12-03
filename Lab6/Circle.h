//
//  Circle.h
//  Lab6
//
//  Created by Matthew Perry on -0212-2016.
//  Copyright © 2016 Matthew Perry. All rights reserved.
//

#ifndef Circle_h
#define Circle_h

#include <iostream>
#include <assert.h>

#include "Shape.h"

#define PRINTDEBUG 1

class Circle : public Shape {
private:
public:
    Circle();
    Circle(const Circle& that_);
    virtual ~Circle();
    
    //From Shape class
    virtual void print () const;
    virtual void scale (float scaleFac);
    virtual float computeArea () const;
    virtual float computePerimeter () const;
    virtual void draw (easygl* window) const;
    virtual bool pointInside (float x, float y) const;
};

#endif /* Circle_h */
