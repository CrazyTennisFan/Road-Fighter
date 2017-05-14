#include "Car.h"

Car::Car()
	:posX(-699), posY(0), posZ(0), speed(0.0), wheelRotateAngle(0.0), PI(3.14159265)
{}

Car::~Car()
{}

float Car::getSpeed()
{
	return speed;
}

void Car::setSpeed(float s)
{
	speed = s;
}

float Car::getLength()
{
	return length;
}

float Car::getWidth()
{
	return width;
}

float Car::getPosX()
{
	return posX;
}

void Car::setPosX(float x)
{
	posX = x;
}

float Car::getPosY()
{
	return posY;
}

void Car::setPosY(float y)
{
	posY = y;
}

float Car::getPosZ()
{
	return posZ;
}

void Car::setPosZ(float z)
{
	posZ = z;
}
