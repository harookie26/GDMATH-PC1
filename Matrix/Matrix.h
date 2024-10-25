#ifndef MATRIX_H
#define MATRIX_H

#include "../User/User.h"

class matrix
{
public:
	matrix(const transformation& trans, const rotation& rot, const scaling& scale);
	void setTransformationMatrix(float x, float y, float z);
	void setRotationMatrix(float x, float y, float z, float theta);
	void setScalingMatrix(float x, float y, float z);
	static void printMatrix(float matrix[4][4]);
	static void multiplyMatrices(float result[4][4], float mat1[4][4], float mat2[4][4]);
	void getFinalTransformationMatrix(const matrixParams& params, float result[4][4]);
	static void transformVector(float result[4], float matrix[4][4], float vector[4]);

private:
	float transformation_matrix_[4][4];

	float rotation_matrix_[4][4];

	float scaling_matrix_[4][4];

	float temp_matrix1_[4][4];
};

class matrixOutput
{
public:
	static void matrixConversion(const matrixParams& params);
};

#endif // MATRIX_H
