//
// Created by antoine on 28/03/18.
//

#ifndef INFOGRAPHIE_LINE_H
#define INFOGRAPHIE_LINE_H


#include <cassert>
#include "../tgaimage.h"
#include "vector.h"


class line {

public:

    line(vector p1, vector p2, TGAImage &image, TGAColor color);

    static void line1(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

    static void line2(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

    static void line3(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

    static void bresenham(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

    static void bresenhamInteger(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);
};




#endif //INFOGRAPHIE_LINE_H
