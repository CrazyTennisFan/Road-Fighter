#pragma once

#include <GL/glut.h>

class Box {

public:
	Box(int length, int function, float speed, float x, float y, float z, int texture);
	~Box();
	void drawBox();
	int getLength();
	int getFunction();
	float getSpeed();
	float getPosX();
	float getPosY();
	float getPosZ();
	
private:
	int length;
	int function;
	float speed;
	float posX;
	float posY;
	float posZ;
	float material_Green[4];
	float material_Red[4];
	float material_Yellow[4];
	float materialShininess;

	int texture;
};