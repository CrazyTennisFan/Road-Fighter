#include "Car1.h"


Car1::Car1(int shaftTexture, int pipeTexture, int cargoTexture)
{
	length = 17; // half
	width = 7; // half
	this->shaftTexture = shaftTexture;
	this->pipeTexture = pipeTexture;
	this->cargoTexture = cargoTexture;
	quadratic = gluNewQuadric();
	pointArray1 = new float[64];     //these points for gas tank 
	trailerKeyPoint = new float[8];

	material_Black[0] = 0.0;
	material_Black[1] = 0.0;
	material_Black[2] = 0.0;
	material_Black[3] = 1.0;

	material_Grey[0] = 0.5;
	material_Grey[1] = 0.5;
	material_Grey[2] = 0.5;
	material_Grey[3] = 1.0;

	material_DarkGrey[0] = 0.4;
	material_DarkGrey[1] = 0.4;
	material_DarkGrey[2] = 0.4;
	material_DarkGrey[3] = 1.0;

	material_LightGrey[0] = 0.7;
	material_LightGrey[1] = 0.7;
	material_LightGrey[2] = 0.7;
	material_LightGrey[3] = 1.0;

	material_Red[0] = 1.0;
	material_Red[1] = 0.0;
	material_Red[2] = 0.0;
	material_Red[3] = 1.0;

	material_White[0] = 1.0;
	material_White[1] = 1.0;
	material_White[2] = 1.0;
	material_White[3] = 1.0;

	materialShininess = 50.0;
}

Car1::~Car1()
{}

void Car1::drawCar()
{
	wheelRotateAngle += speed / 2.5f; // speed/wheel radius
	drawCar1();
}

void Car1::drawTrailer()
{
	drawCar1TrailerAndHitch();
}

void Car1::drawCar1()
{
	glPushMatrix();

	drawCar1LeftPedalShaft();		
	drawCar1LeftPedal();
	drawCar1RightPedalShaft();
	drawCar1RightPedal();		
	drawCar1Engine();
	drawCar1ToolBox();		
	drawCar1RearWheelLeftShaft();
	drawCar1RearWheel();
	
	//drawCar1WheelCenter();
	drawCar1RearWheelCenter();
	drawCar1RearWheelCover();		
	
	drawCar1RearWheelCenterShaft();
	drawCar1RearWheelRightShaft();	
	drawCar1RearLight();
	drawCar1FrontWheelLeftShaft();
	drawCar1FrontWheel();
	drawCar1FrontWheelCenter();	
	drawCar1FrontWheelCover();	
	drawCar1FrontWheelCenterShaft();
	drawCar1FrontWheelRightShaft();
	drawCar1FrontLight();
	drawCar1FrontWheelMiddleShaft();
	drawCar1LeftHandleBar();
	drawCar1RightHandleBar();	
	drawCar1ExhaustPipe();
	drawCar1OtherShaft();
	drawCar1GasTank();
	drawCar1SeatPart1();
	drawCar1SeatPart2();
	
	glPopMatrix();
}

void Car1::drawCar1FrontWheelCenterShaft()
{
	glPushMatrix();						//Draw shaft in center of front wheel start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.5, 0.5, 0.5);

	glTranslatef(15.0, 0.0, -1.0);
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, shaftTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 2.0f, 10, 20);
	glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();                       //Draw shaft in center of front wheel end
}

void Car1::drawCar1ExhaustPipe()
{
	glPushMatrix();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.5, 0.5, 0.5);    

		glPushMatrix();                    //Draw exhaust pipe front side start                  
		
			glTranslatef(7.5, -0.6, 1.4);
			glRotatef(90, 0.0, 1.0, 0.0);
	
			glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
			gluQuadricDrawStyle(quadratic, GLU_FILL);
			gluQuadricNormals (quadratic, GLU_SMOOTH);
			gluQuadricTexture (quadratic, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, pipeTexture);
			gluCylinder(quadratic, 0.15f, 0.15f, 2.8f, 10, 20); 
			glDisable(GL_TEXTURE_2D);

		glPopMatrix();                     //Draw exhaust pipe front side end

		glPushMatrix();                      //Draw exhaust pipe middle side start
	
			glTranslatef(4.0, -0.55, 1.4);
			glRotatef(90, 0.0, 1.0, 0.0);
			gluCylinder(quadratic, 0.2f, 0.2f, 3.4f, 10, 20); 
		
		glPopMatrix();                     //Draw exhaust pipe middle side start
         
		glPushMatrix();                    //Draw exhaust pipe back side start                  
	
			glTranslatef(-1.8, -0.55, 1.4);
			glRotatef(90, 0.0, 1.0, 0.0);	
			gluCylinder(quadratic, 0.3f, 0.3f, 7.0f, 10, 20); 
	
		glPopMatrix();                     //Draw exhaust pipe back side end
	
		glPushMatrix();                    //Draw pipe front start                 
	
			glTranslatef(10, -0.6, 1.4);
			glRotatef(20, 0.0, 0.0, 1.0);
			glRotatef(90, 0.0, 1.0, 0.0);	
			gluCylinder(quadratic, 0.15f, 0.15f, 1.4f, 10, 20); 
	
		glPopMatrix();                     //Draw pipe front end
	
		glPushMatrix();                    //Draw front slant pipe start                  
	
			glTranslatef(10.3, -0.6, 1.4);
			glRotatef(-20, 1.0, 0.0, 0.0);
			glRotatef(75, 0.0, 0.0, 1.0);
			glRotatef(90, 0.0, 1.0, 0.0);	
			gluCylinder(quadratic, 0.15f, 0.15f, 2.8f, 10, 20); 
	
		glPopMatrix();                     //Draw front slant pipe end
	
		glPushMatrix();                    //Draw back slant pipe start                  
	
			glTranslatef(7.5, -0.55, 1.4);
			glRotatef(-20, 1.0, 0.0, 0.0);
			glRotatef(100, 0.0, 0.0, 1.0);
			glRotatef(90, 0.0, 1.0, 0.0);	
			gluCylinder(quadratic, 0.15f, 0.15f, 2.8f, 10, 20); 		
		
		glPopMatrix();                     //Draw back slant pipe end

	glPopMatrix(); 
}

void Car1::drawCar1OtherShaft()
{
	glPushMatrix();                     //Draw straight shaft start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0);

	glTranslatef(12.2, 5.1, 0);	
	glRotatef(90, 1.0,0.0, 0.0);
	
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluCylinder(quadratic, 0.2f, 0.2f, 1.5f, 10, 20); 

	glPopMatrix();                     //Draw straight shaft end
		
	glPushMatrix();                    //Draw long shaft start      

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0);

	glTranslatef(12.2, 4, 0);	
	glRotatef(-12, 0.0, 0.0, 1);
	glRotatef(90, 1.0,0.0, 0.0);
	
		gluQuadricDrawStyle(quadratic, GLU_FILL);
		gluCylinder(quadratic, 0.2f, 0.2f, 5.3f, 10, 20); 
		
	glPopMatrix();					//Draw long shaft end
	
	glPushMatrix();                 //Draw horizontal bottom shaft connect two pedals start    

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0);

	glTranslatef(8.0, -1.3, 0);	
	glRotatef(90, 0.0,1.0, 0.0);

		gluQuadricDrawStyle(quadratic, GLU_FILL);
		gluCylinder(quadratic, 0.2f, 0.2f, 3.3f, 10, 20); 
		
	glPopMatrix();					//Draw horizontal bottom shaft connect two pedals end 
	
	glPushMatrix();                 //Draw vertical bottom shaft connect two pedals start                 
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(9.3, -1.4, -1);	
	
		gluQuadricDrawStyle(quadratic, GLU_FILL);
		gluCylinder(quadratic, 0.2f, 0.2f, 3.3f, 10, 20); 
	
	glPopMatrix();					//Draw vertical bottom shaft connect two pedals end
}
		
void Car1::drawCar1GasTank()
{
	int counter1 = 0;                     //draw smooth gas tank
	glPushMatrix();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Red);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(1.0, 0.0, 0.0); 

	glTranslatef(6.8, 2.9 , -3.5);
	float x0 = 0.0;
	float y0 = 0.0;
	float z0 = 2.0;
	float x = 0.0;
	float y = 0.0;
	float unitLength = 0.45;

	//Compute the point position
	pointArray1[0] = x0;
	pointArray1[1] = y0;
	counter1 = counter1 + 2;

	for (int angle = 45; angle >= 0; angle = angle - 5)
	{
		x = pointArray1[counter1-2] + unitLength * cos(angle * PI/180);
		y = pointArray1[counter1-1] + unitLength * sin(angle * PI/180);
		counter1 = counter1 + 2;
		
		pointArray1[counter1-2] = x;
		pointArray1[counter1-1] = y;
	}
	
	for (int angle = 45; angle <= 90; angle = angle + 10)
	{
		x = pointArray1[counter1-2] + unitLength * cos(angle * PI/180);
		y = pointArray1[counter1-1] - unitLength * sin(angle * PI/180);

		counter1 = counter1 + 2;

		if(y<0)
		{
			y =0;
			pointArray1[counter1-2] = x;
			pointArray1[counter1-1] = y;
			break;
		}else
		{
			pointArray1[counter1-2] = x;
			pointArray1[counter1-1] = y;
		}
	}
	//compute over
	
	
	glBegin(GL_TRIANGLES);
	glVertex3f(pointArray1[0], pointArray1[1], z0);
	glVertex3f(pointArray1[2], pointArray1[3], z0);
	glVertex3f(pointArray1[2], pointArray1[1], z0);

	glVertex3f(pointArray1[0], pointArray1[1], z0+3);
	glVertex3f(pointArray1[2], pointArray1[3], z0+3);
	glVertex3f(pointArray1[2], pointArray1[1], z0+3);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	glBindTexture (GL_TEXTURE_2D, this->pipeTexture);

	glBegin(GL_QUADS);
	for (int i=2;i<counter1-2;i=i+2)
	{
		glTexCoord2d (0, 0);
		glVertex3f(pointArray1[i], pointArray1[i+1], z0);
		glTexCoord2d (1, 0);
		glVertex3f(pointArray1[i], pointArray1[1], z0);
		glTexCoord2d (1, 1);
		glVertex3f(pointArray1[i+2], pointArray1[1], z0);
		glTexCoord2d (0, 1);
		glVertex3f(pointArray1[i+2], pointArray1[i+3], z0);
	}
	glEnd();

	glBegin(GL_QUADS);
	for (int i=2;i<counter1-2;i=i+2)
	{
		glTexCoord2d (0, 0);
		glVertex3f(pointArray1[i], pointArray1[i+1], z0+3);
		glTexCoord2d (1, 0);
		glVertex3f(pointArray1[i], pointArray1[1], z0+3);
		glTexCoord2d (1, 1);
		glVertex3f(pointArray1[i+2], pointArray1[1], z0+3);
		glTexCoord2d (0, 1);
		glVertex3f(pointArray1[i+2], pointArray1[i+3], z0+3);
	}
	glEnd();

	glBegin(GL_QUADS);
	for (int i=0;i<counter1-2;i=i+2)
	{
		glTexCoord2d (0, 0);
		glVertex3f(pointArray1[i], pointArray1[i+1], z0+3);
			
		glTexCoord2d (1, 0);
		glVertex3f(pointArray1[i+2], pointArray1[i+3], z0+3);
			
		glTexCoord2d (1, 1);
		glVertex3f(pointArray1[i+2], pointArray1[i+3], z0);
		glTexCoord2d (0, 1);
		glVertex3f(pointArray1[i], pointArray1[i+1], z0);
	}
	glEnd();
			
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}
		
void Car1::drawCar1SeatPart1()
{
	glPushMatrix();

		glTranslatef(1.7,3.2 , -2.5);
		int counter1 = 0;                                           //Draw wheel cover

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

		glColor3f(0.5,0.5,0.5); 

		glPushMatrix();

			float x0 = 0.0;
			float y0 = 0.0;
			float z0 = 2.0;
			float x = 0.0;
			float y = 0.0;
			float unitLength = 0.5;

			//Compute the point position
			pointArray1[0] = x0;
			pointArray1[1] = y0;
			counter1 = counter1 + 2;

			for (int angle = 5; angle <= 55; angle = angle + 10)
			{
				x = pointArray1[counter1-2] + unitLength * cos(angle * PI/180);
				y = pointArray1[counter1-1] - unitLength * sin(angle * PI/180);

				counter1 = counter1 + 2;
				{
					pointArray1[counter1-2] = x;
					pointArray1[counter1-1] = y;
				}
			}

			//compute over
	

			glBegin(GL_QUAD_STRIP);
			for (int i=0;i<counter1-2;i=i+2)
			{
				glVertex3f(pointArray1[i], pointArray1[i+1], z0);
				glVertex3f(pointArray1[i], pointArray1[i+1], z0+1);
			}
			glEnd();
	
		glPopMatrix();

		glPushMatrix();
			float upOriginX = 0.0;
			float upOriginY = 0.25;

	
			glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
			glBindTexture (GL_TEXTURE_2D, shaftTexture);	

			glBegin(GL_QUADS);

			for (int i=0;i<counter1-2;i=i+2)
			{
				glTexCoord2d (0, 0);
				glVertex3f(pointArray1[i], pointArray1[i+1], z0);
				glTexCoord2d (1, 0);
				glVertex3f(pointArray1[i], upOriginY, z0);	
				glTexCoord2d (1, 1);
				glVertex3f(pointArray1[i+2], upOriginY, z0);
				glTexCoord2d (0, 1);	
				glVertex3f(pointArray1[i+2], pointArray1[i+3], z0);

				glTexCoord2d (0, 0);
				glVertex3f(pointArray1[i], pointArray1[i+1], z0+1);
				glTexCoord2d (1, 0);
				glVertex3f(pointArray1[i], upOriginY, z0+1);
				glTexCoord2d (1, 1);
				glVertex3f(pointArray1[i+2], upOriginY, z0+1);
				glTexCoord2d (0, 1);	
				glVertex3f(pointArray1[i+2], pointArray1[i+3], z0+1);
			}

			glTexCoord2d (0, 0);
			glVertex3f(pointArray1[0], pointArray1[1], z0);	
			glTexCoord2d (1, 0);
			glVertex3f(pointArray1[0], pointArray1[1], z0+1);
			glTexCoord2d (1, 1);
			glVertex3f(0,upOriginY,z0+1);
			glTexCoord2d (0, 1);	
			glVertex3f(0,upOriginY,z0);

			glTexCoord2d (0, 0);
			glVertex3f(pointArray1[counter1-2],pointArray1[counter1-1], z0);	
			glTexCoord2d (1, 0);
			glVertex3f(pointArray1[counter1-2],pointArray1[counter1-1], z0+1);
			glTexCoord2d (1, 1);
			glVertex3f(pointArray1[counter1-2], upOriginY,z0+1);
			glTexCoord2d (0, 1);
			glVertex3f(pointArray1[counter1-2], upOriginY,z0);

			glTexCoord2d (0, 0);
			glVertex3f(0,upOriginY,z0);
			glTexCoord2d (1, 0);
			glVertex3f(0,upOriginY,z0+1);
			glTexCoord2d (1, 1);
			glVertex3f(pointArray1[counter1-2], upOriginY,z0+1);
			glTexCoord2d (0, 1);
			glVertex3f(pointArray1[counter1-2], upOriginY,z0);

			glEnd();

			glDisable(GL_TEXTURE_2D);

		glPopMatrix();

	glPopMatrix();
}
		
void Car1::drawCar1SeatPart2()
{
	int counter1 = 0;                     
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.5, 0.5, 0.5); 

	glTranslatef(7.29, 3.55 , -2.5);
	
	glRotatef(180,0, 0 , 1);
	
	float x0 = 0.0;
	float y0 = 0.0;
	float z0 = 2.0;
	float x = 0.0;
	float y = 0.0;
	float unitLength = 0.3;

	//Compute the point position
	pointArray1[0] = x0;
	pointArray1[1] = y0;
	counter1 = counter1 + 2;

	for (int angle = 45; angle >= 0; angle = angle - 5)
	{
		x = pointArray1[counter1-2] + unitLength * cos(angle * PI/180);
		y = pointArray1[counter1-1] + unitLength * sin(angle * PI/180);
		counter1 = counter1 + 2;
		
		pointArray1[counter1-2] = x;
		pointArray1[counter1-1] = y;
	}
	
	for (int angle = 45; angle <= 90; angle = angle + 15)
	{
		x = pointArray1[counter1-2] + unitLength * cos(angle * PI/180);
		y = pointArray1[counter1-1] - unitLength * sin(angle * PI/180);

		counter1 = counter1 + 2;

		if(y<0)
		{
			y =0;
			pointArray1[counter1-2] = x;
			pointArray1[counter1-1] = y;
			break;
		}else
		{
			pointArray1[counter1-2] = x;
			pointArray1[counter1-1] = y;
		}
	}
	//compute over
	
		glBegin(GL_TRIANGLES);
		glVertex3f(pointArray1[0], pointArray1[1], z0);
		glVertex3f(pointArray1[2], pointArray1[3], z0);
		glVertex3f(pointArray1[2], pointArray1[1]*1/2, z0);

		glVertex3f(pointArray1[0], pointArray1[1], z0+1);
		glVertex3f(pointArray1[2], pointArray1[3], z0+1);
		glVertex3f(pointArray1[2], pointArray1[1]*1/2, z0+1);
		glEnd();

		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
		glBindTexture (GL_TEXTURE_2D, cargoTexture);

		glBegin(GL_QUADS);
		for (int i=2;i<counter1-2;i=i+2)
		{
			glTexCoord2d (0, 0);
			glVertex3f(pointArray1[i], pointArray1[i+1], z0);
			glTexCoord2d (1, 0);
			glVertex3f(pointArray1[i], pointArray1[i+1]*1/2, z0);
			glTexCoord2d (1, 1);
			glVertex3f(pointArray1[i+2], pointArray1[i+3]*1/2, z0);
			glTexCoord2d (0, 1);	
			glVertex3f(pointArray1[i+2], pointArray1[i+3], z0);
		}
		glEnd();
		
		glBegin(GL_QUADS);
		for (int i=2;i<counter1-2;i=i+2)
		{
			glTexCoord2d (0, 0);
			glVertex3f(pointArray1[i], pointArray1[i+1], z0+1);
			glTexCoord2d (1, 0);
			glVertex3f(pointArray1[i], pointArray1[i+1]*1/2, z0+1);
			glTexCoord2d (1, 1);
			glVertex3f(pointArray1[i+2], pointArray1[i+3]*1/2, z0+1);
			glTexCoord2d (0, 1);	
			glVertex3f(pointArray1[i+2], pointArray1[i+3], z0+1);
		}
		glEnd();
		
		glBegin(GL_QUAD_STRIP);
		for (int i=0;i<counter1-2;i=i+2)
		{
			glVertex3f(pointArray1[i], pointArray1[i+1], z0);
			glVertex3f(pointArray1[i], pointArray1[i+1], z0+1);
		}
		glEnd();
		
		glBegin(GL_QUADS);
		for (int i=0;i<counter1-2;i=i+2)
		{
			glTexCoord2d (0, 0);
			glVertex3f(pointArray1[i], pointArray1[i+1]*1/2, z0);
			glTexCoord2d (1, 0);
			glVertex3f(pointArray1[i], pointArray1[i+1]*1/2, z0+1);
			glTexCoord2d (1, 1);
			glVertex3f(pointArray1[i+2], pointArray1[i+3]*1/2, z0+1);
			glTexCoord2d (0, 1);	
			glVertex3f(pointArray1[i+2], pointArray1[i+3]*1/2, z0);
		}
		glEnd();

		glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();
}

void Car1::drawCar1FrontWheelRightShaft()
{
	glPushMatrix();                      //Draw right shaft to connect with front wheel start    

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(15.0, 0.0, 1.0);
	glRotatef(30, 0.0, 0.0, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0); 
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, shaftTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 8.0f, 10, 20);
	glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();                       //Draw right shaft to connect with front wheel end
}

void Car1::drawCar1FrontLight()
{
	glPushMatrix();                                       //Draw front light start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Red);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(13.0, 6.0 * cos(30 * PI/180), 0.0);
	glRotatef(90, 0.0, 0.0, 1.0);
	int radius = 1.0;
	int verticalSlice = 10; 
	int horizontalSlice = 10; 
	for(int i = 0; i < verticalSlice; i++)
	{	//int wire = 1;  //1 for Wire frame, 0 for Shaded Model
		
		glBegin(GL_TRIANGLE_STRIP);			
		

		for(int j = 0; j <= horizontalSlice; j++)
		{
			glVertex3f( radius * cos( (float)(i+1)/verticalSlice * PI/2.0 ) * cos( 2.0 * (float)j/horizontalSlice * PI ),
						radius * sin( (float)(i+1)/verticalSlice * PI/2.0 ),
						radius * cos( (float)(i+1)/verticalSlice * PI/2.0 ) * sin( 2.0 * (float)j/horizontalSlice * PI ) );
			glVertex3f( radius * cos( (float)i/verticalSlice * PI/2.0 ) * cos( 2.0 * (float)j/horizontalSlice * PI ),
						radius * sin( (float)i/verticalSlice * PI/2.0 ),
						radius * cos( (float)i/verticalSlice * PI/2.0 ) * sin( 2.0 * (float)j/horizontalSlice * PI ) );         
		}
		glEnd();
	}
	float t = 0;
	glRotatef(90, 1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);							
	for(int i = 0; i < 10; ++i)
	{
		glVertex3f(radius * cos(t), radius * sin(t), 0.0);
		t += 2 * PI / 10;
	}
	glEnd();
	glPopMatrix();                                    //Draw front light end
}
		
void Car1::drawCar1FrontWheelMiddleShaft()
{
	glPushMatrix();                     //Draw middle shaft to connect with front wheel start      

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.5, 0.5, 0.5); 
	glTranslatef(11.0, 8.0 * cos(30 * PI/180), -4.0);
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, shaftTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 8.0f, 10, 20);
	glDisable(GL_TEXTURE_2D);
		
	glPopMatrix();                      //Draw middle shaft to connect with front wheel end
}
		
void Car1::drawCar1LeftHandleBar()
{
	glPushMatrix();						//Draw left handle bar start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0); 
	glTranslatef(11.0, 8.0 * cos(30 * PI/180), -4.0);
	glRotatef(-150, 0.0, 1.0, 0.0);

	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluCylinder(quadratic, 0.5f, 0.5f, 2.0f, 10, 20);
	
	glPopMatrix();                     //Draw left handle bar end
}
		
void Car1::drawCar1RightHandleBar()
{
	glPushMatrix();                    //Draw right handle bar start    

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(11.0, 8.0 * cos(30 * PI/180), 4.0);
	glRotatef(-30, 0.0, 1.0, 0.0);
	
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluCylinder(quadratic, 0.5f, 0.5f, 2.0f, 10, 20); // right handle bar
		
	glPopMatrix();                      //Draw right handle bar end 
}

void Car1::drawCar1FrontWheel()
{
	glPushMatrix();                      //Draw front wheel start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

  	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(15.0, 0.0, 0);
	glRotatef(-0 * 180 / PI, 0.0, 0.0, 1.0);
	//glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	
	glutSolidTorus(0.5, 2.0, 10, 20);  
	
	glPopMatrix();                       //Draw front wheel end
}

void Car1::drawCar1FrontWheelLeftShaft()
{
	glPushMatrix();						//Draw left shaft to connect with front wheel start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(15.0, 0.0, -1.0);
	glRotatef(30, 0.0, 0.0, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0); 
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, shaftTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 8.0f, 10, 20);
	glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();                       //Draw left shaft to connect with front wheel end
}

void Car1::drawCar1FrontWheelCenter()
{
	glPushMatrix();
	glTranslatef(15.0f, 0.0f, 0.0f);
	glRotatef(-0 * 180 / PI, 0.0, 0.0, 1.0);
	//glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	drawCar1WheelCenter();
	glPopMatrix();
}

void Car1::drawCar1FrontWheelCover()
{
	int counter1 = 0;                                           //Draw wheel cover start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Red);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(1.0, 0.0, 0.0); 
	
	float x0 = 0.0;
	float y0 = 0.0;
	float z0 = 2.0;
	float x = 0.0;
	float y = 0.0;
	float unitLength = 0.5;
            
	glPushMatrix();
	glTranslatef(12, 0.3 , -2.5);

	//Compute the point position
	pointArray1[0] = x0;
	pointArray1[1] = y0;
	counter1 = counter1 + 2;

	for (int angle = 80; angle >= 0; angle = angle - 10)
	{
		
		x = pointArray1[counter1-2] + unitLength * cos(angle * PI/180);
		y = pointArray1[counter1-1] + unitLength * sin(angle * PI/180);
		counter1 = counter1 + 2;
		
		pointArray1[counter1-2] = x;
		pointArray1[counter1-1] = y;
	}
	
	for (int angle = 5; angle <= 90; angle = angle + 10)
	{
		
		x = pointArray1[counter1-2] + unitLength * cos(angle * PI/180);
		y = pointArray1[counter1-1] - unitLength * sin(angle * PI/180);

		counter1 = counter1 + 2;

		if(y<0)
		{
			y =0;
			pointArray1[counter1-2] = x;
			pointArray1[counter1-1] = y;
			break;
		}else
		{
			pointArray1[counter1-2] = x;
			pointArray1[counter1-1] = y;
		}

	
	}

	//compute over
	
	
	glBegin(GL_QUAD_STRIP);
	for (int i=0;i<counter1-2;i=i+2)
	{
		glVertex3f(pointArray1[i], pointArray1[i+1], z0);
		glVertex3f(pointArray1[i], pointArray1[i+1], z0+1);
	}
	glEnd();

	
	glPopMatrix();                                             //Draw wheel cover end
}

void Car1::drawCar1RearWheelCenterShaft()
{
	glPushMatrix();						//Draw shaft in center of front wheel start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(1.6, 0.0, -1.0);
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, shaftTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 2.0f, 10, 20);
	glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();                       //Draw shaft in center of front wheel end
}
		
void Car1::drawCar1RearWheelRightShaft()
{
	glPushMatrix();                    //Draw rear wheel right shaft start         

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(3.4, 2.4, 1.0);
	glRotatef(-40, 0.0, 0.0, 1);
	glRotatef(90, 1.0,0.0, 0.0);
	
	//gluQuadricDrawStyle(quadratic, GLU_FILL);
	//gluCylinder(quadratic, 0.3f, 0.2f, 3.10f, 10, 20); 	

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, shaftTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 3.1f, 10, 20);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();                     //Draw rear wheel right shaft end
}
		
void Car1::drawCar1RearLight()
{
	glPushMatrix();                                       //Draw rear light start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Red);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(2.1, -3.5, 0.0);
	glTranslatef(-3.0, 7.0 * cos(30 * PI/180), 0.0);
	glRotatef(-92, 0.0, 0.0, 1.0);
	float radius = 0.6;
	int verticalSlice = 10; 
	int horizontalSlice = 10; 
	for(int i = 0; i < verticalSlice; i++)
	{	//int wire = 1;  //1 for Wire frame, 0 for Shaded Model
		
		glBegin(GL_TRIANGLE_STRIP);			
		

		for(int j = 0; j <= horizontalSlice; j++)
		{
			glVertex3f( radius * cos( (float)(i+1)/verticalSlice * PI/2.0 ) * cos( 2.0 * (float)j/horizontalSlice * PI ),
						radius * sin( (float)(i+1)/verticalSlice * PI/2.0 ),
						radius * cos( (float)(i+1)/verticalSlice * PI/2.0 ) * sin( 2.0 * (float)j/horizontalSlice * PI ) );
			glVertex3f( radius * cos( (float)i/verticalSlice * PI/2.0 ) * cos( 2.0 * (float)j/horizontalSlice * PI ),
						radius * sin( (float)i/verticalSlice * PI/2.0 ),
						radius * cos( (float)i/verticalSlice * PI/2.0 ) * sin( 2.0 * (float)j/horizontalSlice * PI ) );         
		}
		glEnd();
	}
	float t = 0;
	glRotatef(90, 1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);							
	for(int i = 0; i < 10; ++i)
	{
		glVertex3f(radius * cos(t), radius * sin(t), 0.0);
		t += 2 * PI / 10;
	}
	glEnd();
	glPopMatrix();                                    //Draw rear light end
}

void Car1::drawCar1WheelCenter()
{
	glPushMatrix();

	glColor3f(1.0f, 1.0f, 1.0f);
	
	float radius = 1.4;
	int colorChoice = 0;
	
	float circleX = 0;
	float circleY = 0;
	float centerX = 0;
	float centerY = 0;

	glBegin(GL_TRIANGLE_FAN);
	
	glVertex3f(centerX,centerY,0.0f);
	for(float angle = 0.0f; angle <= 720; angle = angle + 60)
	{
		circleX = radius*cos(angle*3.14159265/360)+centerX;
		circleY = radius*sin(angle*3.14159265/360)+centerY;
	
		if((colorChoice %2) == 0)
		{
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_White);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_White);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_White);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
			glColor3f(1.0f, 1.0f, 1.0f);
		}
		else
		{
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
			glColor3f(0.0f, 0.0f, 0.0f);
		}
			
		colorChoice++;

		glVertex3f(circleX, circleY,0);
	}

	glEnd();
	glPopMatrix();
}

void Car1::drawCar1RearWheelCenter()
{
	glPushMatrix();
	glTranslatef(1.6f, 0.0f, 0.0f);
	glRotatef(-0 * 180 / 3.14159265, 0.0, 0.0, 1.0);
	//glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	drawCar1WheelCenter();
	glPopMatrix();
}

void Car1::drawCar1RearWheelCover()
{
	int counter1 = 0;                                           //Draw wheel cover

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Red);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(1.0, 0.0, 0.0); 
	
	float x0 = 0.0;
	float y0 = 0.0;
	float z0 = 2.0;
	float x = 0.0;
	float y = 0.0;
	float unitLength = 0.5;
            
	glPushMatrix();
	glTranslatef(-1.4, 0.5 , -2.5);

	//Compute the point position
	pointArray1[0] = x0;
	pointArray1[1] = y0;
	counter1 = counter1 + 2;

	for (int angle = 80; angle >= 0; angle = angle - 10)
	{
		
		x = pointArray1[counter1-2] + unitLength * cos(angle * PI/180);
		y = pointArray1[counter1-1] + unitLength * sin(angle * PI/180);
		counter1 = counter1 + 2;
		
		pointArray1[counter1-2] = x;
		pointArray1[counter1-1] = y;
	}
	
	for (int angle = 5; angle <= 90; angle = angle + 10)
	{
		
		x = pointArray1[counter1-2] + unitLength * cos(angle * PI/180);
		y = pointArray1[counter1-1] - unitLength * sin(angle * PI/180);

		counter1 = counter1 + 2;

		if(y<0)
		{
			y =0;
			pointArray1[counter1-2] = x;
			pointArray1[counter1-1] = y;
			break;
		}else
		{
			pointArray1[counter1-2] = x;
			pointArray1[counter1-1] = y;
		}

	
	}

	//compute over

	glBegin(GL_QUAD_STRIP);
	for (int i=0;i<counter1-2;i=i+2)
	{
		glVertex3f(pointArray1[i], pointArray1[i+1], z0);
		glVertex3f(pointArray1[i], pointArray1[i+1], z0+1);
	}
	glEnd();

	
	glPopMatrix();
}		

void Car1::drawCar1RearWheelLeftShaft()
{
	glPushMatrix();                    //Draw rear wheel left shaft start                  

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(3.4, 2.4, -1);
	glRotatef(-40, 0.0, 0.0, 1);
	glRotatef(90, 1.0,0.0, 0.0);

	//gluQuadricDrawStyle(quadratic, GLU_FILL);
	//gluCylinder(quadratic, 0.3f, 0.2f, 3.10f, 10, 20); 

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, shaftTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 3.1f, 10, 20);
	glDisable(GL_TEXTURE_2D);
		

	glPopMatrix();                     //Draw rear wheel left shaft end
}

void Car1::drawCar1RearWheel()
{
	glPushMatrix();                      //Draw rear wheel start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

  	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(1.6, 0.0, 0);
	glRotatef(-0 * 180 / 3.14159265, 0.0, 0.0, 1.0);
	//glRotatef(-wheelRotateAngle * 180 / 3.14159265, 0.0, 0.0, 1.0);
	glutSolidTorus(0.5, 2.0, 10, 20);  
	
	glPopMatrix();                       //Draw rear wheel end
}

void Car1::drawCar1LeftPedalShaft()
{
	glPushMatrix();						//Draw shaft between engine and left pedal start    
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(9.3, -1.4, -3.0);
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluCylinder(quadratic, 0.3f, 0.3f, 2.0f, 10, 20);
	
	glPopMatrix();                       //Draw shaft between engine and left pedal end
}

void Car1::drawCar1LeftPedal()
{
	glPushMatrix();						//Draw left pedal start  

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0);
	
  	glTranslatef(9.3f, -1.4, -3);
	glScalef(2.2, 0.2, 0.9);
	glutSolidCube(1);  

	glPopMatrix();                        //Draw left pedal end
}

void Car1::drawCar1RightPedalShaft()
{
	glPushMatrix();                      //Draw shaft between engine and right pedal start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0);  
	glTranslatef(9.3, -1.4, 1.0);
	
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluCylinder(quadratic, 0.3f, 0.3f, 2, 10, 20);
	
	glPopMatrix();                       //Draw shaft between engine and right pedal end
}

void Car1::drawCar1RightPedal()
{
	glPushMatrix();                      //Draw right pedal start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0);
  	glTranslatef(9.3f, -1.4, 3);
	glScalef(2.2, 0.2, 0.9);
	
	glutSolidCube(1);  
	
	glPopMatrix();                        //Draw right pedal end
}

void Car1::drawCar1Engine()
{
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_DarkGrey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_DarkGrey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_DarkGrey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.4, 0.4, 0.4);
	
	glPushMatrix();                      //bottom retangle box   
	glTranslatef(9.2f, 0, 0);
	glScalef(1.0, 1.2, 1);
	
	glutSolidCube(1);  
	
	glPopMatrix();    
		
	glPushMatrix();                     //Top 2 retangle box (right)  
  	glTranslatef(10.5f, 2.46, 0);
	glRotatef(-10,0.0,0.0,1.0);
	glScalef(1.0, 0.3, 1);
	
	glutSolidCube(2);  
	
	glPopMatrix();     

	glPushMatrix();                     //Top 2 retangle box (left)  
  	glTranslatef(7.8f, 2.46, 0);
	glRotatef(10,0.0,0.0,1.0);
	glScalef(1.0, 0.3, 1);
	
	glutSolidCube(2);  
	
	glPopMatrix();                    

	glPushMatrix();                      //middle 2 retangle box (right)  
  	glTranslatef(10.3f, 1.15, 0);
	glRotatef(-10,0.0,0.0,1.0);
	glScalef(0.6, 1, 1);
	
	glutSolidCube(2);  
	
	glPopMatrix();     

	glPushMatrix();                      //middle 2 retangle box (left)  
  	glTranslatef(8.1f, 1.15, 0);
	glRotatef(10,0.0,0.0,1.0);
	glScalef(0.6, 1, 1);
	
	glutSolidCube(2);  
	
	glPopMatrix();  
	
	glPushMatrix();                      

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_LightGrey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_LightGrey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_LightGrey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

  	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(9.2, 1.6, 0);
	
	glutSolidTorus(0.3, 0.5, 10, 20);  
	
	glPopMatrix();  
}

void Car1::drawCar1ToolBox()
{
	glPushMatrix();                      //Draw toolbox start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.0, 0.0, 0.0);
	
  	glTranslatef(5.6f, 1.4, 0);
	glRotatef(10,0, 0, 1);
	glScalef(0.8f, 0.7f, 0.67);
	
	glutSolidCube(3);  
	
	glPopMatrix();                       //Draw toolbox end

	glPushMatrix();                      //Draw toolbox start
  	glTranslatef(5.6f, -0.2f, 0);
	glRotatef(10,0, -0.5, 1);
	glScalef(1.5f, 1.0f, 1.0f);
	
	glutSolidCube(1);  
	
	glPopMatrix();                       //Draw toolbox end
}

void Car1::drawCar1TrailerAndHitch()
{
	drawCar1TrailerHitch();
	drawCar1TrailerHitchArm();
	drawCar1Trailer();
}

void Car1::drawCar1TrailerHitch()
{
	glPushMatrix();                      //Draw hitch base(retangle) start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.0, 0.0, 0.0);

  	glTranslatef(-1.5, 1.2, 0);
	glScalef(0.6, 0.2, 0.6);
	
	glutSolidCube(1);  
	
	glPopMatrix();                        //Draw hitch base(retangle) end
 
	glPushMatrix();						//Draw hitch cap start
	glTranslatef(-1.5, 1.2, 0.0);
	glRotatef(-90, 1.0, 0.0, 0.0); 
	
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluCylinder(quadratic, 0.2f, 0.1f, 0.8f, 10, 20);
	
	glPopMatrix();                       //Draw hitch cap end
}

void Car1::drawCar1TrailerHitchArm()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Red);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(1.0, 0.0, 0.0);

	glPushMatrix();                      
  	glTranslatef(-1.5, 1.4, 0);
	glRotatef(90, 1.0, 0.0, 0.0);
	
	glutSolidTorus(0.1, 0.3, 3, 10);  
	
	glPopMatrix();  

	glPushMatrix();     
	glTranslatef(-7, 1.0, 0.0);
	glRotatef(4, 0.0, 0.0, 1.0); 
	glRotatef(90, 0.0, 1.0, 0.0); 

	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluCylinder(quadratic, 0.1f, 0.1f, 5.2f, 10, 20);
	
	glPopMatrix();                       
}

void Car1::drawCar1TrailerLeftWheel()
{
	glPushMatrix();                      //Draw trailer left wheel start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

  	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-21.0, 0.0, -7);
	glRotatef(-0 * 180 / PI, 0.0, 0.0, 1.0);
	//glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	
	glutSolidTorus(0.5, 2.0, 10, 20);  
	
	glPopMatrix();                       //Draw trailer left wheel end
}

float Car1::drawCar1TrailerLeftWheelCover()
{
	int counter1 = 0;                                           //Draw wheel cover start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Red);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(1.0, 0.0, 0.0); 
	
	float x0 = 0.0;
	float y0 = 0.0;
	float z0 = 2.0;
	float x = 0.0;
	float y = 0.0;
	float unitLength = 0.5;
            
	glPushMatrix();
	glTranslatef(-24, 0.3 , -9.5);

	//Compute the point position
	pointArray1[0] = x0;
	trailerKeyPoint[0] = pointArray1[0];

	pointArray1[1] = y0;
	trailerKeyPoint[1] = pointArray1[1];

	counter1 = counter1 + 2;

	for (int angle = 80; angle >= 0; angle = angle - 10)
	{
		x = pointArray1[counter1-2] + unitLength * cos(angle * PI/180);
		y = pointArray1[counter1-1] + unitLength * sin(angle * PI/180);
		counter1 = counter1 + 2;
		
		pointArray1[counter1-2] = x;
		pointArray1[counter1-1] = y;
	}
	
	for (int angle = 5; angle <= 90; angle = angle + 10)
	{
		x = pointArray1[counter1-2] + unitLength * cos(angle * PI/180);
		y = pointArray1[counter1-1] - unitLength * sin(angle * PI/180);

		counter1 = counter1 + 2;

		if(y<0)
		{
			y =0;
			pointArray1[counter1-2] = x;
			pointArray1[counter1-1] = y;
			break;
		}else
		{
			pointArray1[counter1-2] = x;
			pointArray1[counter1-1] = y;
		}
	}

	trailerKeyPoint[2] = pointArray1[counter1-2];
	trailerKeyPoint[3] = pointArray1[counter1-1];

	//compute over
	
	
		glBegin(GL_QUAD_STRIP);
		for (int i=0;i<counter1-2;i=i+2)
		{
			glVertex3f(pointArray1[i], pointArray1[i+1], z0);
			glVertex3f(pointArray1[i], pointArray1[i+1], z0+1);
		}
		glEnd();
		glBegin(GL_QUADS);
		glVertex3f(trailerKeyPoint[2],trailerKeyPoint[3],z0);
		glVertex3f(trailerKeyPoint[2]+5,trailerKeyPoint[3],z0);
		glVertex3f(trailerKeyPoint[2]+5,trailerKeyPoint[3], z0+1);
		glVertex3f(trailerKeyPoint[2],trailerKeyPoint[3], z0+1);
		glEnd();
	
	glPopMatrix();                                             //Draw wheel cover end

	return z0 + 1;
}

void Car1::drawCar1TrailerLeftWheelCenter()
{
	glPushMatrix();
	glTranslatef(-21.0f, 0.0f, -7.0f);
	glRotatef(-0 * 180 / PI, 0.0, 0.0, 1.0);
	//glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	drawCar1WheelCenter();
	glPopMatrix();
}

void Car1::drawCar1TrailerWheelCenterShaft()
{
	glPushMatrix();						//Draw shaft in center of front wheel start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.5, 0.5, 0.5);

	glTranslatef(-21, 0.0, -7.0);

		gluQuadricDrawStyle(quadratic, GLU_FILL);
		gluCylinder(quadratic, 0.3f, 0.3f, 14.0f, 10, 20);
	
	glPopMatrix();                       //Draw shaft in center of front wheel end
}

void Car1::drawCar1Cargo()
{
	int counter1 = 0;                     //draw cargo
	glPushMatrix();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_LightGrey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_LightGrey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_LightGrey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.7, 0.7, 0.7); 
	glTranslatef(-13.4, 0.5 , 8.4);
	
	
	glRotatef(180, 0.0, 1.0, 0.0); 
	
	float x0 = 0.0;
	float y0 = 0.0;
	float z0 = 2.0;
	float x = 0.0;
	float y = 0.0;
	float unitLength = 0.8;

	//Compute the point position
	pointArray1[0] = x0;
	pointArray1[1] = y0;
	counter1 = counter1 + 2;

	for (int angle = 45; angle >= 0; angle = angle - 5)
	{
		x = pointArray1[counter1-2] + unitLength * cos(angle * PI/180);
		y = pointArray1[counter1-1] + unitLength * sin(angle * PI/180);
		counter1 = counter1 + 2;
		
		pointArray1[counter1-2] = x;
		pointArray1[counter1-1] = y;
	}

	for (int angle = 45; angle <= 90; angle = angle + 10)
	{
		x = pointArray1[counter1-2] + unitLength * cos(angle * PI/180);
		y = pointArray1[counter1-1] - unitLength * sin(angle * PI/180);

		counter1 = counter1 + 2;

		if(y<0)
		{
			y =0;
			pointArray1[counter1-2] = x;
			pointArray1[counter1-1] = y;
			break;
		}else
		{
			pointArray1[counter1-2] = x;
			pointArray1[counter1-1] = y;
		}
	}
	
	//compute over
	
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	glBindTexture (GL_TEXTURE_2D, this->cargoTexture);	


	glBegin(GL_TRIANGLES);

	glTexCoord2d (0, 0);
	glVertex3f(pointArray1[0], pointArray1[1], z0);
	glTexCoord2d (1, 0);
	glVertex3f(pointArray1[2], pointArray1[3], z0);
	glTexCoord2d (1, 1);
	glVertex3f(pointArray1[2], pointArray1[1], z0);

	glVertex3f(pointArray1[0], pointArray1[1], z0+13);
	glVertex3f(pointArray1[2], pointArray1[3], z0+13);
	glVertex3f(pointArray1[2], pointArray1[1], z0+13);
	glEnd();

	glBegin(GL_QUADS);
	for (int i=0;i<counter1-2;i=i+2)
	{
			
		glTexCoord2d (0, 0);
		glVertex3f(pointArray1[i], pointArray1[1], z0);
		glTexCoord2d (1, 0);
		glVertex3f(pointArray1[i+2], pointArray1[1], z0);
		glTexCoord2d (1, 1);
		glVertex3f(pointArray1[i+2], pointArray1[i+1], z0);
		glTexCoord2d (0, 1);	
		glVertex3f(pointArray1[i], pointArray1[i+1], z0);
	}
	glEnd();

	glBegin(GL_QUADS);
	for (int i=0;i<counter1-2;i=i+2)
	{
			
		glTexCoord2d (0, 0);
		glVertex3f(pointArray1[i], pointArray1[1], z0+13);
		glTexCoord2d (1, 0);
		glVertex3f(pointArray1[i+2], pointArray1[1], z0+13);
		glTexCoord2d (1, 1);
		glVertex3f(pointArray1[i+2], pointArray1[i+1], z0+13);
		glTexCoord2d (0, 1);	
		glVertex3f(pointArray1[i], pointArray1[i+1], z0+13);
	}
	glEnd();

	glBegin(GL_QUADS);
	for (int i=0;i<counter1-2;i=i+2)
	{
			
		glTexCoord2d (0, 0);
		glVertex3f(pointArray1[i], pointArray1[i+1], z0+13);
		glTexCoord2d (1, 0);
		glVertex3f(pointArray1[i+2], pointArray1[i+3], z0+13);
		glTexCoord2d (1, 1);
		glVertex3f(pointArray1[i+2], pointArray1[i+3], z0);
		glTexCoord2d (0, 1);	
		glVertex3f(pointArray1[i], pointArray1[i+1], z0);
	}
	glEnd();
		
	glBegin(GL_QUAD_STRIP);
	for (int i=0;i<counter1-2;i=i+2)
	{
		glVertex3f(pointArray1[i], pointArray1[1], z0);
		glVertex3f(pointArray1[i], pointArray1[1], z0+13);
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);
		
	
	glPopMatrix();
}

void Car1::drawCar1TrailerRightWheel()
{
	glPushMatrix();                      //Draw trailer right wheel start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

  	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-21.0, 0.0, 7);
	glRotatef(-0 * 180 / PI, 0.0, 0.0, 1.0);
	//glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	
		glutSolidTorus(0.5, 2.0, 10, 20);  
	
	glPopMatrix();                       //Draw trailer right wheel end
}

void Car1::drawCar1TrailerRightWheelCenter()
{
	glPushMatrix();
	glTranslatef(-21.0f, 0.0f, 7.0f);
	glRotatef(-0 * 180 / PI, 0.0, 0.0, 1.0);
	//glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	drawCar1WheelCenter();
	glPopMatrix();
}

float Car1::drawCar1TrailerRightWheelCover()
{
	int counter1 = 0;                                           //Draw wheel cover start

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Red);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	 
	glColor3f(1.0, 0.0, 0.0); 

	float x0 = 0.0;
	float y0 = 0.0;
	float z0 = 2.0;
	float x = 0.0;
	float y = 0.0;
	float unitLength = 0.5;
            
	glPushMatrix();
	glTranslatef(-24, 0.3 , 4.5);

	//Compute the point position
	pointArray1[0] = x0;
	trailerKeyPoint[4] = pointArray1[0];
	pointArray1[1] = y0;
	trailerKeyPoint[5] = pointArray1[1];
	counter1 = counter1 + 2;
	
	for (int angle = 80; angle >= 0; angle = angle - 10)
	{
		x = pointArray1[counter1-2] + unitLength * cos(angle * PI/180);
		y = pointArray1[counter1-1] + unitLength * sin(angle * PI/180);
		counter1 = counter1 + 2;
		
		pointArray1[counter1-2] = x;
		
		pointArray1[counter1-1] = y;
	}
	
	for (int angle = 5; angle <= 90; angle = angle + 10)
	{
		x = pointArray1[counter1-2] + unitLength * cos(angle * PI/180);
		y = pointArray1[counter1-1] - unitLength * sin(angle * PI/180);

		counter1 = counter1 + 2;

		if(y<0)
		{
			y =0;
			pointArray1[counter1-2] = x;
			pointArray1[counter1-1] = y;
			break;
		}else
		{
			pointArray1[counter1-2] = x;
			pointArray1[counter1-1] = y;
		}

		trailerKeyPoint[6] = pointArray1[counter1-2];
		trailerKeyPoint[7] = pointArray1[counter1-1];
	}

	//compute over
	
	
		glBegin(GL_QUAD_STRIP);
		for (int i=0;i<counter1-2;i=i+2)
		{
			glVertex3f(pointArray1[i], pointArray1[i+1], z0);
			glVertex3f(pointArray1[i], pointArray1[i+1], z0+1);
		}
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(trailerKeyPoint[6],trailerKeyPoint[7],z0);
		glVertex3f(trailerKeyPoint[6]+5,trailerKeyPoint[7],z0);
		glVertex3f(trailerKeyPoint[6]+5,trailerKeyPoint[7], z0+1);
		glVertex3f(trailerKeyPoint[6],trailerKeyPoint[7], z0+1);
		glEnd();
	
	glPopMatrix();                                             //Draw wheel cover end

	return z0;
}
		
void Car1::drawCar1Trailer()
{
	drawCar1TrailerLeftWheel();
	drawCar1TrailerLeftWheelCenter();
	float leftZ = drawCar1TrailerLeftWheelCover();
	drawCar1TrailerWheelCenterShaft();
	drawCar1Cargo();
	drawCar1TrailerRightWheel();
	drawCar1TrailerRightWheelCenter();
	float rightZ = drawCar1TrailerRightWheelCover();
	
	glPushMatrix();                      

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Red);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

  	glColor3f(1.0, 0.0, 0.0);
	
		glBegin(GL_TRIANGLES);
		glVertex3f(trailerKeyPoint[2]-19, trailerKeyPoint[3]+0.3, leftZ-9.5);						
		glVertex3f(trailerKeyPoint[2]-19, trailerKeyPoint[3]+0.3, leftZ-9.5-1);						
		glVertex3f(trailerKeyPoint[2]-19+5, trailerKeyPoint[3]+0.3+0.8, (leftZ-9.5+rightZ+4.5)/2);

		glVertex3f(trailerKeyPoint[6]-19, trailerKeyPoint[7]+0.3, rightZ+5.5);						
		glVertex3f(trailerKeyPoint[6]-19, trailerKeyPoint[7]+0.3, rightZ+5.5-1);						
		glVertex3f(trailerKeyPoint[2]-19+5, trailerKeyPoint[3]+0.3+0.8, (leftZ-9.5+rightZ+4.5)/2);
		glEnd();
	
	glPopMatrix();    

	glPushMatrix();          

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Red);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Red);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(1.0, 0.0, 0.0);
  	glTranslatef(-7.3, 0.3+0.8, 0);
	glScalef(1, 0.7, 2);
	
		glutSolidCube(1);  
	
	glPopMatrix();   
}