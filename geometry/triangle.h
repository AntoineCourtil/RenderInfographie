//
// Created by antoine on 28/03/18.
//

#ifndef INFOGRAPHIE_TRIANGLE_H
#define INFOGRAPHIE_TRIANGLE_H


#include "line.h"

class triangle {

public:
    triangle(vector t0, vector t1, vector t2, TGAImage &image, TGAColor color);

    void filledTriangle(vector t0, vector t1, vector t2, TGAImage &image, TGAColor color);
};


#endif //INFOGRAPHIE_TRIANGLE_H
