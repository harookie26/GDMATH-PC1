#ifndef MATRIX_H
#define MATRIX_H

#include "../User/User.h">

class Matrix {
public:
    void setTransformationMatrix(float x, float y, float z);
    void setRotationMatrix(float x, float y, float z, float theta);
    void setScalingMatrix(float x, float y, float z);
    void printMatrix(float matrix[4][4]);
    void multiplyMatrices(float result[4][4], float mat1[4][4], float mat2[4][4]);
    void getFinalTransformationMatrix(float x_trans, float y_trans, float z_trans,
        float x_scale, float y_scale, float z_scale,
        float x_rot, float y_rot, float z_rot, float theta,
        float result[4][4]);
    void transformVector(float result[4], float matrix[4][4], float vector[4]);
private:
    float transformationMatrix[4][4];
    float rotationMatrix[4][4];
    float scalingMatrix[4][4];
};


class matrix_output
{
public:
    void matrixConversion(float x_trans, float y_trans, float z_trans,
        float x_rot, float y_rot, float z_rot,
        float x_scale, float y_scale, float z_scale, float theta);
};

#endif // MATRIX_H
