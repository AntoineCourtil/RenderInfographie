//
// Created by antoine on 28/03/18.
//

#ifndef INFOGRAPHIE_OBJMODEL_H
#define INFOGRAPHIE_OBJMODEL_H


#include <vector>
#include "../geometry/Point3D.h"
#include "../geometry/triangle.h"

class objmodel {
private:

    objmodel();

    std::vector<Point3D> points;
    std::vector<triangle> faces;

public:
    objmodel(std::vector<Point3D> points_, std::vector<triangle> faces_);


    void draw(TGAImage &image, TGAColor color);
};


#endif //INFOGRAPHIE_OBJMODEL_H
