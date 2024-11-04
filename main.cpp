#include <iostream>

#include "User/User.h"
#include "Matrix/Matrix.h"

int main()
{
	int input;
	matrixParams params;

	float pointD[4] = {-14, 10, 42, 1}; // Original point (x, y, z, 1)
	float transformedPoint[4];

	std::cout << "Original D' is ("
		<< pointD[0] << ", "
		<< pointD[1] << ", "
		<< pointD[2] << ")"
		<< std::endl;

	user::userInput(params);

	matrix transformationMatrix(params);

	transformationMatrix.getFinalTransformationMatrix(params);

	transformationMatrix.applyTransformationToPoint(pointD, transformedPoint);

	std::cout << "\nTransformed D' is ("
		<< transformedPoint[0] << ", "
		<< transformedPoint[1] << ", "
		<< transformedPoint[2] << ")"
		<< std::endl;

	std::cout << "\nInput any number to exit: ";
	std::cin >> input;

	return 0;
}
