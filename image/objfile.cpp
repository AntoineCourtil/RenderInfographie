//
// Created by antoine on 28/03/18.
//

#include <sstream>
#include <vector>
#include <cstdlib>
#include "objfile.h"

using namespace std;

objmodel objfile::loadfile(char *fileName) {
    string line;
    string lineType, x, y, z, t0, t1, t2, t0_, t1_, t2_;

    std::vector<Point3D> vertexs;
    std::vector<Point3D> textures;
    std::vector<triangle> faces;

    ifstream myfile(fileName);
//    cout << fileName << endl;
    while (!myfile.eof()) {
        getline(myfile, line);
//        cout << line.size() << endl;
        std::istringstream iss(line);

        //lecture des Point3D
        if (line[0] == 'v' & line[1] == ' ') {

            iss >> lineType >> x >> y >> z;
//            cout << x << "\t" << y << "\t" << z << endl;

            Point3D point = Point3D(std::atof(x.c_str()) * 300 + 500, std::atof(y.c_str()) * 300 + 500,
                                    std::atof(z.c_str()) * 300 + 500);
            vertexs.push_back(point);
//            cout << x << "\t" << std::atof(x.c_str()) << "\t" << point.x << endl;
        }

        //lecture des faces
        if (line[0] == 'f' & line[1] == ' ') {
            iss >> lineType >> t0 >> t1 >> t2;

            t0_ = t0.substr(0, t0.find("/"));
            t1_ = t1.substr(0, t1.find("/"));
            t2_ = t2.substr(0, t2.find("/"));

            t0.erase(0, t0.find("/") + 1);
            t1.erase(0, t1.find("/") + 1);
            t2.erase(0, t2.find("/") + 1);

            double textureX = std::atof(t0.substr(0, t0.find("/")).c_str()) - 1;
            double textureY = std::atof(t1.substr(0, t1.find("/")).c_str()) - 1;
            double textureZ = std::atof(t2.substr(0, t2.find("/")).c_str()) - 1;

//            std::cout << textureX << " " << textureY << " " << textureZ << std::endl;

            Point3D texture = Point3D(textureX, textureY, textureZ);

//            faces.push_back(triangle(vertexs.at(std::atoi(t0.c_str())-1), vertexs.at(std::atoi(t1.c_str())-1), vertexs.at(std::atoi(t2.c_str())-1)));
            faces.push_back(triangle(vertexs.at(std::atoi(t0_.c_str()) - 1), vertexs.at(std::atoi(t1_.c_str()) - 1),
                                     vertexs.at(std::atoi(t2_.c_str()) - 1), texture));

//            cout << vertexs.at(std::atoi(t0.c_str())-1).x << " " << vertexs.at(std::atoi(t0.c_str())-1).y << " " << vertexs.at(std::atoi(t0.c_str())-1).z << " " << endl;
//            cout << vertexs.at(std::atoi(t1.c_str())-1).x << " " << vertexs.at(std::atoi(t1.c_str())-1).y << " " << vertexs.at(std::atoi(t1.c_str())-1).z << " " << endl;
//            cout << vertexs.at(std::atoi(t2.c_str())-1).x << " " << vertexs.at(std::atoi(t2.c_str())-1).y << " " << vertexs.at(std::atoi(t2.c_str())-1).z << " " << endl << endl;

//            cout << t0 << "\t" << t1 << "\t" << t2 << endl;
//            cout << t0_ << "\t" << t1_ << "\t" << t2_ << endl;
//
//            cout << std::atoi(t0.c_str())-1 << "\t" << std::atoi(t1.c_str())-1 << "\t" << std::atoi(t2.c_str())-1 << endl;
//            cout << std::atoi(t0_.c_str())-1 << "\t" << std::atoi(t1_.c_str())-1 << "\t" << std::atoi(t2_.c_str())-1 << endl << endl;


        }

        //lecture des textures
        if (line[0] == 'v' & line[1] == 't') {

            iss >> lineType >> x >> y >> z;
//            cout << x << "\t" << y << "\t" << z << endl;

            Point3D point = Point3D(std::atof(x.c_str()), std::atof(y.c_str()), std::atof(z.c_str()));
            textures.push_back(point);
//            cout << x << "\t" << std::atof(x.c_str()) << "\t" << point.x << endl;
        }
    }

    return objmodel(vertexs, faces, textures);
}