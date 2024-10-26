#include "User.h"

#include <iostream>

/**
 * @brief Prompts the user to input transformation, rotation, and scale values.
 *
 * This function will ask the user to input values for x, y, and z transformations,
 * rotations, and scales. It will also prompt for a rotation angle in degrees.
 *
 * @param params A reference to a MatrixParams structure to store the user input.
 */
void user::userInput(matrixParams& params)
{
	std::cout << "\nEnter transformation" << std::endl;
	std::cout << "x: ";
	std::cin >> params.trans.x;

	std::cout << "y: ";
	std::cin >> params.trans.y;

	std::cout << "z: ";
	std::cin >> params.trans.z;

	std::cout << "\nEnter scale" << std::endl;
	std::cout << "x: ";
	std::cin >> params.scale.x;

	std::cout << "y: ";
	std::cin >> params.scale.y;

	std::cout << "z: ";
	std::cin >> params.scale.z;

	std::cout << "\nEnter rotation" << std::endl;
	std::cout << "x: ";
	std::cin >> params.rot.x;

	std::cout << "y: ";
	std::cin >> params.rot.y;

	std::cout << "z: ";
	std::cin >> params.rot.z;

	std::cout << "\nEnter rotation angle (in degrees)" << std::endl;
	std::cout << "theta: ";
	std::cin >> params.rot.theta;
}
