#ifndef USER_H
#define USER_H

#pragma once

#include <iostream>

class user
{
public:
	float x_transformation;
	float y_transformation;
	float z_transformation;
	
	float x_rotation;
	float y_rotation;
	float z_rotation;
	
	float x_scale;
	float y_scale;
	float z_scale;

	int rotation_angle;

	void userInput();
};

#endif