//
// Created by antoine on 28/03/18.
//

#include <iostream>
#include <cstdlib>
#include "objmodel.h"

objmodel::objmodel(std::vector<Point3D> points_, std::vector<triangle> faces_){
    points = points_;
    faces = faces_;
}

objmodel::objmodel(){ }

void objmodel::draw(TGAImage &image, TGAColor color) {


    for(int i=0; i<faces.size(); i++){
        faces.at(i).draw2D(image, TGAColor(rand()%255, rand()%255, rand()%255, 255));
    }

}

void objmodel::fill(TGAImage &image) {


    for(int i=0; i<faces.size(); i++){
        faces.at(i).filled2D(image, TGAColor(rand()%255, rand()%255, rand()%255, 255));
    }

}