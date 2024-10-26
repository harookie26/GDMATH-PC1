#ifndef MATRIX_H
#define MATRIX_H

#include <string>

#include "../User/User.h"

class matrix
{
public:
    // Modify the constructor to accept matrixParams
    matrix(const matrixParams& params);
    void setTransformationMatrix(float x, float y, float z);
    void setRotationMatrix(float x, float y, float z, float theta);
    void setScalingMatrix(float x, float y, float z);
    static void printMatrix(float matrix[4][4]);
    static void multiplyMatrices(float result[4][4], float mat1[4][4], float mat2[4][4]);
    void getFinalTransformationMatrix(const matrixParams& params);
    void applyTransformationToPoint(float point[4], float transformedPoint[4]) const;

    void exportTransformationMatrix(const std::string& filename);
    void exportScalingMatrix(const std::string& filename);
    void exportRotationMatrix(const std::string& filename);


private:
    float transformation_matrix_[4][4];
    float rotation_matrix_[4][4];
    float scaling_matrix_[4][4];
    float temp_matrix1_[4][4];
    float final_transformation_matrix_[4][4];

    static void writeMatrixToFile(float matrix[4][4], const std::string& filename);
};

class matrixOutput
{
public:
    static void applyTransformationToPoint(float point[4], float transformedPoint[4]);
};

#endif // MATRIX_H
