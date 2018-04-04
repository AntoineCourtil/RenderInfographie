//
// Created by antoine on 28/03/18.
//

#include <cmath>
#include "Point3D.h"

Point3D::Point3D(double coordX, double coordY, double coordZ){
    x = coordX;
    y = coordY;
    z = coordZ;
}

Point3D::Point3D() {}

void Point3D::normalize(){

    double longueur = sqrt(x*x + y*y + z*z);

    x = x / longueur;
    y = y / longueur;
    z = z / longueur;

}

