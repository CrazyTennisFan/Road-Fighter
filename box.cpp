#include "box.h"


Box::Box(int length, int function, float speed, float x, float y, float z, int texture)
	:length(length), function(function), speed(speed), posX(x), posY(y), posZ(z), texture(texture)
{
	
	material_Green[0] = 0.0;
	material_Green[1] = 1.0;
	material_Green[2] = 0.0;
	material_Green[3] = 1.0;

	material_Red[0] = 1.0;
	material_Red[1] = 0.0;
	material_Red[2] = 0.0;
	material_Red[3] = 1.0;

	material_Yellow[0] = 1.0;
	material_Yellow[1] = 1.0;
	material_Yellow[2] = 0.0;
	material_Yellow[3] = 1.0;

	materialShininess = 50.0;
}

Box::~Box(void)
{}

int Box::getLength()
{
	return length;
}

int Box::getFunction()
{
	return function;
}

float Box::getSpeed()
{
	return speed;
}

float Box::getPosX()
{
	return posX;
}

float Box::getPosY()
{
	return posY;
}

float Box::getPosZ()
{
	return posZ;
}

void Box::drawBox()
{
	if (function == 1) // green, accelerate
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Green);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Green);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Green);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

		glColor3f(0, 1, 0);
		
		glPushMatrix();
			glEnable(GL_TEXTURE_2D);
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 
				glBindTexture(GL_TEXTURE_2D, texture);
					glBegin(GL_QUADS); // outside rectangle

						glTexCoord2d (0, 0);//front
						glVertex3f( -4, 0, -4);//a 
						glTexCoord2d (1, 0);
						glVertex3f( -4, 0, 4);//b
						glTexCoord2d (1, 1);
						glVertex3f( -4, 8, 4);//c
						glTexCoord2d (0, 1);
						glVertex3f( -4, 8, -4);//d

						glVertex3f( -4, 0, -4);//a//bottom
						glVertex3f( -4, 0, 4);//b
						glVertex3f( 4, 0, 4);//b'
						glVertex3f( 4, 0, -4);//a'

						glVertex3f( 4, 0, -4);//a'//rear
						glVertex3f( 4, 0, 4);//b'
						glVertex3f( 4, 8, 4);//c'
						glVertex3f( 4, 8, -4);//d'

						glTexCoord2d (0, 0);//top
						glVertex3f( -4, 8, -4);//d
						glTexCoord2d (1, 0);
						glVertex3f( -4, 8, 4);//c
						glTexCoord2d (1, 1);
						glVertex3f( 4, 8, 4);//c'
						glTexCoord2d (0, 1);
						glVertex3f( 4, 8, -4);//d'

						glTexCoord2d (0, 0);//right
						glVertex3f( -4, 0, 4);//b
						glTexCoord2d (1, 0);
						glVertex3f( 4, 0, 4);//b'
						glTexCoord2d (1, 1);
						glVertex3f( 4, 8, 4);//c'
						glTexCoord2d (0, 1);
						glVertex3f( -4, 8, 4);//c
						
						glTexCoord2d (0, 0);//left
						glVertex3f( 4, 0, -4);//a'
						glTexCoord2d (1, 0);
						glVertex3f( -4, 0, -4);//a
						glTexCoord2d (1, 1);
						glVertex3f( -4, 8, -4);//d
						glTexCoord2d (0, 1);
						glVertex3f( 4, 8, -4);//d'
					glEnd();
			glDisable(GL_TEXTURE_2D);		
		glPopMatrix();
	}
	else if (function == 0) // red, decelerate
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Red);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Red);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Red);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

		glColor3f(1, 0, 0);
		glPushMatrix();
			glEnable(GL_TEXTURE_2D);
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 
				glBindTexture(GL_TEXTURE_2D, texture);
					glBegin(GL_QUADS); // outside rectangle

						glTexCoord2d (0, 0);//front
						glVertex3f( -4, 0, -4);//a 
						glTexCoord2d (1, 0);
						glVertex3f( -4, 0, 4);//b
						glTexCoord2d (1, 1);
						glVertex3f( -4, 8, 4);//c
						glTexCoord2d (0, 1);
						glVertex3f( -4, 8, -4);//d

						glVertex3f( -4, 0, -4);//a//bottom
						glVertex3f( -4, 0, 4);//b
						glVertex3f( 4, 0, 4);//b'
						glVertex3f( 4, 0, -4);//a'

						glVertex3f( 4, 0, -4);//a'//rear
						glVertex3f( 4, 0, 4);//b'
						glVertex3f( 4, 8, 4);//c'
						glVertex3f( 4, 8, -4);//d'

						glTexCoord2d (0, 0);//top
						glVertex3f( -4, 8, -4);//d
						glTexCoord2d (1, 0);
						glVertex3f( -4, 8, 4);//c
						glTexCoord2d (1, 1);
						glVertex3f( 4, 8, 4);//c'
						glTexCoord2d (0, 1);
						glVertex3f( 4, 8, -4);//d'

						glTexCoord2d (0, 0);//right
						glVertex3f( -4, 0, 4);//b
						glTexCoord2d (1, 0);
						glVertex3f( 4, 0, 4);//b'
						glTexCoord2d (1, 1);
						glVertex3f( 4, 8, 4);//c'
						glTexCoord2d (0, 1);
						glVertex3f( -4, 8, 4);//c
						
						glTexCoord2d (0, 0);//left
						glVertex3f( 4, 0, -4);//a'
						glTexCoord2d (1, 0);
						glVertex3f( -4, 0, -4);//a
						glTexCoord2d (1, 1);
						glVertex3f( -4, 8, -4);//d
						glTexCoord2d (0, 1);
						glVertex3f( 4, 8, -4);//d'
					glEnd();
			glDisable(GL_TEXTURE_2D);		
		glPopMatrix();
	}
	else // yellow, special
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Yellow);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Yellow);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Yellow);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

		glColor3f(1, 1, 0);

		glPushMatrix();
			glEnable(GL_TEXTURE_2D);
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 
				glBindTexture(GL_TEXTURE_2D, texture);
					glBegin(GL_QUADS); // outside rectangle

						glTexCoord2d (0, 0);//front
						glVertex3f( -4, 0, -4);//a 
						glTexCoord2d (1, 0);
						glVertex3f( -4, 0, 4);//b
						glTexCoord2d (1, 1);
						glVertex3f( -4, 8, 4);//c
						glTexCoord2d (0, 1);
						glVertex3f( -4, 8, -4);//d

						glVertex3f( -4, 0, -4);//a//bottom
						glVertex3f( -4, 0, 4);//b
						glVertex3f( 4, 0, 4);//b'
						glVertex3f( 4, 0, -4);//a'

						glVertex3f( 4, 0, -4);//a'//rear
						glVertex3f( 4, 0, 4);//b'
						glVertex3f( 4, 8, 4);//c'
						glVertex3f( 4, 8, -4);//d'

						glTexCoord2d (0, 0);//top
						glVertex3f( -4, 8, -4);//d
						glTexCoord2d (1, 0);
						glVertex3f( -4, 8, 4);//c
						glTexCoord2d (1, 1);
						glVertex3f( 4, 8, 4);//c'
						glTexCoord2d (0, 1);
						glVertex3f( 4, 8, -4);//d'

						glTexCoord2d (0, 0);//right
						glVertex3f( -4, 0, 4);//b
						glTexCoord2d (1, 0);
						glVertex3f( 4, 0, 4);//b'
						glTexCoord2d (1, 1);
						glVertex3f( 4, 8, 4);//c'
						glTexCoord2d (0, 1);
						glVertex3f( -4, 8, 4);//c
						
						glTexCoord2d (0, 0);//left
						glVertex3f( 4, 0, -4);//a'
						glTexCoord2d (1, 0);
						glVertex3f( -4, 0, -4);//a
						glTexCoord2d (1, 1);
						glVertex3f( -4, 8, -4);//d
						glTexCoord2d (0, 1);
						glVertex3f( 4, 8, -4);//d'
					glEnd();
			glDisable(GL_TEXTURE_2D);		
		glPopMatrix();
	}
}