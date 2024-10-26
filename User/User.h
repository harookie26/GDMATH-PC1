#ifndef USER_H
#define USER_H

#pragma once

struct transformation {

    float x, y, z;

};

struct rotation {

    float x, y, z, theta;

};

struct scaling {

    float x, y, z;

};

struct matrixParams {

    transformation trans;

    scaling scale;

    rotation rot;

};

class user
{
public:
    transformation transformation;
    rotation rotation;
    scaling scale;

    static void userInput(matrixParams& params);
};

#endif
