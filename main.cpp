#include "User/User.h"
#include "Matrix/Matrix.h"

int main()
{
	matrixParams params; // Define the params variable

	user::userInput(params);
	matrixOutput::matrixConversion(params);

	return 0;
}