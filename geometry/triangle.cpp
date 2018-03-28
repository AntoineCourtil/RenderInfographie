//
// Created by antoine on 28/03/18.
//

#include "triangle.h"
#include <iostream>
#include <math.h>

triangle::triangle(Vec2i t0, Vec2i t1, Vec2i t2, TGAImage &image, TGAColor color) {

    if (t0.y>t1.y) std::swap(t0, t1);
    if (t0.y>t2.y) std::swap(t0, t2);
    if (t1.y>t2.y) std::swap(t1, t2);
    line(t0, t1, image, color);
    line(t1, t2, image, color);
    line(t2, t0, image, color);

}
