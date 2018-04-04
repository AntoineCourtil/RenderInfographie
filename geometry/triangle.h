//
// Created by antoine on 28/03/18.
//

#ifndef INFOGRAPHIE_TRIANGLE_H
#define INFOGRAPHIE_TRIANGLE_H


#include "line.h"
#include "Point3D.h"

class triangle {

private:
    Point3D t1;
    Point3D t2;

public:
    triangle(Point3D t0, Point3D t1, Point3D t2);
    static void draw(Point2D t0, Point2D t1, Point2D t2, TGAImage &image, TGAColor color);
    void draw2D(TGAImage &image, TGAColor color);

    void draw(TGAImage &image, TGAColor color);

    Point3D t0;

    void filled2D(TGAImage &image, TGAColor color);

    Point3D barycentric(Point2D P);

    Point3D crossproduct(Point3D v1, Point3D v2);
};


#endif //INFOGRAPHIE_TRIANGLE_H
