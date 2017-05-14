#pragma once

#include "Car.h"
#include <GL/glut.h>
class Car1: public Car
{
	public:
		Car1(int shaftTexture, int pipeTexture, int cargoTexture); 
		~Car1();
		void drawCar();
		void drawTrailer();
		
	private:
		GLUquadric *quadratic;
		float *pointArray1;     //these points for gas tank 
		float *trailerKeyPoint;

		float material_Black[4];
		float material_Grey[4];
		float material_DarkGrey[4];
		float material_LightGrey[4];
		float material_Red[4];
		float material_White[4];
		float materialShininess;

		void drawCar1();
		void drawCar1TrailerAndHitch();
		void drawCar1LeftPedalShaft();		
		void drawCar1LeftPedal();
		void drawCar1RightPedalShaft();
		void drawCar1RightPedal();		
		void drawCar1Engine();
		void drawCar1ToolBox();		
		void drawCar1RearWheelLeftShaft();
		void drawCar1RearWheel();
		void drawCar1WheelCenter();
		void drawCar1RearWheelCenter();
		void drawCar1RearWheelCover();		
		void drawCar1RearWheelCenterShaft();
		void drawCar1RearWheelRightShaft();
		void drawCar1RearLight();
		void drawCar1FrontWheelLeftShaft();
		void drawCar1FrontWheel();
		void drawCar1FrontWheelCenter();
		void drawCar1FrontWheelCover();		
		void drawCar1FrontWheelCenterShaft();
		void drawCar1FrontWheelRightShaft();
		void drawCar1FrontLight();
		void drawCar1FrontWheelMiddleShaft();
		void drawCar1LeftHandleBar();
		void drawCar1RightHandleBar();		
		void drawCar1ExhaustPipe();
		void drawCar1OtherShaft();
		void drawCar1GasTank();
		void drawCar1SeatPart1();
		void drawCar1SeatPart2();
		void drawCar1TrailerHitch();
		void drawCar1TrailerHitchArm();
		void drawCar1Trailer();
		void drawCar1TrailerLeftWheel();
		void drawCar1TrailerLeftWheelCenter();
		float drawCar1TrailerLeftWheelCover();
		void drawCar1TrailerWheelCenterShaft();
		void drawCar1Cargo();
		void drawCar1TrailerRightWheel();
		void drawCar1TrailerRightWheelCenter();
		float drawCar1TrailerRightWheelCover();
};