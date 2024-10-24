#include "User/User.h"
#include "Matrix/Matrix.h"

int main()
{
	user user;

	user.userInput();

	matrix_output matrix;
	matrix.matrixConversion(user.x_transformation, user.y_transformation, user.z_transformation,
	                        user.x_rotation, user.y_rotation, user.z_rotation,
	                        user.x_scale, user.y_scale, user.z_scale, user.rotation_angle);

	return 0;
}
