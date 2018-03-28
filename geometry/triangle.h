//
// Created by antoine on 28/03/18.
//

#ifndef INFOGRAPHIE_TRIANGLE_H
#define INFOGRAPHIE_TRIANGLE_H


#include "line.h"

class triangle {

public:
    triangle(vec<2, int> t0, vec<2, int> t1, vec<2, int> t2, TGAImage &image, TGAColor color);
};


#endif //INFOGRAPHIE_TRIANGLE_H
