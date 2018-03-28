//
// Created by antoine on 28/03/18.
//

#ifndef INFOGRAPHIE_LOADFILE_H
#define INFOGRAPHIE_LOADFILE_H
#include <iostream>
#include <fstream>
#include "objmodel.h"


class objfile {

public:
    static objmodel loadfile(char* fileName);
};


#endif //INFOGRAPHIE_LOADFILE_H
