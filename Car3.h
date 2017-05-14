#pragma once
#include "Car.h"
#include <GL/glut.h>

class Car3 : public Car
{
	public:
		Car3(int shaftTexture, int pipeTexture, int cargoTexture);
		~Car3(void);
		void drawCar();
		void drawTrailer();

	private:
		GLUquadric *quadratic;
		void drawCar3();
		void drawCar3TrailerAndHitch();

		int rotate_trailer_wheel;
		int rotate_moto_wheel;
		int rotate_moto_wheel_speed;
		int rotate_trailer_wheel_speed;
};

