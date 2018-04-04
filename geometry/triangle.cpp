//
// Created by antoine on 28/03/18.
//

#include "triangle.h"
#include <iostream>
#include <cmath>


triangle::triangle(Point3D t0_, Point3D t1_, Point3D t2_) {

    t0 = t0_;
    t1 = t1_;
    t2 = t2_;

//    if (t0.y > t1.y) std::swap(t0, t1);
//    if (t0.y > t2.y) std::swap(t0, t2);
//    if (t1.y > t2.y) std::swap(t1, t2);
}

void triangle::draw(Point2D t0, Point2D t1, Point2D t2, TGAImage &image, TGAColor color) {

    if (t0.y > t1.y) std::swap(t0, t1);
    if (t0.y > t2.y) std::swap(t0, t2);
    if (t1.y > t2.y) std::swap(t1, t2);
    line(t0, t1, image, color);
    line(t1, t2, image, color);
    line(t2, t0, image, color);

}

void triangle::draw2D(TGAImage &image, TGAColor color) {

    line(t0, t1, image, color);
    line(t1, t2, image, color);
    line(t2, t0, image, color);

}

void triangle::filled2D(TGAImage &image, TGAColor color) {

    if (t0.y > t1.y) std::swap(t0, t1);
    if (t0.y > t2.y) std::swap(t0, t2);
    if (t1.y > t2.y) std::swap(t1, t2);

    Point2D bboxmin(image.get_width() - 1, image.get_height() - 1);
    Point2D bboxmax(0, 0);
    Point2D clamp(image.get_width() - 1, image.get_height() - 1);

    // Calcul de la bbox min

    bboxmin.x = std::max((const double &)0, std::min(bboxmin.x, t0.x));
    bboxmin.x = std::max((const double &)0, std::min(bboxmin.x, t1.x));
    bboxmin.x = std::max((const double &)0, std::min(bboxmin.x, t2.x));

    bboxmin.y = std::max((const double &)0, std::min(bboxmin.y, t0.y));
    bboxmin.y = std::max((const double &)0, std::min(bboxmin.y, t1.y));
    bboxmin.y = std::max((const double &)0, std::min(bboxmin.y, t2.y));

    // Calcul de la bbox min

    bboxmax.x = std::max(clamp.x, std::max(bboxmax.x, t0.x));
    bboxmax.x = std::max(clamp.x, std::max(bboxmax.x, t1.x));
    bboxmax.x = std::max(clamp.x, std::max(bboxmax.x, t2.x));

    bboxmax.y = std::max(clamp.y, std::max(bboxmax.x, t0.y));
    bboxmax.y = std::max(clamp.y, std::max(bboxmax.x, t1.y));
    bboxmax.y = std::max(clamp.y, std::max(bboxmax.x, t2.y));


    Point2D P;

    bool isPrinted = false;

    for (P.x = bboxmin.x; P.x <= bboxmax.x; P.x++) {
        for (P.y = bboxmin.y; P.y <= bboxmax.y; P.y++) {
            Point3D bc_screen = barycentric(P);
            if (bc_screen.x < 0 || bc_screen.y < 0 || bc_screen.z < 0) continue;
            image.set(P.x, P.y, color);
            isPrinted = true;
        }
    }

    if(!isPrinted) std::cout << "NOT PRINTED " << std::endl;

}

Point3D triangle::barycentric(Point2D P) {
    Point3D u = crossproduct(Point3D(t2.x-t0.x, t1.x-t0.x, t0.x-P.x), Point3D(t2.y-t0.y, t1.y-t0.y, t0.y-P.y));


    if (std::abs(u.z) < 1){
        return Point3D(-1.d, 1.d, 1.d);
    }

    return Point3D(1.f - (u.x + u.y) / u.z, u.y / u.z, u.x / u.z);


}

Point3D triangle::crossproduct(Point3D v1,Point3D v2) {

    Point3D cross_p = Point3D();

    cross_p.x = (v1.y * v2.z) - (v1.z * v2.y);

    cross_p.y = -((v1.x * v2.z) - (v1.z * v2.x));

    cross_p.z = (v1.x * v2.y) - (v1.y * v2.x);

    return cross_p;

}


Point3D triangle::normale(){
    Point3D normale = Point3D();

    Point3D u = Point3D(t1.x-t0.x, t1.y-t0.y, t1.z-t0.z);
    Point3D v = Point3D(t2.x-t0.x, t2.y-t0.y, t2.z-t0.z);

//    normale.x = (t1.y-t0.y) * (t2.z-t0.z) - (t1.z -t0.z) * (t2.y - t0.y);
//    normale.y = (t1.z-t0.z) * (t2.x-t0.x) - (t1.x -t0.x) * (t2.z - t0.z);
//    normale.z = (t1.x-t0.x) * (t2.y-t0.y) - (t1.y -t0.y) * (t2.x - t0.x);

    return crossproduct(u,v);
}

