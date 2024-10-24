#include "User.h"

#include <iostream>

/**
 * @brief Prompts the user to input transformation, rotation, and scale values.
 *
 * This function will ask the user to input values for x, y, and z transformations,
 * rotations, and scales. It will also prompt for a rotation angle in degrees.
 */
void user::userInput()
{
    std::cout << "\nEnter transformation" << std::endl;
    std::cout << "x: ";
    std::cin >> x_transformation;

    std::cout << "y: ";
    std::cin >> y_transformation;

    std::cout << "z: ";
    std::cin >> z_transformation;

    std::cout << "\nEnter rotation" << std::endl;
    std::cout << "x: ";
    std::cin >> x_rotation;

    std::cout << "y: ";
    std::cin >> y_rotation;

    std::cout << "z: ";
    std::cin >> z_rotation;

    std::cout << "\nEnter scale" << std::endl;
    std::cout << "x: ";
    std::cin >> x_scale;

    std::cout << "y: ";
    std::cin >> y_scale;

    std::cout << "z: ";
    std::cin >> z_scale;

    std::cout << "\nEnter rotation angle (in degrees)" << std::endl;
    std::cout << "theta: ";
    std::cin >> rotation_angle;
}
