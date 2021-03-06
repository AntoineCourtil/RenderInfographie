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
    std::vector<Point3D> textures;

public:
    objmodel(std::vector<Point3D> points_, std::vector<triangle> faces_, std::vector<Point3D> textures_);


    void draw(TGAImage &image, TGAColor color);

    void fill(TGAImage &image);

    void fillWithLight(TGAImage &image, double zbuffer[], TGAImage &texture);
};


#endif //INFOGRAPHIE_OBJMODEL_H
