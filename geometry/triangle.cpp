//
// Created by antoine on 28/03/18.
//

#include "triangle.h"
#include <iostream>
#include <math.h>


triangle::triangle(Point3D t0_, Point3D t1_, Point3D t2_) {

    t0 = t0_;
    t1 = t1_;
    t2 = t2_;

    if (t0.y>t1.y) std::swap(t0, t1);
    if (t0.y>t2.y) std::swap(t0, t2);
    if (t1.y>t2.y) std::swap(t1, t2);
}

void triangle::draw(Point2D t0, Point2D t1, Point2D t2, TGAImage &image, TGAColor color) {

    if (t0.y>t1.y) std::swap(t0, t1);
    if (t0.y>t2.y) std::swap(t0, t2);
    if (t1.y>t2.y) std::swap(t1, t2);
    line(t0, t1, image, color);
    line(t1, t2, image, color);
    line(t2, t0, image, color);

}

void triangle::draw2D(TGAImage &image, TGAColor color) {

    line(t0, t1, image, color);
    line(t1, t2, image, color);
    line(t2, t0, image, color);

}


