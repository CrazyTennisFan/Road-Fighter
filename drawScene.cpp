#include "drawScene.h"
#include <time.h>


DrawScene::DrawScene()
{

}

DrawScene::DrawScene(int adTexture1, int adTexture2, int trackTexture)
	:PI(3.14159265), particleCount(50), adTexture1(adTexture1), adTexture2(adTexture2), trackTexture(trackTexture)
{
	material_Grey[0] = 0.5;
	material_Grey[1] = 0.5;
	material_Grey[2] = 0.5;
	material_Grey[3] = 1.0;

	material_Blue[0] = 0.1;
	material_Blue[1] = 0.1;
	material_Blue[2] = 0.3;
	material_Blue[3] = 1.0;

	materialShininess = 50.0;

	quadratic = gluNewQuadric();

	this->CreateParticles();
}

void DrawScene::setAd(int adTexture1, int adTexture2)
{
	this->adTexture1 = adTexture1;
	this->adTexture2 = adTexture2;
}

void DrawScene::CreateParticles()
{
	for (int i = 1; i < particleCount; ++i)
	{
		Particle[i].Xpos = 3;
		Particle[i].Ypos = 0;
		Particle[i].Zpos = 0;	
		Particle[i].Xoriginpos = 3;
		Particle[i].Yoriginpos = 0;
		Particle[i].Zoriginpos = 0;	

		Particle[i].Ymov = 0.06;
		Particle[i].Zmov = 0.1;
		
		Particle[i].Red = 0.5;
		Particle[i].Green = 0.5;
		Particle[i].Blue = 0.5;
		Particle[i].Scalez = 0.1;
		Particle[i].Direction = 0;
	}
}

void DrawScene::DrawParticles(int carNumber)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.0f);
	glColor3f(0.5, 0.5, 0.5);

	for (int i = 1; i < particleCount; ++i)
	{
		glPushMatrix();		

		if(carNumber == 1)
		{
			glTranslatef(Particle[i].Xpos-5, Particle[i].Ypos-0.5, Particle[i].Zpos+1.5);			
		}
		else if(carNumber == 2)
		{
			glTranslatef(Particle[i].Xpos-2, Particle[i].Ypos-1, Particle[i].Zpos+2);			
		}			
		else if(carNumber == 3)
		{
			glTranslatef(Particle[i].Xpos-5, Particle[i].Ypos, Particle[i].Zpos+1);			
		}
		else
		{
			glTranslatef(Particle[i].Xpos-30, Particle[i].Ypos+3, Particle[i].Zpos+8);
		}

		glScalef (Particle[i].Scalez, Particle[i].Scalez, Particle[i].Scalez);

		glBegin (GL_QUADS);
		glVertex3f (-1, -1, 0);
		glVertex3f (1, -1, 0);
		glVertex3f (1, 1, 0);
		glVertex3f (-1, 1, 0);
		glEnd();
			
		glBegin(GL_QUADS);		
		glVertex3f(-1, -1, 0);		
		glVertex3f (1, -1, 0);		
		glVertex3f (1, 1, 0);		
		glVertex3f (-1, 1, 0);
		glEnd();
        		
		glPopMatrix();
	}
}

void DrawScene::UpdateParticles1(double *distanceArray)
{
	int maxangle = 15;
	int minangle = -15;
	float changeAngle = 6;
	int direction = (maxangle-minangle)/changeAngle + 1;
	int angle = 0;
	int mode = 0;

	for (int i = 0; i < particleCount; ++i)
	{
		glColor3f (Particle[i].Red, Particle[i].Green, Particle[i].Blue);

		double randomDistance = *(distanceArray+i);
		
		if(i%direction==mode)
		{
			Particle[i].Xpos = Particle[i].Xoriginpos - randomDistance * cos((maxangle- changeAngle*mode)* PI/180);
			Particle[i].Ypos = Particle[i].Yoriginpos + randomDistance * sin((maxangle- changeAngle*mode)* PI/180);
			Particle[i].Zpos = Particle[i].Zoriginpos + randomDistance * sin((maxangle- changeAngle*mode)* PI/180);
		}
				
		if(mode==direction)
		{
			mode=0;
		}
		else
		{
			mode++;
		}		
	}
}

void DrawScene::drawTrack()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Blue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Blue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Blue);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.1, 0.1, 0.3); // RichBlue

	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
		glBindTexture (GL_TEXTURE_2D, trackTexture);
		glBegin(GL_QUADS);
			for (int i = 0; i < 1152; i = i + 12)
			{
				for (int j = 0; j < 120; j = j + 12)
				{
					glTexCoord2d (j/12 * 0.1, i/12 * 0.1);				glVertex3f(-756 + i, -3.0, -60 + j);
					glTexCoord2d ((j/12 + 1) * 0.1, i/12 * 0.1);		glVertex3f(-756 + i, -3.0, -60 + j + 12);
					glTexCoord2d ((j/12 + 1) * 0.1, (i/12 + 1) * 0.1);	glVertex3f(-756 + i + 12, -3.0, -60 + j + 12);
					glTexCoord2d (j/12 * 0.1, (i/12 + 1) * 0.1);		glVertex3f(-756 + i + 12, -3.0, -60 + j);
				}
			}
		glEnd();
		glBegin(GL_QUADS);
			glTexCoord2d (0, 0);	glVertex3f(396, -3.0, -60);				
			glTexCoord2d (1, 0);	glVertex3f(396, -3.0, 60);	
			glTexCoord2d (1, 1);	glVertex3f(900, -3.0, 60);
			glTexCoord2d (0, 1);	glVertex3f(900, -3.0, -60);	
		glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	
}
	
GLvoid DrawScene::drawBillboard()
{
	glPushMatrix();
	glTranslatef(80.0, 0.0, -5.0);
	drawBillboardLeftLeg();
	drawBillboardRightLeg();
	drawBillboardFace(adTexture1);
	drawBillboardArm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-100.0, 0.0, -155);
	drawBillboardLeftLeg();
	drawBillboardRightLeg();
	drawBillboardFace(adTexture2);
	drawBillboardArm();
	glPopMatrix();
}

GLvoid DrawScene::drawBillboardLeftLeg()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
		glTranslatef( 100, 0, 70);
		glRotatef(-90, 1.0, 0.0, 0.0);
			gluQuadricDrawStyle(quadratic, GLU_FILL);
			gluCylinder(quadratic, 2, 2,10,20,20);
	glPopMatrix();
}

GLvoid DrawScene::drawBillboardRightLeg()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
		glTranslatef( 100, 0, 90);
		glRotatef(-90, 1.0, 0.0, 0.0);
			gluQuadricDrawStyle(quadratic, GLU_FILL);
			gluCylinder(quadratic, 2, 2,10,20,20); 
	glPopMatrix();
}

GLvoid DrawScene::drawBillboardFace(int adTexture)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.5, 0.5, 0.5);

	glPushMatrix();
		glTranslatef( 100, 21, 80.0);
		glScalef( 0.6, 20, 40);
			glutSolidCube(1);	
	glPopMatrix();  
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
			glBindTexture(GL_TEXTURE_2D, adTexture);
				glBegin(GL_QUADS); // outside rectangle
				glTexCoord2d (1, 0);//right bottom
				glVertex3f( 100 -0.3 -0.01, 11, 100 );
				glTexCoord2d (1, 1);//right top
				glVertex3f( 100 -0.3 -0.01, 31, 100);
				glTexCoord2d (0, 1);//left top
				glVertex3f( 100 -0.3 -0.01, 31, 60 );
				glTexCoord2d (0, 0);//left bottom
				glVertex3f( 100 -0.3 -0.01, 11, 60);
			glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

GLvoid DrawScene::drawBillboardArm()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Grey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Grey);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.5, 0.5, 0.5);

	glPushMatrix();
	glTranslatef( 100, 10.5, 80.0);
	glScalef( 6, 1, 44);
			glutSolidCube(1);	
	glPopMatrix();
}

void DrawScene::drawViewportDivideLine1()
{
	glPushMatrix();
	glColor3f(1, 1, 1); 
	glLineWidth(1.0);
	glBegin(GL_LINES);
		glVertex2f(-15, -50);
		glVertex2f(-15, 8);
	glEnd();
	glPopMatrix();


}

void DrawScene::drawViewportDivideLine2()
{
	glPushMatrix();
	glColor3f(1, 1, 1); 
	glLineWidth(1.0);
	glBegin(GL_LINES);
		glVertex2f(-15, -100);
		glVertex2f(-15, 150);
	glEnd();
	glPopMatrix();

}


void DrawScene::drawStartLine(int difficulty)
{
	if(difficulty==1)
	{
		glPushMatrix();
			glColor3f(1, 1, 1); 
			glBegin(GL_QUADS);					
				glVertex3f(-699+20, 0, -50);					
				glVertex3f(-699+16, 0, -50);
				glVertex3f(-699+16, 0, +50);										
				glVertex3f(-699+20, 0, +50);					
			glEnd();			
		glPopMatrix();
	}
	else if(difficulty==2)
	{
		glPushMatrix();
			glColor3f(1, 1, 1); 
			glBegin(GL_QUADS);					
				glVertex3f(-699+17, 0, -50);					
				glVertex3f(-699+13, 0, -50);
				glVertex3f(-699+13, 0, +50);										
				glVertex3f(-699+17, 0, +50);					
			glEnd();			
		glPopMatrix();
	}
	else if(difficulty==0)
	{
		glPushMatrix();
			glColor3f(1, 1, 1); 
			glBegin(GL_QUADS);					
				glVertex3f(-699+8, 0, -50);					
				glVertex3f(-699+4, 0, -50);
				glVertex3f(-699+4, 0, +50);										
				glVertex3f(-699+8, 0, +50);					
			glEnd();			
		glPopMatrix();
	}
}

void DrawScene::drawFinalLine(int difficulty)
{
	if(difficulty==1)
	{
		glPushMatrix();
			glColor3f(1, 1, 1); 
			glBegin(GL_QUADS);					
				glVertex3f(300-20, 0, -50);					
				glVertex3f(300-16, 0, -50);
				glVertex3f(300-16, 0, +50);										
				glVertex3f(300-20, 0, +50);					
			glEnd();			
		glPopMatrix();
	}
	else if(difficulty==2)
	{
		glPushMatrix();
			glColor3f(1, 1, 1); 
			glBegin(GL_QUADS);					
				glVertex3f(300-20, 0, -50);					
				glVertex3f(300-16, 0, -50);
				glVertex3f(300-16, 0, +50);										
				glVertex3f(300-20, 0, +50);						
			glEnd();			
		glPopMatrix();
	}
	else if(difficulty==0)
	{
		glPushMatrix();
			glColor3f(1, 1, 1); 
			glBegin(GL_QUADS);					
				glVertex3f(300-20, 0, -50);					
				glVertex3f(300-16, 0, -50);
				glVertex3f(300-16, 0, +50);										
				glVertex3f(300-20, 0, +50);					
			glEnd();			
		glPopMatrix();
	}
}