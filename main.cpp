#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <math.h>
#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);
const TGAColor green   = TGAColor(0, 255,   0,   255);
const TGAColor blue   = TGAColor(0, 0,   255,   255);
const TGAColor yellow   = TGAColor(255, 255, 0,   255);
const TGAColor pink   = TGAColor(255, 0, 255,   255);
const TGAColor cyan   = TGAColor(0, 255, 255,   255);


/**
* Méthode 1
**/
void line1(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) { 
    for (float t=0.; t<1.; t+=.01) { 
        int x = x0*(1.-t) + x1*t; 
        int y = y0*(1.-t) + y1*t; 
        image.set(x, y, color);
    } 
}

/**
* Méthode 2
**/
void line2(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) { 
    for (int x=x0; x<=x1; x++) { 
        float t = (x-x0)/(float)(x1-x0); 
        int y = y0*(1.-t) + y1*t; 
        image.set(x, y, color); 
    } 
}

/**
* Méthode 3
**/
void line3(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
	bool steep = false;

	if (std::abs(x0-x1) < std::abs(y0-y1)) { 
        std::swap(x0, y0); 
        std::swap(x1, y1); 
        steep = true; 
    } 
    if (x0 > x1) { 
        std::swap(x0, x1); 
        std::swap(y0, y1); 
    } 
    for (int x = x0; x <= x1; x++) { 
        float t = (x-x0)/(float)(x1-x0); 
        int y = y0*(1.-t) + y1*t; 
        if (steep) { 
            image.set(y, x, color); 
        } else { 
            image.set(x, y, color); 
        } 
    } 
}

/**
* Méthode 4
**/
void bresenham(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
	bool steep = false; 
    if (std::abs(x0-x1)<std::abs(y0-y1)) { 
        std::swap(x0, y0); 
        std::swap(x1, y1); 
        steep = true; 
    } 
    if (x0>x1) { 
        std::swap(x0, x1); 
        std::swap(y0, y1); 
    }

    int dx = x1 - x0;
    int dy = y1 - y0;
    float derror = std::abs(dy / float(dx)); 
    float error = 0; 
    int y = y0; 

    for (int x = x0; x <= x1; x++) { 
        if (steep) { 
            image.set(y, x, color); 
        } else { 
            image.set(x, y, color); 
        } 
        error += derror; 
        if (error > .5) { 
            y += (y1 > y0 ? 1 : -1); 
            error -= 1.; 
        } 
    } 
}

/**
* Méthode 5
**/
void bresenhamInteger(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
	bool steep = false; 
    if (std::abs(x0-x1)<std::abs(y0-y1)) { 
        std::swap(x0, y0); 
        std::swap(x1, y1); 
        steep = true; 
    } 
    if (x0>x1) { 
        std::swap(x0, x1); 
        std::swap(y0, y1); 
    }

    int dx = x1 - x0;
    int dy = y1 - y0;
    float derror = std::abs(dy * 2); 
    float error = 0; 
    int y = y0; 

    for (int x = x0; x <= x1; x++) { 
        if (steep) { 
            image.set(y, x, color); 
        } else { 
            image.set(x, y, color); 
        } 
        error += derror; 
        if (error > dx) { 
            y += (y1 > y0 ? 1 : -1); 
            error -= dx*2.; 
        } 
    } 
}


int main(int argc, char** argv) {
    TGAImage image(100, 100, TGAImage::RGB);
    image.set(52, 41, white);

    line1(0,0,50,50, image, red);
    line2(10,80,80,10, image, green);
    line3(10,90,80,70, image, blue);
    bresenham(05,30,95,20, image, yellow);
    bresenhamInteger(0,50,90,90, image, pink);


    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");

    return 0;
}