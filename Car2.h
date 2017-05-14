#pragma once
#include "Car.h"
#include <GL/glut.h>


class Car2 : public Car
{
	public:
		Car2(int shaftTexture, int pipeTexture, int cargoTexture);
		~Car2();
		void drawCar();
		void drawTrailer();

	private:
		GLUquadric *quadratic;
		float *xList; // array of x, for calculation of arc
		float *yList; // array of y, for calculation of arc

		float material_Black[4];
		float material_Orange[4];
		float material_SlateBlue[4];
		float materialShininess;

		void drawCar2();
		void drawCar2TrailerAndHitch();

		void drawCar2WheelShaft(float x, float y, float z);
		void drawCar2WheelMudTile();
		void drawCar2FrontWheel();
		void drawCar2FrontWheelMudTile();
		void drawCar2FrontLeftShaft();
		void drawCar2FrontRightShaft();
		void drawCar2FrontShaft();
		void drawCar2LeftHandleBar();
		void drawCar2RightHandleBar();
		void drawCar2FrontPanel();
		void drawCar2FrontLight();
		void drawCar2FrontConnectShaft();
		void drawCar2GasTank();
		void drawCar2Engine();
		void drawCar2Battery();
		void drawCar2FrontSlantPipe();
		void drawCar2RearSlantPipe();
		void drawCar2MiddleHorizontalPipe();
		void drawCar2ExhaustPipe();
		void drawCar2RearLeftShaft();
		void drawCar2RearRightShaft();
		void drawCar2RearWheel();
		void drawCar2RearWheelMudTile();
		void drawCar2RearLight();
		void drawCar2Seat();
		void drawCar2Hitch();
		void drawCar2HitchTorus();
		void drawCar2TrailerCargo();
		void drawCar2TrailerLeftWheel();
		void drawCar2TrailerRightWheel();
		void drawCar2TrailerWheelConnectingShaft();
		void drawCar2TrailerLeftWheelMudTile();
		void drawCar2TrailerRightWheelMudTile();
		int calculateIncreasingArc(float x, float y, float length, int startAngle, int endAngle, int angleChange);
		int calculateDecreasingArc(float x, float y, float length, int startAngle, int endAngle, int angleChange);
		
};

