//
//  Polygon.cpp
//  Lab6
//
//  Created by Matthew Perry on -0212-2016.
//  Copyright © 2016 Matthew Perry. All rights reserved.
//

#include <iostream>
#include <cmath>

#include "easygl.h"
#include "Polygon.h"

using namespace std;

Polygon::Polygon(string name, string colour, float xcen, float ycen, t_point vertices[100], int numVertices):Shape(name, colour, xcen, ycen), _numVertices(numVertices) {
#if PRINTDEBUG
    cout << "Polygon CTOR: " << this << '\n';
#endif
    
    for (int index = 0; index < 100; index += 1) {
        _vertices[index] = vertices[index];
    }
}

Polygon::Polygon(const Polygon& that){
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
    Shape::print();
    cout << "polygon";
    
    for (int index = 0; index < _numVertices; index += 1) {
        cout << " (" << (_vertices[index].x + getXcen()) << "," << (_vertices[index].y + getYcen()) << ")";
    }
    cout << '\n';
}


void Polygon::scale (float scaleFac) {
    //Move each point out from center by scale factor
    for (int index = 0; index < _numVertices; index += 1) {
        _vertices[index].x *= scaleFac;
        _vertices[index].y *= scaleFac;
    }
}


float Polygon::computeArea () const {
    float area = 0.0;
    
#if 0
    int j = _numVertices-1;  // The last vertex is the 'previous' one to the first
    
    for (int i=0; i<_numVertices; i++)
    {
        area = area +  (_vertices[j].x+_vertices[i].x) * (_vertices[j].y-_vertices[i].y);
        j = i;  //j is previous vertex to i
    }
#else
    for (int index = 0; index < _numVertices; index += 1) {
        //Get current point and next point (first if current is last). Uses general formula to find area
        t_point curr = _vertices[index];
        int nextIndex = (index == (_numVertices - 1)) ? 0:(index + 1);
        t_point next = _vertices[nextIndex];
        area += (curr.x * next.y) - (curr.y * next.x);
    }
#endif
     
    return abs(area) * 0.5;
}


float Polygon::computePerimeter () const {
    float perimeter = 0;
    for (int index = 0; index < _numVertices; index += 1) {
        //Calculate length of segment between current vertice and next vertice
        if (index == (_numVertices - 1)) {//Last point -> next point is first point
            t_point start;
            start.x = _vertices[index].x;
            start.y = _vertices[index].y;
            
            t_point end;
            end.x = _vertices[0].x;
            end.y = _vertices[0].y;
            
            t_point displacement = getVecBetweenPoints(start, end);
            perimeter += getMagnitude(displacement.x, displacement.y);
        }else{
            t_point start;
            start.x = _vertices[index].x;
            start.y = _vertices[index].y;
            
            t_point end;
            end.x = _vertices[index + 1].x;
            end.y = _vertices[index + 1].y;
            
            t_point displacement = getVecBetweenPoints(start, end);
            perimeter += getMagnitude(displacement.x, displacement.y);
        }
    }
    return perimeter;
}


void Polygon::draw (easygl* window) const {
    t_point coords[_numVertices];  // This data type is in easygl_constants.h
    //Gets vertices in x,y coordinates, not reference to center point
    for (int index = 0; index < _numVertices; index += 1) {
        coords[index].x = getXcen() + _vertices[index].x;
        coords[index].y = getYcen() + _vertices[index].y;
    }
    window->gl_setcolor(getColour());
    window->gl_fillpoly(coords, _numVertices);
}


bool Polygon::pointInside (float x, float y) const {
    // Make a point that corresponds to where you clicked. Since all my
    // vertices are relative to the triangle center, it is more convenient
    // to also shift the click point so it is an offset from the triangle
    // center.
    t_point click;
    click.x = x - getXcen();
    click.y = y - getYcen();
    
    // The test is that a horizontal line (ray) from x = -infinity to the click point
    // will cross (intersect) only one side of triangle to the left of the
    // click point.  If the point is above or below the triangle, the ray will not
    // intersect any triangle sides. If the point is to the left of the triangle
    // the ray will also not intersect any sides to the left of the point.
    // If the point is to the right of the triangle, the ray will intersect
    // two sides of the triangle to its left. Only if the point is inside the
    // triangle will the ray intersect exactly one side to the left of the point.
    
    t_point vecOfSide;
    float distanceAlongVector, yDistance;
    int endIndex;
    int sidesToLeft = 0;
    
    for (int istart = 0; istart < _numVertices; istart += 1) {
        endIndex = (istart + 1) % _numVertices; // Next vertex after istart
        vecOfSide = getVecBetweenPoints (_vertices[istart], _vertices[endIndex]);
        yDistance = (click.y - _vertices[istart].y);
        if (vecOfSide.y != 0) {
            distanceAlongVector = yDistance / vecOfSide.y;
        }
        else if (yDistance == 0) {
            distanceAlongVector = 0;
        }
        else {
            distanceAlongVector = 1e10; // Really infinity, but this is big enough
        }
        
        // We intersect this side if the distance (scaling) along the side vector to
        // get to our "click" y point is between 0 and 1.  Count the first
        // endpoint of the side as being part of the line (distanceAlongVector = 0)
        // but don't count the second endPoint; we'll intersect that point later
        // when we check the next side.
        if (distanceAlongVector >= 0 && distanceAlongVector < 1) {
            float xIntersection = _vertices[istart].x + vecOfSide.x * distanceAlongVector;
            if (xIntersection <= click.x )
                sidesToLeft += 1;
        }
    }
    
    return (sidesToLeft == 1);
}

float Polygon::getMagnitude(float x, float y) const{
    return sqrt(pow(x, 2) + pow(y, 2));
}

t_point Polygon::getVecBetweenPoints (t_point start, t_point end) const{
    t_point vec;
    vec.x = end.x - start.x;
    vec.y = end.y - start.y;
    
    return  vec;
}
