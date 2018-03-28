//
// Created by antoine on 28/03/18.
//

#ifndef INFOGRAPHIE_LINE_H
#define INFOGRAPHIE_LINE_H


#include <cassert>
#include "../image/tgaimage.h"
#include "Point2D.h"
#include "Point3D.h"


class line {

public:

    line(Point2D p1, Point2D p2, TGAImage &image, TGAColor color);

    line(Point3D p1, Point3D p2, TGAImage &image, TGAColor color);

    static void line1(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

    static void line2(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

    static void line3(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

    static void bresenham(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

    static void bresenhamInteger(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);
};




#endif //INFOGRAPHIE_LINE_H
