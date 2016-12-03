//
//  Polygon.h
//  Lab6
//
//  Created by Matthew Perry on -0212-2016.
//  Copyright © 2016 Matthew Perry. All rights reserved.
//

#ifndef Polygon_h
#define Polygon_h

#include <iostream>
#include <assert.h>

#include "Shape.h"

#define PRINTDEBUG 1

class Polygon : public Shape {
private:
public:
    Polygon();
    Polygon(const Polygon& that_);
    virtual ~Polygon();
    
    //From Shape class
    virtual void print () const;
    virtual void scale (float scaleFac);
    virtual float computeArea () const;
    virtual float computePerimeter () const;
    virtual void draw (easygl* window) const;
    virtual bool pointInside (float x, float y) const;
};

#endif /* Polygon_h */
