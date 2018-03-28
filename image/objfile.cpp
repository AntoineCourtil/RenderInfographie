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
    string lineType, x, y, z, t0, t1, t2;

    std::vector<Point3D> data;
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

            Point3D point = Point3D(std::atof(x.c_str())*100 +500, std::atof(y.c_str())*100 +500, std::atof(z.c_str())*100 +500);
            data.push_back(point);
//            cout << x << "\t" << std::atof(x.c_str()) << "\t" << point.x << endl;
        }

        //lecture des faces
        if (line[0] == 'f' & line[1] == ' ') {
            iss >> lineType >> t0 >> t1 >> t2;

            faces.push_back(triangle(data.at(std::atoi(t0.c_str())-1), data.at(std::atoi(t1.c_str())-1), data.at(std::atoi(t2.c_str())-1)));

//            cout << data.at(std::atoi(t0.c_str())-1).x << data.at(std::atoi(t0.c_str())-1).y << data.at(std::atoi(t0.c_str())-1).z << endl;
//            cout << data.at(std::atoi(t1.c_str())-1).x << data.at(std::atoi(t1.c_str())-1).y << data.at(std::atoi(t1.c_str())-1).z << endl;
//            cout << data.at(std::atoi(t2.c_str())-1).x << data.at(std::atoi(t2.c_str())-1).y << data.at(std::atoi(t2.c_str())-1).z << endl << endl;

//            cout << t0 << "\t" << t1 << "\t" << t2 << endl;


        }
    }

    return objmodel(data, faces);
}