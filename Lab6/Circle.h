//
//  Circle.h
//  Lab6
//
//  Created by Matthew Perry on -0212-2016.
//  Copyright © 2016 Matthew Perry. All rights reserved.
//

#ifndef Circle_h
#define Circle_h

#include <assert.h>

#include "easygl.h"
#include "Shape.h"

#define PRINTDEBUG 1

class Circle : public Shape {
private:
    float _radius;
    
    t_point getVecBetweenPoints (t_point start, t_point end) const;
    float getMagnitude(float x, float y) const;
public:
    Circle(string name, string colour, float xcen, float ycen, float radius);
    Circle(const Circle& that);
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
