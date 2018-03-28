//
// Created by antoine on 28/03/18.
//

#include "triangle.h"
#include <iostream>
#include <math.h>

triangle::triangle(vector t0, vector t1, vector t2, TGAImage &image, TGAColor color) {

    if (t0.y>t1.y) std::swap(t0, t1);
    if (t0.y>t2.y) std::swap(t0, t2);
    if (t1.y>t2.y) std::swap(t1, t2);
    line(t0, t1, image, color);
    line(t1, t2, image, color);
    line(t2, t0, image, color);

}


void triangle::filledTriangle(vector t0, vector t1, vector t2, TGAImage &image, TGAColor color) {
    if (t0.y>t1.y) std::swap(t0, t1);
    if (t0.y>t2.y) std::swap(t0, t2);
    if (t1.y>t2.y) std::swap(t1, t2);

    int total_height = t2.y - t0.y;
}