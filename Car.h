#pragma once

#include <math.h>

class Car
{
	protected:
	
		float posX;
		float posY;
		float posZ;
		float speed;
		float wheelRotateAngle;
		float PI;
		float length;
		float width;
		int shaftTexture;
		int pipeTexture; 
		int cargoTexture;
		
	public:

		Car();
		virtual ~Car();
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

		virtual void drawCar() = 0;
		virtual void drawTrailer() = 0;
};