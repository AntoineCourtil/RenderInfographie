#include <limits>
#include "image/tgaimage.h"
#include "geometry/line.h"
#include "geometry/triangle.h"
#include "image/objfile.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);
const TGAColor green   = TGAColor(0, 255,   0,   255);
const TGAColor blue   = TGAColor(0, 0,   255,   255);
const TGAColor yellow   = TGAColor(255, 255, 0,   255);
const TGAColor pink   = TGAColor(255, 0, 255,   255);
const TGAColor cyan   = TGAColor(0, 255, 255,   255);







int main(int argc, char** argv) {

    int width = 1000;
    int height = 1000;

    TGAImage image(width, height, TGAImage::RGB);
    TGAImage image2(width, height, TGAImage::RGB);
//    image.set(52, 41, white);

//    line::line1(0,0,50,50, image, red);
//    line::line2(10,80,80,10, image, green);
//    line::line3(10,90,80,70, image, blue);
//    line::bresenham(05,30,95,20, image, yellow);
//    line::bresenhamInteger(0,50,90,90, image, pink);

//    triangle triangle1 = triangle(Point3D(10, 70, 0), Point3D(100, 700, 0), Point3D(500, 300, 0));
//    triangle1.draw2D(image, cyan);
//    triangle1.filled2D(image, red);


    //init zbuffer
    double zbuffer[width*height];

    for (int i=0; i<width*height; i++) {
        zbuffer[i] = std::numeric_limits<int>::min();
    }



    objmodel model = objfile::loadfile(const_cast<char *>("res/african_head.obj"));
    model.fillWithLight(image, zbuffer);


    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");

    model.fillWithLight(image2);
    image2.flip_vertically();
    image2.write_tga_file("output2.tga");

    return 0;
}