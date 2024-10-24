#ifndef USER_H
#define USER_H

#pragma once

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

	float rotation_angle;

	void userInput();
};

#endif