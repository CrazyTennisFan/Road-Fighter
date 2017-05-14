#include "Bus.h"
#include <GL/glut.h>
#include <math.h>




Bus::Bus(int back, int front, int left, int right, float x, float y, float z)
	:back(back), front(front), left(left), right(right), speed(0.25), length(30), width(15), posX(x), posY(y), posZ(z)
{
	PI = 3.14159265;
	quadratic = gluNewQuadric();
	rotation_wheel = 2;

	material_Black[0] = 0.0;
	material_Black[1] = 0.0;
	material_Black[2] = 0.0;
	material_Black[3] = 1.0;

	material_White[0] = 1.0;
	material_White[1] = 1.0;
	material_White[2] = 1.0;
	material_White[3] = 1.0;

	material_Grey[0] = 0.3;
	material_Grey[1] = 0.3;
	material_Grey[2] = 0.3;
	material_Grey[3] = 1.0;

	materialShininess = 50.0;
}

Bus::~Bus()
{
}

float Bus::getSpeed()
{
	return speed;
}

void Bus::setSpeed(float s)
{
	speed = s;
}

float Bus::getLength()
{
	return length;
}

float Bus::getWidth()
{
	return width;
}

float Bus::getPosX()
{
	return posX;
}

void Bus::setPosX(float x)
{
	posX = x;
}

float Bus::getPosY()
{
	return posY;
}

void Bus::setPosY(float y)
{
	posY = y;
}

float Bus::getPosZ()
{
	return posZ;
}

void Bus::setPosZ(float z)
{
	posZ = z;
}

void Bus::moveBus()
{
	posX += speed;
}

void Bus::drawBus(void)
{
	glPushMatrix();
	glTranslatef(posX, posY, posZ);
	drawBusBody1();
	drawBusBody2();
	drawBusBody3();
	drawBusBody4();
	drawBusBody5();
	drawBusFrontLeftWheel();
	drawBusFrontRightWheel();
	drawBusRearLeftWheel();
	drawBusRearRightWheel();
	drawBusExhaustPipe();
	glPopMatrix();
}

void Bus::drawBusBody1(void) 
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_White);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_White);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_White);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(1, 1, 1);
	glPushMatrix();	    
	glTranslatef( 0.0, -4, 0);
		glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
			glBindTexture(GL_TEXTURE_2D, back);
				glBegin(GL_QUADS); // outside rectangle
					glTexCoord2d (0, 0);//back
					glVertex3f( -30, 8, -15);//a' 
					glTexCoord2d (1, 0);
					glVertex3f( -30, 8, 15);//a
					glTexCoord2d (1, 1);
					glVertex3f( -30, 28, 15);//d
					glTexCoord2d (0, 1);
					glVertex3f(  -30, 28, -15);//d'
				glEnd();
		glDisable(GL_TEXTURE_2D);		
	glPopMatrix();
}

void Bus::drawBusBody2(void)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_White);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_White);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_White);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(1, 1, 1);
	glPushMatrix();
			glTranslatef( 0.0, -4, 0);
			glBegin(GL_QUADS); 
				glVertex3f( -30, 8, 15);//a//bottom
				glVertex3f( 30, 8, 15);//b
				glVertex3f( 30, 8, -15);//b'
				glVertex3f( -30, 8, -15);//a'

				glVertex3f( -30, 28, 15);//d//top
				glVertex3f( 30, 28, 15);//c
				glVertex3f( 30, 28, -15);//c'
				glVertex3f( -30, 28, -15);//d'
			glEnd();	
	glPopMatrix();
}

void Bus::drawBusBody3(void)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_White);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_White);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_White);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(1, 1, 1);
	glPushMatrix();	     
	glTranslatef( 0.0, -4, 0);
			glEnable(GL_TEXTURE_2D);
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE); 
				glBindTexture(GL_TEXTURE_2D, front);
					glBegin(GL_QUADS); // outside rectangle
						glTexCoord2d (0, 0);//front
						glVertex3f( 30, 8, 15);//b
						glTexCoord2d (1, 0);
						glVertex3f( 30, 8, -15);//b'
						glTexCoord2d (1, 1);
						glVertex3f( 30, 28, -15);//c'
						glTexCoord2d (0, 1);
						glVertex3f( 30, 28, 15);//c
					glEnd();
			glDisable(GL_TEXTURE_2D);		
	glPopMatrix();
	
}

void Bus::drawBusBody4(void)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_White);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_White);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_White);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(1, 1, 1);
	glPushMatrix();
		    glTranslatef( 0.0, -4, 0);
			glEnable(GL_TEXTURE_2D);
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
				glBindTexture(GL_TEXTURE_2D, left);
					glBegin(GL_QUADS); // outside rectangle
						glTexCoord2d (0, 0);//left
						glVertex3f( 30, 8, -15);//b'
						glTexCoord2d (1, 0);
						glVertex3f( -30, 8, -15);//a'
						glTexCoord2d (1, 1);
						glVertex3f( -30, 28, -15);//d'
						glTexCoord2d (0, 1);
						glVertex3f( 30, 28, -15);//c'
					glEnd();
			glDisable(GL_TEXTURE_2D);		
	glPopMatrix();
}

void Bus::drawBusBody5(void)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_White);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_White);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_White);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(1, 1, 1);
	glPushMatrix();
	    glTranslatef( 0.0, -4, 0);
		glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
			glBindTexture(GL_TEXTURE_2D, right);
				glBegin(GL_QUADS); // outside rectangle
					glTexCoord2d (0, 0);//right
					glVertex3f( -30, 8, 15);//a
					glTexCoord2d (1, 0);
					glVertex3f( 30, 8, 15);//b
					glTexCoord2d (1, 1);
					glVertex3f( 30, 28, 15);//c
					glTexCoord2d (0, 1);
					glVertex3f( -30, 28, 15);//d
				glEnd();
		glDisable(GL_TEXTURE_2D);		
	glPopMatrix();
}

void Bus::drawBusFrontLeftWheel(void) 
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.0, 0.0, 0.0);
	
	glPushMatrix();
	   glTranslatef( 16.0, 2.5, -14);
	   if(speed > 0)
	   {
		   rotation_wheel -= getSpeed();
		   glRotatef( rotation_wheel, 0.0, 0.0, 1.0);
		   if(rotation_wheel <= -360)  
			   rotation_wheel += 360;
	   }
		   glutSolidTorus( 2, 2.5, 10, 10);  

		//cylinders in side the wheel
		glPushMatrix();
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-90,0.0,1.0,0.0);
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(45,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0);
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(135,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(225,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(315,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(90,1.0,0.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-90,1.0,0.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
	   glPopMatrix();
	glPopMatrix();
}

void Bus::drawBusFrontRightWheel(void) 
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.0, 0.0, 0.0);

   glPushMatrix();
	   glTranslatef( 16.0, 2.5, 14);
		   glRotatef( rotation_wheel, 0.0, 0.0, 1.0);
		   glutSolidTorus( 2, 2.5, 10, 10);  

		//cylinders in side the wheel
		glPushMatrix();
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-90,0.0,1.0,0.0);
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(45,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0);
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(135,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(225,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(315,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(90,1.0,0.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-90,1.0,0.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
	   glPopMatrix();
	glPopMatrix();
}

void Bus::drawBusRearLeftWheel(void) 
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.0, 0.0, 0.0);

   glPushMatrix();
	   glTranslatef( -14.0, 2.5, -14);
		   glRotatef( rotation_wheel, 0.0, 0.0, 1.0);
		   glutSolidTorus( 2, 2.5, 10, 10);  

		//cylinders in side the wheel
		glPushMatrix();
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-90,0.0,1.0,0.0);
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(45,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0);
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(135,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(225,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(315,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(90,1.0,0.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-90,1.0,0.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
	   glPopMatrix();
	glPopMatrix();
}

void Bus::drawBusRearRightWheel(void) //cube
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.0, 0.0, 0.0);

   glPushMatrix();
	   glTranslatef( -14.0, 2.5, 14);
		   glRotatef( rotation_wheel, 0.0, 0.0, 1.0);
		   glutSolidTorus( 2, 2.5, 10, 10);  

		//cylinders in side the wheel
		glPushMatrix();
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-90,0.0,1.0,0.0);
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(45,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0);
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(135,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(225,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(315,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(90,1.0,0.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-90,1.0,0.0,0.0); 
			gluCylinder( quadratic ,0.1, 0.1, 2.5, 5, 5);
		glPopMatrix();
	glPopMatrix();
}

void Bus::drawBusExhaustPipe()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	 glPushMatrix();
	 	
		glColor3f(0.3, 0.3, 0.3);
		glTranslatef(-31.0, 3.7, 8);
		glRotatef(90, 0.0, 1.0, 0.0);
		gluQuadricDrawStyle(quadratic, GLU_FILL);
		gluCylinder(quadratic,0.7f, 0.7f, 10.0f, 10, 20);

	glPopMatrix();

	glPushMatrix();
	 	
		glColor3f(0.3, 0.3, 0.3);
		glTranslatef(-31.0, 3.7, 6);
		glRotatef(90, 0.0, 1.0, 0.0);
		gluQuadricDrawStyle(quadratic, GLU_FILL);
		gluCylinder(quadratic,0.7f, 0.7f, 10.0f, 10, 20);

	glPopMatrix();
}