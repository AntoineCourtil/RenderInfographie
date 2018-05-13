//
// Created by antoine on 28/03/18.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "objmodel.h"

objmodel::objmodel(std::vector<Point3D> points_, std::vector<triangle> faces_, std::vector<Point3D> textures_){
    points = points_;
    faces = faces_;
    textures = textures_;
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

void objmodel::fillWithLight(TGAImage &image, double zbuffer[], TGAImage &texture) {

    Point3D light = Point3D(0,0,1);

    std::cout << std::endl << std::endl << "number of faces for the model : " << faces.size() << std::endl;

    std::cout << std::endl << "Progress..." << std::endl;

    for(int i=0; i<faces.size(); i++){

        if(i%100 == 0 && i > 0) std::cerr << "=";

        Point3D normale = faces.at(i).normale();

        normale.normalize();
        light.normalize();

        //double intensity = ( (normale.x * light.x) + ( normale.y * light.y ) ) / (sqrt(normale.x * normale.x + normale.y * normale.y) + sqrt(light.x * light.x + light.y * light.y));

//        int intensity = 1;
        double intensity = normale.x * light.x + normale.y * light.y + normale.z * light.z;


        //float intensity = 1;

        if (intensity > 0) {
//            faces.at(i).filled2D(image, TGAColor(intensity * 255, intensity * 255, intensity * 255, 255));
//            std::cout << intensity << std::endl;
            faces.at(i).filled2DZBuffer(image, texture, zbuffer, intensity, textures);
//            faces.at(i).draw2D(image, TGAColor(255,0,0,255));
//            std::cout << "Draw face " << i << " with itensity : " << intensity << std::endl;
        }
    }

}