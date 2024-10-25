#include "Matrix.h"

#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14
#endif

/**
 * @brief Constructs a Matrix object and initializes transformation, rotation, and scaling matrices.
 *
 * @param trans The transformation parameters.
 * @param rot The rotation parameters.
 * @param scale The scaling parameters.
 */
matrix::matrix(const transformation& trans, const rotation& rot, const scaling& scale)
{
	// Initialize transformationMatrix with user-provided values
	setTransformationMatrix(trans.x, trans.y, trans.z);

	// Initialize rotationMatrix with user-provided values
	setRotationMatrix(rot.x, rot.y, rot.z, rot.theta);

	// Initialize scalingMatrix with user-provided values
	setScalingMatrix(scale.x, scale.y, scale.z);
}

/**
 * @brief Sets the transformation matrix with the given x, y, z translation values.
 *
 * @param x Translation along the x-axis.
 * @param y Translation along the y-axis.
 * @param z Translation along the z-axis.
 */
void matrix::setTransformationMatrix(float x, float y, float z)
{
	transformation_matrix_[0][0] = 1;
	transformation_matrix_[0][1] = 0;
	transformation_matrix_[0][2] = 0;
	transformation_matrix_[0][3] = x;
	transformation_matrix_[1][0] = 0;
	transformation_matrix_[1][1] = 1;
	transformation_matrix_[1][2] = 0;
	transformation_matrix_[1][3] = y;
	transformation_matrix_[2][0] = 0;
	transformation_matrix_[2][1] = 0;
	transformation_matrix_[2][2] = 1;
	transformation_matrix_[2][3] = z;
	transformation_matrix_[3][0] = 0;
	transformation_matrix_[3][1] = 0;
	transformation_matrix_[3][2] = 0;
	transformation_matrix_[3][3] = 1;
}

/**
 * @brief Sets the rotation matrix with the given x, y, z rotation values in degrees.
 *
 * @param x Rotation around the x-axis in degrees.
 * @param y Rotation around the y-axis in degrees.
 * @param z Rotation around the z-axis in degrees.
 * @param theta Angle of rotation in degrees.
 */
void matrix::setRotationMatrix(float x, float y, float z, float theta)
{
	// Normalize the axis vector (x, y, z)  
	const float magnitude = sqrt(x * x + y * y + z * z);
	if (magnitude != 0.0f)
	{
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
	}

	// Convert angle from degrees to radians  
	const float radTheta = static_cast<float>(theta * M_PI / 180.0);

	// Compute the half-angle  
	const float halfTheta = radTheta / 2;

	// Compute quaternion components  
	const float a = cos(halfTheta);
	const float sinHalfTheta = sin(halfTheta);
	const float b = sinHalfTheta * x;
	const float c = sinHalfTheta * y;
	const float d = sinHalfTheta * z;

	// Fill in the rotation matrix using quaternion matrix components  
	rotation_matrix_[0][0] = a * a + b * b - c * c - d * d;
	rotation_matrix_[0][1] = 2 * (b * c + a * d);
	rotation_matrix_[0][2] = 2 * (b * d - a * c);
	rotation_matrix_[0][3] = 0;

	rotation_matrix_[1][0] = 2 * (b * c - a * d);
	rotation_matrix_[1][1] = a * a - b * b + c * c - d * d;
	rotation_matrix_[1][2] = 2 * (c * d + a * b);
	rotation_matrix_[1][3] = 0;

	rotation_matrix_[2][0] = 2 * (b * d + a * c);
	rotation_matrix_[2][1] = 2 * (c * d - a * b);
	rotation_matrix_[2][2] = a * a - b * b - c * c + d * d;
	rotation_matrix_[2][3] = 0;

	rotation_matrix_[3][0] = 0;
	rotation_matrix_[3][1] = 0;
	rotation_matrix_[3][2] = 0;
	rotation_matrix_[3][3] = 1;
}

/**
 * @brief Sets the scaling matrix with the given x, y, z scaling values.
 *
 * @param x Scaling along the x-axis.
 * @param y Scaling along the y-axis.
 * @param z Scaling along the z-axis.
 */
void matrix::setScalingMatrix(float x, float y, float z)
{
	scaling_matrix_[0][0] = x;
	scaling_matrix_[0][1] = 0;
	scaling_matrix_[0][2] = 0;
	scaling_matrix_[0][3] = 0;
	scaling_matrix_[1][0] = 0;
	scaling_matrix_[1][1] = y;
	scaling_matrix_[1][2] = 0;
	scaling_matrix_[1][3] = 0;
	scaling_matrix_[2][0] = 0;
	scaling_matrix_[2][1] = 0;
	scaling_matrix_[2][2] = z;
	scaling_matrix_[2][3] = 0;
	scaling_matrix_[3][0] = 0;
	scaling_matrix_[3][1] = 0;
	scaling_matrix_[3][2] = 0;
	scaling_matrix_[3][3] = 1;
}

/**
 * @brief Prints the given 4x4 matrix to the console, rounding each value to the nearest hundredths.
 *
 * @param matrix The 4x4 matrix to be printed.
 */
void matrix::printMatrix(float matrix[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			// Round to the nearest hundredths  
			const float value = static_cast<float>(round(matrix[i][j] * 100.0) / 100.0);
			std::cout << value << " ";
		}
		std::cout << std::endl;
	}
}

/**
 * @brief Demonstrates the creation and printing of transformation, rotation, and scaling matrices.
 *
 * @param params The parameters for the matrix transformations.
 */
void matrixOutput::matrixConversion(const matrixParams& params)
{
	matrix matrix(params.trans, params.rot, params.scale);
	float finalMatrix[4][4];

	matrix.getFinalTransformationMatrix(params, finalMatrix);

	std::cout << "\nFinal Transformation Matrix:" << std::endl;
	matrix::printMatrix(finalMatrix);

	// Define the augmented vector [x, y, z, 1]
	float vector[4] = { params.trans.x, params.trans.y, params.trans.z, 1 };
	float transformedVector[4];

	// Transform the vector using the final transformation matrix
	matrix::transformVector(transformedVector, finalMatrix, vector);

	std::cout << "\nTransformed Vector:" << std::endl;
	for (const float i : transformedVector)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

/**
 * @brief Multiplies two 4x4 matrices and stores the result in a third matrix.
 *
 * @param result The resulting matrix after multiplication.
 * @param mat1 The first matrix to be multiplied.
 * @param mat2 The second matrix to be multiplied.
 */
void matrix::multiplyMatrices(float result[4][4], float mat1[4][4], float mat2[4][4])
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

/**
 * @brief Computes the final transformation matrix by combining translation, scaling, and rotation matrices.
 *
 * @param params The parameters for the matrix transformations.
 * @param result The resulting final transformation matrix.
 */
void matrix::getFinalTransformationMatrix(const matrixParams& params, float result[4][4])
{
	// Set individual matrices
	setTransformationMatrix(params.trans.x, params.trans.y, params.trans.z);
	setScalingMatrix(params.scale.x, params.scale.y, params.scale.z);
	setRotationMatrix(params.rot.x, params.rot.y, params.rot.z, params.rot.theta);

	// Multiply translation and scaling matrices
	multiplyMatrices(temp_matrix1_, transformation_matrix_, scaling_matrix_);

	// Multiply the result with the rotation matrix
	multiplyMatrices(result, temp_matrix1_, rotation_matrix_);
}

/**
 * @brief Transforms a vector using a given 4x4 matrix.
 *
 * @param result The resulting transformed vector.
 * @param matrix The transformation matrix.
 * @param vector The vector to be transformed.
 */
void matrix::transformVector(float result[4], float matrix[4][4], float vector[4])
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
