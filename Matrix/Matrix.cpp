#include "Matrix.h"
#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14
#endif

/**
 * @brief Constructs a Matrix object and initializes transformation, rotation, and scaling matrices.
 *
 * @param x_trans Translation along the x-axis.
 * @param y_trans Translation along the y-axis.
 * @param z_trans Translation along the z-axis.
 * @param x_rot Rotation around the x-axis in degrees.
 * @param y_rot Rotation around the y-axis in degrees.
 * @param z_rot Rotation around the z-axis in degrees.
 * @param theta Angle of rotation in degrees.
 * @param x_scale Scaling along the x-axis.
 * @param y_scale Scaling along the y-axis.
 * @param z_scale Scaling along the z-axis.
 */
Matrix::Matrix(float x_trans, float y_trans, float z_trans,
               float x_rot, float y_rot, float z_rot, float theta,
               float x_scale, float y_scale, float z_scale)
{
	// Initialize transformationMatrix with user-provided values
	setTransformationMatrix(x_trans, y_trans, z_trans);

	// Initialize rotationMatrix with user-provided values
	setRotationMatrix(x_rot, y_rot, z_rot, theta);

	// Initialize scalingMatrix with user-provided values
	setScalingMatrix(x_scale, y_scale, z_scale);
}

/**
 * @brief Sets the transformation matrix with the given x, y, z translation values.
 *
 * @param x Translation along the x-axis.
 * @param y Translation along the y-axis.
 * @param z Translation along the z-axis.
 */
void Matrix::setTransformationMatrix(float x, float y, float z)
{
	transformationMatrix[0][0] = 1;
	transformationMatrix[0][1] = 0;
	transformationMatrix[0][2] = 0;
	transformationMatrix[0][3] = x;
	transformationMatrix[1][0] = 0;
	transformationMatrix[1][1] = 1;
	transformationMatrix[1][2] = 0;
	transformationMatrix[1][3] = y;
	transformationMatrix[2][0] = 0;
	transformationMatrix[2][1] = 0;
	transformationMatrix[2][2] = 1;
	transformationMatrix[2][3] = z;
	transformationMatrix[3][0] = 0;
	transformationMatrix[3][1] = 0;
	transformationMatrix[3][2] = 0;
	transformationMatrix[3][3] = 1;
}

/**
 * @brief Sets the rotation matrix with the given x, y, z rotation values in degrees.
 *
 * @param x Rotation around the x-axis in degrees.
 * @param y Rotation around the y-axis in degrees.
 * @param z Rotation around the z-axis in degrees.
 * @param theta Angle of rotation in degrees.
 */
void Matrix::setRotationMatrix(float x, float y, float z, float theta)
{
	// Normalize the axis vector (x, y, z)  
	float magnitude = sqrt(x * x + y * y + z * z);
	if (magnitude != 0.0f)
	{
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
	}

	// Convert angle from degrees to radians  
	float radTheta = static_cast<float>(theta * M_PI / 180.0);

	// Compute the half-angle  
	float halfTheta = radTheta / 2;

	// Compute quaternion components  
	float A = cos(halfTheta);
	float sinHalfTheta = sin(halfTheta);
	float B = sinHalfTheta * x;
	float C = sinHalfTheta * y;
	float D = sinHalfTheta * z;

	// Fill in the rotation matrix using quaternion matrix components  
	rotationMatrix[0][0] = A * A + B * B - C * C - D * D;
	rotationMatrix[0][1] = 2 * (B * C + A * D);
	rotationMatrix[0][2] = 2 * (B * D - A * C);
	rotationMatrix[0][3] = 0;

	rotationMatrix[1][0] = 2 * (B * C - A * D);
	rotationMatrix[1][1] = A * A - B * B + C * C - D * D;
	rotationMatrix[1][2] = 2 * (C * D + A * B);
	rotationMatrix[1][3] = 0;

	rotationMatrix[2][0] = 2 * (B * D + A * C);
	rotationMatrix[2][1] = 2 * (C * D - A * B);
	rotationMatrix[2][2] = A * A - B * B - C * C + D * D;
	rotationMatrix[2][3] = 0;

	rotationMatrix[3][0] = 0;
	rotationMatrix[3][1] = 0;
	rotationMatrix[3][2] = 0;
	rotationMatrix[3][3] = 1;
}

/**
 * @brief Sets the scaling matrix with the given x, y, z scaling values.
 *
 * @param x Scaling along the x-axis.
 * @param y Scaling along the y-axis.
 * @param z Scaling along the z-axis.
 */
void Matrix::setScalingMatrix(float x, float y, float z)
{
	scalingMatrix[0][0] = x;
	scalingMatrix[0][1] = 0;
	scalingMatrix[0][2] = 0;
	scalingMatrix[0][3] = 0;
	scalingMatrix[1][0] = 0;
	scalingMatrix[1][1] = y;
	scalingMatrix[1][2] = 0;
	scalingMatrix[1][3] = 0;
	scalingMatrix[2][0] = 0;
	scalingMatrix[2][1] = 0;
	scalingMatrix[2][2] = z;
	scalingMatrix[2][3] = 0;
	scalingMatrix[3][0] = 0;
	scalingMatrix[3][1] = 0;
	scalingMatrix[3][2] = 0;
	scalingMatrix[3][3] = 1;
}

/**
 * @brief Prints the given 4x4 matrix to the console, rounding each value to the nearest hundredths.
 *
 * @param matrix The 4x4 matrix to be printed.
 */
void Matrix::printMatrix(float matrix[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			// Round to the nearest hundredths  
			float value = static_cast<float>(round(matrix[i][j] * 100.0) / 100.0);
			std::cout << value << " ";
		}
		std::cout << std::endl;
	}
}

/**
 * @brief Demonstrates the creation and printing of transformation, rotation, and scaling matrices.
 *
 * @param x_trans Translation along the x-axis.
 * @param y_trans Translation along the y-axis.
 * @param z_trans Translation along the z-axis.
 * @param x_rot Rotation around the x-axis in degrees.
 * @param y_rot Rotation around the y-axis in degrees.
 * @param z_rot Rotation around the z-axis in degrees.
 * @param x_scale Scaling along the x-axis.
 * @param y_scale Scaling along the y-axis.
 * @param z_scale Scaling along the z-axis.
 * @param theta Angle of rotation in degrees.
 */
void matrix_output::matrixConversion(float x_trans, float y_trans, float z_trans,
                                     float x_rot, float y_rot, float z_rot,
                                     float x_scale, float y_scale, float z_scale, float theta)
{
	Matrix m(x_trans, y_trans, z_trans, x_rot, y_rot, z_rot, theta, x_scale, y_scale, z_scale);
	float finalMatrix[4][4];

	m.getFinalTransformationMatrix(x_trans, y_trans, z_trans,
	                               x_scale, y_scale, z_scale,
	                               x_rot, y_rot, z_rot, theta,
	                               finalMatrix);

	std::cout << "\nFinal Transformation Matrix:" << std::endl;
	m.printMatrix(finalMatrix);

	// Define the augmented vector [x, y, z, 1]
	float vector[4] = {x_trans, y_trans, z_trans, 1};
	float transformedVector[4];

	// Transform the vector using the final transformation matrix
	m.transformVector(transformedVector, finalMatrix, vector);

	std::cout << "\nTransformed Vector:" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		std::cout << transformedVector[i] << " ";
	}
	std::cout << std::endl;
}

void Matrix::multiplyMatrices(float result[4][4], float mat1[4][4], float mat2[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result[i][j] = 0;
			for (int k = 0; k < 4; ++k)
			{
				result[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}

void Matrix::getFinalTransformationMatrix(float x_trans, float y_trans, float z_trans,
                                          float x_scale, float y_scale, float z_scale,
                                          float x_rot, float y_rot, float z_rot, float theta,
                                          float result[4][4])
{
	// Set individual matrices
	setTransformationMatrix(x_trans, y_trans, z_trans);
	setScalingMatrix(x_scale, y_scale, z_scale);
	setRotationMatrix(x_rot, y_rot, z_rot, theta);

	// Temporary matrices to hold intermediate results
	float tempMatrix1[4][4];

	// Multiply translation and scaling matrices
	multiplyMatrices(tempMatrix1, transformationMatrix, scalingMatrix);

	// Multiply the result with the rotation matrix
	multiplyMatrices(result, tempMatrix1, rotationMatrix);
}

void Matrix::transformVector(float result[4], float matrix[4][4], float vector[4])
{
	for (int i = 0; i < 4; ++i)
	{
		result[i] = 0;
		for (int j = 0; j < 4; ++j)
		{
			result[i] += matrix[i][j] * vector[j];
		}
	}
}
