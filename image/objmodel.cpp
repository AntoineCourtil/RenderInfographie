//
// Created by antoine on 28/03/18.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
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
        std::cout << "Draw face " << i+1 << std::endl;
    }

}

void objmodel::fillWithLight(TGAImage &image) {

    Point3D light = Point3D(0,0,1);

    std::cout << "faces size : " << faces.size() << std::endl;


    for(int i=0; i<faces.size(); i++){

        Point3D normale = faces.at(i).normale();

        normale.normalize();
        light.normalize();

        //double intensity = ( (normale.x * light.x) + ( normale.y * light.y ) ) / (sqrt(normale.x * normale.x + normale.y * normale.y) + sqrt(light.x * light.x + light.y * light.y));

        double intensity = normale.x * light.x + normale.y * light.y + normale.z * light.z;


        //float intensity = 1;

        if (intensity > 0) {
            faces.at(i).filled2D(image, TGAColor(intensity * 255, intensity * 255, intensity * 255, 255));
//            faces.at(i).draw2D(image, TGAColor(255,0,0,255));
            std::cout << "Draw face " << i << " with itensity : " << intensity << std::endl;
        }
    }

}