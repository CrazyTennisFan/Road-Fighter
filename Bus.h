#pragma once
#include <GL/glut.h>


class Bus
{
	private:
		float speed;
		float length;
		float width;
		float posX;
		float posY;
		float posZ;
		int front;
		int left;
		int back;
		int right;
		int rotation_wheel;

		float material_Black[4];
		float material_White[4];
		float material_Grey[4];
		float materialShininess;

		double PI;
		GLUquadric *quadratic;
		void drawBusBody1();
		void drawBusBody2();
		void drawBusBody3();
		void drawBusBody4();
		void drawBusBody5();
		void drawBusFrontLeftWheel();
		void drawBusFrontRightWheel();
		void drawBusRearLeftWheel();
		void drawBusRearRightWheel();
		void drawBusExhaustPipe();

	public:
		Bus(int back, int front, int left, int right, float x, float y, float z);
		~Bus();
		float getSpeed();
		void setSpeed(float s);
		float getLength();
		float getWidth();
		float getPosX();
		void setPosX(float x);
		float getPosY();
		void setPosY(float y);
		float getPosZ();
		void setPosZ(float z);
		void drawBus();
		void moveBus();
};