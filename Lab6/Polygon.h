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

#define PRINTDEBUG 0

class Polygon : public Shape {
private:
    //Variables
    t_point _vertices[100];
    int _numVertices;
    
    //Functions
    t_point getVecBetweenPoints (t_point start, t_point end) const;
    float getMagnitude(float x, float y) const;
public:
    Polygon(string name, string colour, float xcen, float ycen, t_point vertices[100], int numVertices);
    Polygon(const Polygon& that);
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
