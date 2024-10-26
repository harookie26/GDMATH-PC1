#include <iostream>
#include "User/User.h"
#include "Matrix/Matrix.h"

int main() {
    matrixParams params;

    // Define point D' in homogeneous coordinates
    float pointD[4] = { -14, 10, 42, 1 };  // Original point (x, y, z, 1)
    float transformedPoint[4];

    // Print the original point D'
    std::cout << "Original D' is ("
        << pointD[0] << ", "
        << pointD[1] << ", "
        << pointD[2] << ")"
        << std::endl;

    // Ask the user to input the transformation, scale, and rotation parameters
    user::userInput(params);

    // Create the transformation matrix using the user input
    matrix transformationMatrix(params);

    // Export the individual matrices to text files
    transformationMatrix.exportTransformationMatrix("transformation_matrix.txt");
    transformationMatrix.exportScalingMatrix("scaling_matrix.txt");
    transformationMatrix.exportRotationMatrix("rotation_matrix.txt");


    // Get the final transformation matrix
    transformationMatrix.getFinalTransformationMatrix(params);

    // Apply the final transformation matrix to point D'
    transformationMatrix.applyTransformationToPoint(pointD, transformedPoint);

    // Output the transformed point
    std::cout << "\nTransformed D' is ("
        << transformedPoint[0] << ", "
        << transformedPoint[1] << ", "
        << transformedPoint[2] << ")"
        << std::endl;

    return 0;
}
