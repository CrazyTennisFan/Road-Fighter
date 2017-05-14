#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <list>

#include "Car.h"
#include "Car1.h"
#include "Car2.h"
#include "Car3.h"
#include "box.h"
#include "Bus.h"
#include "drawScene.h"

using namespace std;

void resize(int w, int h);
GLvoid driveMoto(Car* car);
Bus* bus1;
Bus* bus2;
Car* car1;
Car* car2;
Car* car3;
Car* car;
DrawScene *scene;

const float PI = 3.14159265;

static unsigned int texture[23]; // Array of texture indices.

// Struct of bitmap file.
struct BitMapFile
{
   int sizeX;
   int sizeY;
   unsigned char *data;
};
void loadExternalTextures();


float light1Position[] = {1.0, 1.0, 1.0, 0.0}; 
float light1Ambient[] = {1.0, 1.0, 1.0, 1.0};
float light1Diffuse[] = {1.0, 1.0, 1.0, 1.0};
float light1Specular[] = {1.0, 1.0, 1.0, 1.0};

float light2Ambient[] = {1.0, 1.0, 1.0, 1.0};
float light2Diffuse[] = {1.0, 1.0, 1.0, 1.0};
float light2Specular[] = {1.0, 1.0, 1.0, 1.0};
float light2SpotAngle = 45.0f;

GLfloat light3Ambient[] = {1.0, 1.0, 1.0f, 1.0};
GLfloat light3Diffuse[] = {1.0, 1.0, 1.0f, 1.0};
GLfloat light3Specular[] = {1.0, 1.0, 1.0f, 1.0};

float light3SpotAngle = 40.0f;
int windowX;
int windowY;

bool isLight1on = false;
bool isLight2on = true;

list<Box*> boxList;

//////////////////////////////////////////////////////Need to reset///////////////////////////////////
//////////////////////////////////////////////////////Need to reset when every level begins or restart game///////////////////////////////////
float cameraX;     //default value
float cameraY;     //default value
float cameraZ;	 //default value
float lookatX;
float lookatY;
float lookatZ; 

bool isMotoStart;
bool toSpeedUp;
bool toSlowDown;
bool moveLeft;
bool moveRight;
bool firstPressUP;
bool firstPressDOWN;
bool isUPpressed;
bool isWin;
bool isFail;

float UPstart;
float UPcurrent;
float UPinterval;
int boxChoice[2];
float boxSpeedChoice;
int boxPosChoice;
int busPosXChoice[2];
int busPosZChoice[2];
bool isGenerateBus;
bool isGenerateBox;
bool isGenerateAD;
bool isAnimate;
bool thirdPersonCarema;


float timeInterval;
float motoStartTime;
float motoCurrentTime;
float motoTimeInterval;

bool isRotate;
float motoRotateAngle; // moto rotate when collision

int currentTime;
int previousTime;
int trackCounter;
float distanceRun;




//////////////////////////////////////////////////////Need to reset when every level begins or restart game///////////////////////////////////


//////////////////////////////////////////////////////Need to reset Only when game start///////////////////////////////////
int currentSelect;
int difficulty;
float miniRotateAngle;
int gameState;    
int computerPerformanceTimerInterval;
int computerPerformanceCurrentTime = 0;
int computerPerformancePreviousTime = 0;
int level;
int frameNumber;
float frameCount;
float standardFrameCount = 180;

float easyIndividualLastLevelScore;
float normalIndividualLastLevelScore;
float hardIndividualLastLevelScore;

float individualHighScore;

float logoRotateAngle;

//////////////////////////////////////////////////////Need to reset Only when game start///////////////////////////////////

float highScore = 0;
float easyAllPeopleHistoryScore = 0;
float normalAllPeopleHistoryScore = 0;
float hardAllPeopleHistoryScore = 0;


int standardEasyDistance = 11000;
int standardNormalDistance = 13000;
int standardHardDistance = 15000;
int currentLevelAndDifficultyDistance = 13000;

float changeLaneStartTime = 0;
float changeLaneCurrentTime = 0;
float changeLaneTimeInterval = 0;


void initParameterGameStart()
{
	currentSelect = 1;
	difficulty = 1;
	miniRotateAngle = 0;
	gameState = 0;    //0: select car state   1: run  

	computerPerformanceCurrentTime = 0;
	computerPerformancePreviousTime = 0;

	level = 1;

	frameNumber = 0;
	frameCount = 60;

	thirdPersonCarema = true;

    easyIndividualLastLevelScore = 0;
	normalIndividualLastLevelScore = 0;
	hardIndividualLastLevelScore = 0;

	individualHighScore = 0;

	logoRotateAngle = 0;
}


void initParameterAnyTime()
{
	cameraX = -550.0;     //default value
	cameraY = 30.0;     //default value
	cameraZ = 15.0;	 //default value
	lookatX = 0.0;
	lookatY = 0.0;
	lookatZ = 0.0; 

	isMotoStart = false;
	toSpeedUp = false;
	toSlowDown = false;
	moveLeft = false;
	moveRight = false;
	firstPressUP = false;
	firstPressDOWN = false;
	isUPpressed = false;
	isWin = false;
	isFail = false;

	UPstart = 0;
	UPcurrent = 0;
	UPinterval = 0;
	//boxChoice = 0;
	boxSpeedChoice = 0;
	boxPosChoice = 0;
	isGenerateBox = true;
	isGenerateAD = false;
	isGenerateBus = false;
	isAnimate = false;
	

	timeInterval = 0;
    motoStartTime = 0;
    motoCurrentTime = 0;
    motoTimeInterval = 0;

	isRotate = false;
	motoRotateAngle = 0.0;

	currentTime = 0;
	previousTime = 0;
	trackCounter = 0;

	distanceRun = 0;

}

///////////////////Startup screen select car end

bool isCollisionWithBox(Car* car, Box* box)
{
	if (car->getPosZ() < box->getPosZ()) // car at left hit box at right
	{
		if ( ((car->getPosZ() + car->getWidth()) >= (box->getPosZ() - box->getLength()/2)) 
			&& ((car->getPosX() + car->getLength()) >= (box->getPosX() - box->getLength()/2))
			&& ((car->getPosX() - car->getLength()) <= (box->getPosX() + box->getLength()/2)) )
			return true;
	}
	else if (car->getPosZ() > box->getPosZ()) // car at right hit box at left 
	{
		if ( ((car->getPosZ() - car->getWidth()) <= (box->getPosZ() + box->getLength()/2)) 
			&& ((car->getPosX() + car->getLength()) >= (box->getPosX() - box->getLength()/2))
			&& ((car->getPosX() - car->getLength()) <= (box->getPosX() + box->getLength()/2)) )
			return true;
	}
	else // same z position
	{
		if ( ((car->getPosX() + car->getLength()) >= (box->getPosX() - box->getLength()/2))
			&& ((car->getPosX() - car->getLength()) <= (box->getPosX() + box->getLength()/2)) )
			return true;
	}
	return false;
}

bool isCollisionWithBus(Car* car, Bus* bus)
{
	if (car->getPosZ() < bus->getPosZ()) // car at left hit bus at right
	{
		if ( ((car->getPosZ() + car->getWidth()) >= (bus->getPosZ() - bus->getWidth())) 
			&& ((car->getPosX() + car->getLength()) >= (bus->getPosX() - bus->getLength())) 
			&& ((car->getPosX() - car->getLength()) <= (bus->getPosX() + bus->getLength())) )
			return true;
	}
	else if (car->getPosZ() > bus->getPosZ()) // car at right hit bus at left
	{
		if ( ((car->getPosZ() - car->getWidth()) <= (bus->getPosZ() + bus->getWidth())) 
			&& ((car->getPosX() + car->getLength()) >= (bus->getPosX() - bus->getLength())) 
			&& ((car->getPosX() - car->getLength()) <= (bus->getPosX() + bus->getLength())) )
			return true;
	}
	else // same z position
	{
		if ( ((car->getPosX() + car->getLength()) >= (bus->getPosX() - bus->getLength())) 
			&& ((car->getPosX() - car->getLength()) <= (bus->getPosX() + bus->getLength())) )
			return true;
	}
	return false;
}

bool isBoxCollisionWithBus(Bus* bus, Box* box)
{
	if (bus->getPosZ() < box->getPosZ()) // car at left hit box at right
	{
		if ( ((bus->getPosZ() + bus->getWidth()) >= (box->getPosZ() - box->getLength()/2)) 
			&& ((bus->getPosX() + bus->getLength()) >= (box->getPosX() - box->getLength()/2))
			&& ((bus->getPosX() - bus->getLength()) <= (box->getPosX() + box->getLength()/2)) )
			return true;
	}
	else if (car->getPosZ() > box->getPosZ()) // car at right hit box at left 
	{
		if ( ((bus->getPosZ() - bus->getWidth()) <= (box->getPosZ() + box->getLength()/2)) 
			&& ((bus->getPosX() + bus->getLength()) >= (box->getPosX() - box->getLength()/2))
			&& ((bus->getPosX() - bus->getLength()) <= (box->getPosX() + box->getLength()/2)) )
			return true;
	}
	else // same z position
	{
		if ( ((bus->getPosX() + bus->getLength()) >= (box->getPosX() - box->getLength()/2))
			&& ((bus->getPosX() - bus->getLength()) <= (box->getPosX() + box->getLength()/2)) )
			return true;
	}
	return false;
}

void light()
{
	if ((isLight1on) || (isLight2on))
	{
		glEnable(GL_LIGHTING);
	}
	else glDisable(GL_LIGHTING);

	if (isLight1on)
	{
		glEnable(GL_NORMALIZE);
		glEnable(GL_LIGHT1);
		glLightfv(GL_LIGHT1, GL_POSITION, light1Position);
		glLightfv(GL_LIGHT1, GL_AMBIENT, light1Ambient);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light1Diffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light1Specular);

	}
	else
	{
		glDisable(GL_LIGHT1);
	}
	
	if (isLight2on)
	{
		

		if((difficulty==0) || (difficulty==2))
		{
			GLfloat light2Position[] = {car->getPosX() + 11.5, 6.0 * cos(30 * PI/180)+0.2, car->getPosZ(),1}; 
			GLfloat light2Direction[] = {1,0,0};
			glLightfv(GL_LIGHT2, GL_POSITION, light2Position);
			glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light2Direction);
		}else
		{
			GLfloat light2Position[] = {car->getPosX() + 16.5, car->getPosY()+6.925, car->getPosZ(),1}; 
			GLfloat light2Direction[] = {1,0,0};
			glLightfv(GL_LIGHT2, GL_POSITION, light2Position);
			glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light2Direction);
		}
	
		glLightfv(GL_LIGHT2, GL_AMBIENT, light2Ambient);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, light2Diffuse);
		glLightfv(GL_LIGHT2, GL_SPECULAR, light2Specular);
		glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, light2SpotAngle);
		glEnable(GL_LIGHT2);
	}else
	{
		glDisable(GL_LIGHT2);
	}
	
}

void floatToString(char * destStr, int precision, int level, int difficulty, 
	float highScore, float currentScore, float valTimer, int percentage, int counter) 
{
	switch(counter)
	{
		case 0:
			glColor3f(1, 1, 1); 
			sprintf(destStr,"Level: %d", level);
			break;
		case 1:
			sprintf(destStr,"");
			break;
		case 2:
			glColor3f(1, 1, 1); 
			sprintf(destStr,"Difficulty:");
			break;
		case 3:
			glColor3f(0, 1, 1); 
			if (difficulty == 0)
				sprintf(destStr,"Easy");
			else if (difficulty == 1)
				sprintf(destStr,"Normal");
			else 
				sprintf(destStr,"Hard");
			break;
		case 4:
			glColor3f(1, 1, 1); 
			sprintf(destStr,"HighScore:");
			break;
		case 5:
			glColor3f(1, 0, 0); 
			sprintf(destStr,"%d", (int)highScore);
			break;
		case 6:	
			glColor3f(1, 1, 1); 
			sprintf(destStr,"Current Score:");
			break;
		case 7:	
			glColor3f(1, 1, 0); 
			sprintf(destStr,"%d", (int)currentScore);
			break;
		case 8:
			glColor3f(1, 1, 1); 
			sprintf(destStr,"Time Passed:");
			break;
		case 9:
			glColor3f(1, 0, 1);
			if(valTimer >= 60)
			{
				valTimer = 60;
			}
			sprintf(destStr,"%4.3f s", valTimer);
			break;
		case 10:
			glColor3f(1, 1, 1); 
			sprintf(destStr,"Complete:");
			break;
		case 11:
			glColor3f(0, 1, 0);
			sprintf(destStr,"%d %%", percentage);
			break;
	}
	destStr[precision] = '\0';
}

void printToScreen(char* string)
{
    char* p;
	 for (p = string; *p; p++)
	{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p);
	}
}

void displayFunction()
{
	float time;
    //  Calculate time passed
	if( ! isAnimate)
	{
		time = 0;
	}
	else
		time = timeInterval;

	distanceRun = car->getPosX() + 700 + trackCounter * 1000 -1;
	int percentage = (distanceRun * 100) / currentLevelAndDifficultyDistance;
	
	char buffer [200];

	if((difficulty==0) && ((easyIndividualLastLevelScore + distanceRun) > easyAllPeopleHistoryScore))
	{
		easyAllPeopleHistoryScore = easyIndividualLastLevelScore + distanceRun;
		
	}else if((difficulty==1) && ((normalIndividualLastLevelScore + distanceRun) > normalAllPeopleHistoryScore))
	{
		normalAllPeopleHistoryScore = normalIndividualLastLevelScore + distanceRun;
		

	}else if((difficulty==2) && ((hardIndividualLastLevelScore + distanceRun) > hardAllPeopleHistoryScore))
	{
		hardAllPeopleHistoryScore = hardIndividualLastLevelScore + distanceRun;
		
	}

	if(difficulty==0)
	{
		highScore = easyAllPeopleHistoryScore * standardFrameCount / frameCount;
		individualHighScore = (easyIndividualLastLevelScore + distanceRun) * standardFrameCount / frameCount;
		
	}else if(difficulty==1)
	{
		highScore = normalAllPeopleHistoryScore * standardFrameCount / frameCount;
		individualHighScore = (normalIndividualLastLevelScore + distanceRun)* standardFrameCount / frameCount;

	}else if(difficulty==2)
	{
		highScore = hardAllPeopleHistoryScore * standardFrameCount / frameCount;
		individualHighScore = (hardIndividualLastLevelScore + distanceRun)* standardFrameCount / frameCount;
		
	}
		
	for (int i = 0; i < 12; ++i)
	{
		floatToString(buffer, 100, level, difficulty, highScore, individualHighScore, time, percentage, i);	
		glRasterPos2i(-5.0, 7.0 - i * 1.0);
		printToScreen(buffer);
	}
}

void displayInfoFunction()
{
	//int time;
   
	char buffer [300];
	
	int percentage = (distanceRun * 100) / currentLevelAndDifficultyDistance;
	
	switch(currentSelect)
	{
		case 0:
			sprintf(buffer,"Difficulty Level : Easy");	
			break;

		case 1:
			sprintf(buffer,"Difficulty Level : Normal");	
			break;

		case 2:
			sprintf(buffer,"Difficulty Level : Hard");	
			break;
	}
		
	buffer[50] = '\0';	
	glRasterPos3f(-50.0, 50.0, 0.0);			
	printToScreen(buffer);


	sprintf(buffer,"  Press Enter key to start game");
	buffer[50] = '\0';	
	glRasterPos3f(-60.0, -10.0, 0.0);	
	printToScreen(buffer);

	glColor3f(0.0, 1.0, 0.0);
	
	sprintf(buffer,"Left and Right key: Change Difficulty");
	buffer[50] = '\0';	
	glRasterPos3f(-65.0, -70.0, 0.0);	
	printToScreen(buffer);	

}


void displayGameStatus()
{
	//int time;
   
	char buffer [300];
	
	
	if(isFail == true)
	{
		glColor3f(1.0, 0.0, 0.0);
	
		sprintf(buffer,"Game Over");
		buffer[50] = '\0';	
		glRasterPos3f(-10.0, 110.0, 0.0);	
		printToScreen(buffer);

		sprintf(buffer,"Esc: Exit Game");
		buffer[50] = '\0';	
		glRasterPos3f(-130.0, 50.0, 0.0);	
		printToScreen(buffer);

		sprintf(buffer,"Enter: Restart Game");
		buffer[50] = '\0';	
		glRasterPos3f(70.0, 50.0, 0.0);	
		printToScreen(buffer);
	}else if(isWin == true)
	{
		glColor3f(1.0, 0.0, 0.0);
	
		sprintf(buffer,"Congradulations!!");
		buffer[50] = '\0';	
		glRasterPos3f(-10.0, 110.0, 0.0);	
		printToScreen(buffer);

		glColor3f(0.0, 1.0, 0.0);

		sprintf(buffer,"Esc: Exit Game");
		buffer[50] = '\0';	
		glRasterPos3f(-130.0, 50.0, 0.0);	
		printToScreen(buffer);

		sprintf(buffer,"Enter: Next Level");
		buffer[50] = '\0';	
		glRasterPos3f(70.0, 50.0, 0.0);	
		printToScreen(buffer);
	}


	glColor3f(1.0, 1.0, 0.0);
	
	sprintf(buffer,"Up key: Increase speed");
	buffer[50] = '\0';	
	glRasterPos3f(-150.0, -10.0, 0.0);	
	printToScreen(buffer);

	sprintf(buffer,"Down key: Decrease speed     ");
	buffer[50] = '\0';	
	glRasterPos3f(50.0, -10.0, 0.0);	
	printToScreen(buffer);


	sprintf(buffer,"Left key: Move left");
	buffer[50] = '\0';	
	glRasterPos3f(-150.0, -70.0, 0.0);	
	printToScreen(buffer);

	sprintf(buffer,"Right key: Move right ");
	buffer[50] = '\0';	
	glRasterPos3f(50.0, -70.0, 0.0);	
	printToScreen(buffer);

	sprintf(buffer,"Press Key 1:  First person camera     ");
	buffer[50] = '\0';	
	glRasterPos3f(-150.0, -130.0, 0.0);	
	printToScreen(buffer);

	sprintf(buffer,"Press Key 3:  Third person camera ");
	buffer[50] = '\0';	
	glRasterPos3f(50.0, -130.0, 0.0);	
	printToScreen(buffer);

	

}



void computeFrameFunction()
{
	frameNumber++;
	computerPerformanceCurrentTime = glutGet(GLUT_ELAPSED_TIME);

    //  Calculate time passed
    int computerPerformanceTimerInterval = computerPerformanceCurrentTime - computerPerformancePreviousTime;

    if(computerPerformanceTimerInterval > 1000)
    {
        //  calculate the number of frames per second		
        frameCount = frameNumber / (computerPerformanceTimerInterval / 1000.0f);

        //  Set time
        computerPerformancePreviousTime = computerPerformanceCurrentTime;

        //  Reset frame count
        frameNumber = 0;
    }

	printf("\n frameCount = %f", frameCount);
}


void displaySelectCarScreen()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1, 0, 0);
	miniRotateAngle = miniRotateAngle + 0.005;

	computeFrameFunction();
	
	GLfloat light3Position[] = {0, 25, -45,1}; 								
	GLfloat light3Direction[] = {0,-1,0};
	glLightfv(GL_LIGHT3, GL_POSITION, light3Position);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light3Direction);
	glLightfv(GL_LIGHT3, GL_AMBIENT, light3Ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, light3Diffuse);
	glLightfv(GL_LIGHT3, GL_SPECULAR, light3Specular);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, light3SpotAngle);
	glEnable(GL_LIGHT3);
	
	GLfloat mat0_ambient[ ] = {0.2, 0.2, 1.0, 1.0};
	GLfloat mat0_diffuse[ ] = {0.2, 0.2, 1.0, 1.0};
	GLfloat mat0_specular[ ] = {0.2, 0.2, 1.0, 1.0};
	GLfloat mat0_shininess[ ] = {5.0};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0_shininess);

	glPushMatrix();
		glViewport(0, 0, windowX , windowY *1/5);			
		gluLookAt(0, 0, 153, 0, 0, 0, 0.0, 1.0, 0.0); 
		glDisable(GL_LIGHTING);
		displayInfoFunction(); 
	glPopMatrix();
	
	glPushMatrix();
		glViewport(0, windowY *1/5 + 1 , windowX , windowY *4/5);		
		gluLookAt(0, 10, 53, 0, 0, 0, 0.0, 1.0, 0.0); 
		
		glEnable(GL_LIGHTING);
		glPushMatrix();                    //Draw selection area
			glBegin(GL_QUAD_STRIP);
			for (int i = 0; i < 100; ++i)
			{
				for (int j = 0; j < 100; ++j)
				{
					glVertex3f(-50 + i, -3.0, -50 + j);
					glVertex3f(-50 + i, -3.0, -50 + j+1);
					glVertex3f(-50 + i+1, -3.0, -50 + j);
					glVertex3f(-50 + i+1, -3.0, -50 + j+1);
				}
			}
			glEnd();
		glPopMatrix();

		glPushMatrix();                    //Draw Game Logo

			glTranslatef(0.0, 34.0, 13.0);			
			if(logoRotateAngle<=75)
			{
				glRotatef(-logoRotateAngle, 1.0, 0.0, 0.0);
				logoRotateAngle = logoRotateAngle+0.8;
			}else
			{
				glRotatef(-75, 1.0, 0.0, 0.0);
			}

			glTranslatef(0.0, 00.0, -13.0);
			glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
			glBindTexture(GL_TEXTURE_2D, texture[22]);
			glBegin(GL_QUADS);
					glTexCoord2d (0, 0);
					glVertex3f(-40, -0, -11);

					glTexCoord2d (1, 0);
					glVertex3f(40, -0, -11);

					glTexCoord2d (1, 1);
					glVertex3f(45, 0, 13);

					glTexCoord2d (0, 1);
					glVertex3f(-45, 0, 13);  				
			glEnd();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		
		double randomDistance1[50];
		for (int i = 0; i < 50; ++i)
		{
			randomDistance1[i] = rand()%700/100.0;
		}
		
		switch(currentSelect)
		{
			case 0:
				glPushMatrix();                       //Left back  car 
					glTranslatef(-25, 0, -25);										
					car1->drawCar();
					car1->drawTrailer();
					scene->UpdateParticles1(randomDistance1);
					scene->DrawParticles(1);
				glPopMatrix();

				glPushMatrix();                       //Right back  car			
					glTranslatef(25, 0, -25);						
					car2->drawCar();
					car2->drawTrailer();	
					scene->UpdateParticles1(randomDistance1);
					scene->DrawParticles(2);
				glPopMatrix();

				glPushMatrix();                   //Front car, current selected car
					glTranslatef(0, 0, 15);		
					glRotatef(miniRotateAngle * 180 / PI, 0.0, 1.0, 0.0);										
					car3->drawCar();
					car3->drawTrailer();
					scene->UpdateParticles1(randomDistance1);
					scene->DrawParticles(3);
				glPopMatrix();
				break;

			case 1:
				glPushMatrix();                       //Left back  car 
					glTranslatef(-25, 0, -25);						
					car3->drawCar();
					car3->drawTrailer();	
					scene->UpdateParticles1(randomDistance1);
					scene->DrawParticles(3);
				glPopMatrix();

				glPushMatrix();                       //Right back  car			
					glTranslatef(25, 0, -25);						
					car1->drawCar();
					car1->drawTrailer();	
					scene->UpdateParticles1(randomDistance1);
					scene->DrawParticles(1);
				glPopMatrix();

				glPushMatrix();                   //Front car, current selected car
					glTranslatef(0, 0, 15);		
					glRotatef(miniRotateAngle * 180 / PI, 0.0, 1.0, 0.0);
					car2->drawCar();
					car2->drawTrailer();	
					scene->UpdateParticles1(randomDistance1);
					scene->DrawParticles(2);
				glPopMatrix();
				break;

			case 2:
				glPushMatrix();                       //Left back  car 
					glTranslatef(-25, 0, -25);						
					car2->drawCar();
					car2->drawTrailer();
					scene->UpdateParticles1(randomDistance1);
					scene->DrawParticles(2);
				glPopMatrix();

				glPushMatrix();                       //Right back  car			
					glTranslatef(25, 0, -25);						
					car3->drawCar();
					car3->drawTrailer();
					scene->UpdateParticles1(randomDistance1);
					scene->DrawParticles(3);
				glPopMatrix();

				glPushMatrix();                   //Front car, current selected car is hard car
					glTranslatef(0, 0, 15);		
					glRotatef(miniRotateAngle * 180 / PI, 0.0, 1.0, 0.0);					
					car1->drawCar();
					car1->drawTrailer();
					scene->UpdateParticles1(randomDistance1);
					scene->DrawParticles(1);
				glPopMatrix();
				break;
		}
	glPopMatrix();
}



void displayRunScreen()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//////////////////////////////////////////////// lower viewport start
	glPushMatrix();								
	glViewport(0, 0, windowX * 3/4, windowY * 1/5);
	gluLookAt(0, 0, 153, 0, 0, 0, 0.0, 1.0, 0.0); 
	glDisable(GL_LIGHTING);
	displayGameStatus(); 

	glPopMatrix();							
	/////////////////////////////////////////////// lower viewport end

	/////////////////////////////////////////////// right upper viewport start
	glPushMatrix();								
	glViewport(windowX * 3/4, windowX * 1/8, windowX * 1/4, windowY - windowX * 1/4 + windowX * 1/8);
	glDisable(GL_LIGHTING);
	gluLookAt(0.0, 0.0, 10, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); 
	
	displayFunction(); //to display time and distance
	
	// viewport divide line
	scene->drawViewportDivideLine1();
	
	glPopMatrix();							
	////////////////////////////////////////////// right upper viewport end

	////////////////////////////////////////////// right lower viewport start
	glPushMatrix();								
	glViewport(windowX * 3/4, 100, windowX * 1/4, windowX * 1/8);
	glDisable(GL_LIGHTING);
	gluLookAt(0.0, 0.0, 10, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	// viewport divide line
	scene->drawViewportDivideLine2();

	// meter
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 
	glBindTexture (GL_TEXTURE_2D, texture[14]);	
	glBegin(GL_QUADS);
		glTexCoord2d (0, 0); glVertex2f(-10.1, -10);
		glTexCoord2d (1, 0); glVertex2f(9.5, -10);
		glTexCoord2d (1, 1); glVertex2f(9.5, 10);
		glTexCoord2d (0, 1); glVertex2f(-10.1, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	// pointer of meter
	glPushMatrix();
	glColor3f(1, 0, 0); 
	glLineWidth(3.0);
	glBegin(GL_LINES);
		float sp = car->getSpeed();
		float angle = sp * 223 / 3;
		glVertex3f(0.0, -1.5, 1.0);
		glVertex3f(7*cos( (215-angle) * PI/180), 7*sin((215-angle) * PI/180)-1.5, 1.0);
	glEnd();
	glPopMatrix();

	glPopMatrix();							
	//////////////////////////////////////////// right lower viewport end
		
	//////////////////////////////////////////// main viewport start
	glPushMatrix();							
		glViewport(0, windowY * 1/5, windowX * 3/4, windowY * 4/5);

		if(thirdPersonCarema == true)		//For the third person camera
		{	
			cameraX = car->getPosX()-50;
			cameraY = car->getPosY()+30;
			cameraZ = 0; 		
			lookatX = car->getPosX();
			lookatY = car->getPosY();
			lookatZ = 0; 		
		}
		else                                 //For the first person camera
		{
			if(difficulty==0)                    // car3 camera
			{
				cameraX = car->getPosX();
				cameraY = car->getPosY() + 7.0; 
				cameraZ = car->getPosZ(); 
				lookatX = car->getPosX() + 5 * cos(motoRotateAngle);
				lookatY = car->getPosY() + 7.0;
				lookatZ = car->getPosZ() - 5 * sin(motoRotateAngle);
			}
			else if(difficulty==1)               // car2 camera
			{
				cameraX = car->getPosX()+4;
				cameraY = car->getPosY() + 14.0; 
				cameraZ = car->getPosZ(); 
				lookatX = car->getPosX() + 5 * cos(motoRotateAngle);
				lookatY = car->getPosY() + 14.0;
				lookatZ = car->getPosZ() - 5 * sin(motoRotateAngle);
			}
			else if(difficulty==2)              // car1 camera
			{
				cameraX = car->getPosX()-1;
				cameraY = car->getPosY() + 15.0; 
				cameraZ = car->getPosZ(); 
				lookatX = car->getPosX() + 5 * cos(motoRotateAngle);
				lookatY = car->getPosY() + 15.0;
				lookatZ = car->getPosZ() - 5 * sin(motoRotateAngle); 
			}
		}

		gluLookAt(cameraX, cameraY, cameraZ, lookatX, lookatY, lookatZ, 0.0, 1.0, 0.0); 	
		
		light(); // enable lighting function working

		
		scene->drawTrack(); // draw track

		if(isGenerateAD)
		{
			int ad_number[2];
			for (int i = 0; i < 2; ++i)
			{
				ad_number[i] = rand()%4 + 1;	
			}
			scene ->setAd(texture[ad_number[0]], texture[ad_number[1]]);
			isGenerateAD = false;
		}
		scene ->drawBillboard();
				
		// draw car
		glPushMatrix();	
			glTranslatef(car->getPosX(), car->getPosY(), car->getPosZ());
			glRotatef(motoRotateAngle * 180 / PI, 0.0, 1.0, 0.0);					
			car->drawCar();
			car->drawTrailer();
			double randomDistance1[50];
			for (int i = 0; i < 50; ++i)
			{
				randomDistance1[i] = rand()%700/100.0;
			}
			scene->UpdateParticles1(randomDistance1);
			if (difficulty == 0)
				scene->DrawParticles(3);
			else if (difficulty == 1)
				scene->DrawParticles(2);
			else
				scene->DrawParticles(1);
		glPopMatrix();

		if (trackCounter==0)   //difficulty
		{
			scene->drawStartLine(difficulty);			
		}

		if((currentLevelAndDifficultyDistance - distanceRun)<990)
		{
			//scene->drawFinalLine(difficulty);	
		}
		
		
		// draw bus
		glPushMatrix();
			if (isGenerateBus)
			{
				bool isLegalGenerate1 = false;
				do{
					for (int i = 0; i < 2; ++i)
					{
						busPosXChoice[i] = rand() % 300 - 300; // random position for x
						busPosZChoice[i] = rand() % 3 - 1; // random postion for z
					}
					if (abs(busPosXChoice[0] - busPosXChoice[1]) > bus1->getLength() * 2) // two bus not collide
					{
						isLegalGenerate1 = true;
					}
				}while(!isLegalGenerate1);

				bus1->setPosX(busPosXChoice[0]);
				bus1->setPosZ(busPosZChoice[0]* 35.0);
				bus2->setPosX(busPosXChoice[1]);
				bus2->setPosZ(busPosZChoice[1]* 35.0);

				isGenerateBus = false;
			}

			bus1->moveBus(); // move bus
			bus2->moveBus();
			bus1->drawBus(); // draw bus
			bus2->drawBus();

			glPushMatrix();
				glTranslatef(bus1->getPosX(), bus1->getPosY(), bus1->getPosZ());
				double randomDistance2[50];
				for (int i = 0; i < 50; ++i)
				{
					randomDistance2[i] = rand()%1000/100.0;
				}
				scene->UpdateParticles1(randomDistance2);
				scene->DrawParticles(4);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(bus2->getPosX(), bus2->getPosY(), bus2->getPosZ());
				double randomDistance3[50];
				for (int i = 0; i < 50; ++i)
				{
					randomDistance3[i] = rand()%1000/100.0;
				}
				scene->UpdateParticles1(randomDistance3);
				scene->DrawParticles(4);
			glPopMatrix();
		glPopMatrix();
	
		// generate boxes if list has less than 3 boxes
		if (isGenerateBox)
		{
			// delete old boxes
			list<Box*>::iterator it = boxList.begin(); 
			while(it != boxList.end())
			{
				delete(*it); // delete box
				it = boxList.erase(it); // remove from list
			}

			// generate new boxes
			while (boxList.size() < 3)
			{
				for (int i = 0; i < 2; ++i)
				{
					boxChoice[i] = rand() % 3 - 1; // 0~decelerate, 1~accelerate, -1~special
				}
				boxSpeedChoice = (rand() % 4 + 2) / 10.0f; // speed from 0.02 to 0.05
				
				bool isLegalGenerate2 = false;
				Box * newbox;
				do{
					boxPosChoice = rand() % 500 - 300; // random position
					
					if (boxChoice[0] == 0) // 0~decelerate
					{
						newbox = new Box(8, boxChoice[0], pow(-1.0, boxPosChoice) * boxSpeedChoice, boxPosChoice, 8.0, boxChoice[1] * 35.0, texture[17]);
					}
					else if (boxChoice[0] == 1) // 1~accelerate
					{
						newbox = new Box(8, boxChoice[0], boxSpeedChoice, boxPosChoice, 8.0, boxChoice[1] * 35.0, texture[16]);
					}
					else // -1~special
					{
						newbox = new Box(8, boxChoice[0], -boxSpeedChoice, boxPosChoice, 8.0, boxChoice[1] * 35.0, texture[15]);
					}					
					if ((!isBoxCollisionWithBus(bus1, newbox)) && (!isBoxCollisionWithBus(bus2, newbox)))
					{
						isLegalGenerate2 = true;
					}
				}while(!isLegalGenerate2);
				
				boxList.push_back(newbox);	
			}
			isGenerateBox = false;
		}

		// draw boxes in list
		if (boxList.size() > 0)
		{
			list<Box*>::iterator it = boxList.begin(); 
			while(it != boxList.end())
			{
				glPushMatrix();
					glTranslatef((*it)->getPosX(), (*it)->getPosY(), (*it)->getPosZ());
					(*it)->drawBox();
				glPopMatrix();
				++it;
			}
		}
	glPopMatrix();							
	//////////////////////////////////////////////////// main viewport end
	
	driveMoto(car);
	
	// check collision with box	
	list<Box*>::iterator it = boxList.begin(); 
	while(it != boxList.end())
	{
		if (isCollisionWithBox(car, (*it)))
		{
			if ((car->getSpeed() + (*it)->getSpeed()) > 0)
			{
				if ((car->getSpeed() + (*it)->getSpeed()) < 3)
					car->setSpeed(car->getSpeed() + (*it)->getSpeed()); // change moto speed according to collision box property
				else car->setSpeed(3.0); // maximum speed
			}
			else car->setSpeed(0); // avoid speed below zero
			delete(*it); // delete box
			it = boxList.erase(it); // remove from list
		}
		else ++it;
	}
	
	// check collision with bus
	if  (isCollisionWithBus(car, bus1))
	{
		if (car->getPosX() <= bus1->getPosX())
			car->setPosX(car->getPosX() - car->getLength());
		else car->setPosX(car->getPosX() + car->getLength());
		if (car->getPosZ() <= bus1->getPosZ())
			car->setPosZ(car->getPosZ() - car->getWidth());
		else car->setPosZ(car->getPosZ() + car->getWidth());
		isRotate = true;
	}

	if (isCollisionWithBus(car, bus2))
		{
		if (car->getPosX() <= bus2->getPosX())
			car->setPosX(car->getPosX() - car->getLength());
		else car->setPosX(car->getPosX() + car->getLength());
		if (car->getPosZ() <= bus2->getPosZ())
			car->setPosZ(car->getPosZ() - car->getWidth());
		else car->setPosZ(car->getPosZ() + car->getWidth());
		isRotate = true;
	}
	
	// rotate car after collision
	if ((isRotate) && (motoRotateAngle <= 330))
	{
		motoRotateAngle += 30;
		car->setSpeed(0);
		moveLeft = false;
		moveRight = false;
	}
	else
	{
		isRotate = false;
		motoRotateAngle = 0;
	}

	
}

// Drawing routine.
void drawScene(void)
{
	resize(windowX,windowY);
	glLoadIdentity();
	
	if(gameState==0)
	{
		displaySelectCarScreen();
	}	
	else if(gameState==1)
	{
		glDisable(GL_LIGHT3);
		displayRunScreen();
	}
	glutSwapBuffers();
}

// Initialization routine.
void setup(void) 
{
	glEnable(GL_LIGHTING);
	float globAmb[] = { 1, 1, 1, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);

	glClearColor(1.0, 1.0, 1.0, 0.0);  
	glEnable (GL_LINE_SMOOTH);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);

	initParameterAnyTime();
	initParameterGameStart();

	car1 = new Car1(texture[5], texture[6], texture[7]);
	car2 = new Car2(texture[8], texture[9], texture[10]);
	car3 = new Car3(texture[11], texture[12], texture[13]);
	bus1 = new Bus(texture[18], texture[19], texture[20], texture[21], -500, 0, -35);
	bus2 = new Bus(texture[18], texture[19], texture[20], texture[21], -300, 0, 35);

	int ad_number[2];
	for (int i = 0; i < 2; ++i)
	{
		ad_number[i] = rand()%4 + 1;	
	}
	scene = new DrawScene(texture[ad_number[0]], texture[ad_number[1]], texture[0]);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	if (h == 0) h = 1; //to avoid divide-by-zero
	
	windowX = w;
	windowY = h;

    //glViewport(0, 0, w, h); //adjust GL viewport	
    glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
    glLoadIdentity();	
	gluPerspective(90, (GLfloat)w/(GLfloat)h, 5, 800.0);
    glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	if(gameState == 0)
	{
		switch(key) 
		{
			case 13:
				gameState = 1;
				if(frameCount<20)
					frameCount = 20;

				if(currentSelect == 0)
				{
					car = car3;
					currentLevelAndDifficultyDistance = standardEasyDistance * frameCount / standardFrameCount;					
									
				}
				else if(currentSelect == 1)
				{
					car = car2;
					currentLevelAndDifficultyDistance = standardNormalDistance * frameCount / standardFrameCount;;
					
				}
				else if(currentSelect == 2)
				{
					car = car1;
					currentLevelAndDifficultyDistance = standardHardDistance * frameCount / standardFrameCount;;
					
				}
				difficulty = currentSelect;				
				break;

			case 27:
				exit(0);
				break;
		}
	}

	else if(gameState == 1)
	{
		switch(key) 
		{
			case '1':
				thirdPersonCarema = false;
				glutPostRedisplay();
				break;

			case '3':
				thirdPersonCarema = true;
				glutPostRedisplay();
				break;

			case 13:
				if(isFail == true)
				{
					gameState = 0;
					initParameterAnyTime();
					initParameterGameStart();
					car->setPosX(-699);
					car->setPosZ(0);
				}else if(isWin == true)
				{
					level++;
					car->setPosX(-699);
					car->setPosZ(0);
					

					if(difficulty==0)
					{
						easyIndividualLastLevelScore = easyIndividualLastLevelScore + distanceRun;
						currentLevelAndDifficultyDistance = (standardEasyDistance + (level-1)*1000)* frameCount / standardFrameCount;	
						
		
					}else if(difficulty==1)
					{
						normalIndividualLastLevelScore = normalIndividualLastLevelScore + distanceRun;
						currentLevelAndDifficultyDistance = (standardNormalDistance + (level-1)*2000)* frameCount / standardFrameCount;	

					}else if(difficulty==2)
					{
						hardIndividualLastLevelScore = hardIndividualLastLevelScore + distanceRun;
						currentLevelAndDifficultyDistance = (standardHardDistance + (level-1)*3000)* frameCount / standardFrameCount;
					}
					initParameterAnyTime();
				}

				break;
						
			case 27:
				exit(0);
				break;

			default:
				break;
		}
	}
   
}

void specialKey(int key, int x, int y)     // called on special key pressed
{ 
	if(gameState==0)
	{
		switch(key) 
		{
			case GLUT_KEY_LEFT:     // select car  according to counterclockwise direction 
				currentSelect = (currentSelect+2)%3;				
				break;

			case GLUT_KEY_RIGHT:    // select car  according to clockwise direction 
				currentSelect = (currentSelect+1)%3;				
				break;
		}
	}
	else if(gameState==1)
	{
		switch(key) 
		{
			case GLUT_KEY_LEFT: // change to left 
				if(isAnimate)
				{
					if (moveRight) // just wanna to stop moving right
					{
						changeLaneStartTime = changeLaneCurrentTime = glutGet(GLUT_ELAPSED_TIME);
						moveRight = false;
					}
					else // indeed wanna to move left
					{
						moveLeft = true;
					}
				}
				break;

			case GLUT_KEY_RIGHT: // change to right 
				if (isAnimate)
				{
					if (moveLeft) // just wanna to stop moving left
					{
						changeLaneStartTime = changeLaneCurrentTime = glutGet(GLUT_ELAPSED_TIME);
						moveLeft = false;
					}
					else // indeed wanna to move right
					{
						moveRight = true;
					}
				}
				break;

			case GLUT_KEY_UP: // speed up / move forward
				isUPpressed = true;
				UPcurrent = UPstart = glutGet(GLUT_ELAPSED_TIME);
				if(!firstPressUP)
				{
					firstPressUP = true;
				}
				if(!isAnimate)
				{
					currentTime = previousTime = glutGet(GLUT_ELAPSED_TIME);
				}
				if(!toSpeedUp)
				{
					motoCurrentTime = motoStartTime = glutGet(GLUT_ELAPSED_TIME);
				}
				isAnimate = true;
				isMotoStart = true;
				toSpeedUp = true;
				toSlowDown = false;
				break;

			case GLUT_KEY_DOWN: // slow down / stop
				if(!firstPressDOWN)
				{
					firstPressDOWN = true;
				}
				if(!toSlowDown)
				{
					motoCurrentTime = motoStartTime = glutGet(GLUT_ELAPSED_TIME);
				}
				isAnimate = true;
				toSpeedUp = false;
				toSlowDown = true;
				break; 

			case GLUT_KEY_F1: 
				isLight1on = !isLight1on;	// turn on/off light 1
				glutPostRedisplay();
				break;

			case GLUT_KEY_F2: 
				isLight2on = !isLight2on;	// turn on/off light 2
				glutPostRedisplay();
				break;
		}
	}
}

void displayMenu(void)	
{
	printf("\n Welcome! Following are the commands: \n");
	printf("\n KEY \t\t\t FUNCTION");
	printf("\n 1  \t\t first person camera");
	printf("\n 3  \t\t third person camera");
	printf("\n F1  \t\t turn on/off light1");
	printf("\n F2  \t\t turn on/off light2");	
	printf("\n h \t\t\t decrease cutoff angle");
	printf("\n H \t\t\t increase cutoff angle");	
	printf("\n Z \t\t\t zoom in");
	printf("\n z \t\t\t zoom out");
}

int main(int argc, char **argv) 
{
	glutInit(&argc, argv);	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 	
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(0, 0); 
	glutCreateWindow("Motocycle.cpp");
	glGenTextures(22, texture);
	loadExternalTextures();
	setup(); 
	glutDisplayFunc(drawScene); 
	glutReshapeFunc(resize);  
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKey); 
	glutIdleFunc(drawScene);
	displayMenu();
	glutFullScreen();
	glutMainLoop(); 

	return 0;  
}

GLvoid driveMoto(Car* car)
{
	if(!isWin && !isFail)
	{
		currentTime = glutGet(GLUT_ELAPSED_TIME);
		timeInterval=( (float)(currentTime - previousTime) )/1000;
		changeLaneCurrentTime = glutGet(GLUT_ELAPSED_TIME);
		changeLaneTimeInterval = ( (float)(changeLaneCurrentTime - changeLaneStartTime) )/1000;
	
		if(moveLeft)
		{
			if (changeLaneTimeInterval <= 1000)
			{
				if(car->getPosZ() <= -50 )
				{
					moveLeft = false;
					car->setPosZ(-35);
				}
				else
				{
					car->setPosZ(car->getPosZ() - 0.1 * (standardFrameCount) / frameCount);//car->getSpeed()/2);
				}
			}
			else moveLeft = false;
		}

		if(moveRight)
		{
			if (changeLaneTimeInterval <= 1000)
			{
				if(car->getPosZ() >= 50)
				{
					moveRight = false;
					car->setPosZ(35);
				}
				else
				{ 
					car->setPosZ(car->getPosZ() + 0.1 * (standardFrameCount) / frameCount);//car->getSpeed()/2);
				}
			}
			else moveRight = false;
		}

		if(toSpeedUp)
		{   
			if(!isWin && !isFail)
			{
				UPcurrent = glutGet(GLUT_ELAPSED_TIME);
				UPinterval = UPcurrent - UPstart;
			}
			if(firstPressUP )
			{
				firstPressUP = false;
				car->setSpeed(car->getSpeed()+0.02);
				if(car->getSpeed() >= 3)
				{
					car->setSpeed(3);
				}
			}
			if(UPinterval >= 1000)
			{	
				if(car->getSpeed() > 0 )
				{
					car->setSpeed(car->getSpeed() -0.03);
					if(car->getSpeed() <= 0)
					{
						car->setSpeed(0);
					}
				}
				UPstart = UPcurrent;
			}
			if(distanceRun >= currentLevelAndDifficultyDistance && timeInterval <=60) //win
			{
				car->setSpeed(0);
				isWin = true;
			}
			if( timeInterval >= 60 && distanceRun < currentLevelAndDifficultyDistance) //fail
			{
				car->setSpeed(0);
				isFail = true;
			}
		}

		if(car->getPosX() >= 300)
		{
			trackCounter ++;
			car->setPosX(-700);
			isGenerateAD = true;
			isGenerateBox = true;
			isGenerateBus = true;
		}

		if(toSlowDown)
		{
			if(!isWin && !isFail)
			{
				UPstart = UPcurrent =motoCurrentTime = glutGet(GLUT_ELAPSED_TIME);
				motoTimeInterval = motoCurrentTime - motoStartTime;
			}
			if(firstPressDOWN)
			{
				firstPressDOWN = false;
				car->setSpeed(car->getSpeed()-0.05);
				if(car->getSpeed() <= 0)
				{
					car->setSpeed(0);
				}
			}
			if(motoTimeInterval >= 1000)
			{	
				if(car->getSpeed() > 0 )
				{
					car->setSpeed(car->getSpeed()-0.05);
					if(car->getSpeed() <= 0)
					{
						car->setSpeed(0);
					}
				}
				motoStartTime = motoCurrentTime;
			}
	
		}
		car->setPosX(car->getPosX() + car->getSpeed());
	}
}


BitMapFile *getBMPData(string filename)
{
   BitMapFile *bmp = new BitMapFile;
   unsigned int size, offset, headerSize;
  
   // Read input file name.
   ifstream infile(filename.c_str(), ios::binary);
 
   // Get the starting point of the image data.
   infile.seekg(10);
   infile.read((char *) &offset, 4); 
   
   // Get the header size of the bitmap.
   infile.read((char *) &headerSize,4);

   // Get width and height values in the bitmap header.
   infile.seekg(18);
   infile.read( (char *) &bmp->sizeX, 4);
   infile.read( (char *) &bmp->sizeY, 4);

   // Allocate buffer for the image.
   size = bmp->sizeX * bmp->sizeY * 24;
   bmp->data = new unsigned char[size];

   // Read bitmap data.
   infile.seekg(offset);
   infile.read((char *) bmp->data , size);
   
   // Reverse color from bgr to rgb.
   int temp;
   for (int i = 0; i < (int)size; i += 3)
   { 
      temp = bmp->data[i];
	  bmp->data[i] = bmp->data[i+2];
	  bmp->data[i+2] = temp;
   }

   return bmp;
}

void loadExternalTextures()			
{
	// Local storage for bmp image data.
	BitMapFile *image[23]; 
   
	// Load the textures.
	image[0] = getBMPData("Textures/road_texture.bmp"); 
	image[1] = getBMPData("Textures/ad_mc.bmp");   
	image[2] = getBMPData("Textures/ad_insurance.bmp");
	image[3] = getBMPData("Textures/ad_cola.bmp");
	image[4] = getBMPData("Textures/ad_donuts.bmp");  
	image[5] = getBMPData("Textures/car1_shaft.bmp"); 
	image[6] = getBMPData("Textures/car1_pipe.bmp");
	image[7] = getBMPData("Textures/car1_cargo.bmp");  
	image[8] = getBMPData("Textures/car2_shaft.bmp"); 
	image[9] = getBMPData("Textures/car2_pipe.bmp");
	image[10] = getBMPData("Textures/car2_cargo.bmp");
	image[11] = getBMPData("Textures/car3_shaft.bmp");
	image[12] = getBMPData("Textures/car3_pipe.bmp");
	image[13] = getBMPData("Textures/car3_cargo.bmp"); 
	image[14] = getBMPData("Textures/meter.bmp");
	image[15] = getBMPData("Textures/special.bmp");
	image[16] = getBMPData("Textures/accelerate.bmp");
	image[17] = getBMPData("Textures/decelerate.bmp");
	image[18] = getBMPData("Textures/bus_back.bmp");
	image[19] = getBMPData("Textures/bus_front.bmp");
	image[20] = getBMPData("Textures/bus_left.bmp");
	image[21] = getBMPData("Textures/bus_right.bmp");
	image[22] = getBMPData("Textures/game_logo.bmp");

   // Bind image to texture index[0].  - road texture
   glBindTexture(GL_TEXTURE_2D, texture[0]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[0]->sizeX, image[0]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[0]->data);
  
   
   // Bind image to texture index[1]. - billboard ad 1
   glBindTexture(GL_TEXTURE_2D, texture[1]);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[1]->sizeX, image[1]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[1]->data);	
				

   // Bind image to texture index[2]. - billboard ad 2
   glBindTexture(GL_TEXTURE_2D, texture[2]);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[2]->sizeX, image[2]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[2]->data);	

   // Bind image to texture index[3]. - billboard ad 3
   glBindTexture(GL_TEXTURE_2D, texture[3]);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[3]->sizeX, image[3]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[3]->data);	

   // Bind image to texture index[4]. - billboard ad 4
   glBindTexture(GL_TEXTURE_2D, texture[4]);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[4]->sizeX, image[4]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[4]->data);
				
   // Bind image to texture index[5].  - Car1 shaft
   glBindTexture(GL_TEXTURE_2D, texture[5]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[5]->sizeX, image[5]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[5]->data);
   
   // Bind image to texture index[6].  - Car1 pipe
   glBindTexture(GL_TEXTURE_2D, texture[6]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[6]->sizeX, image[6]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[6]->data);
	
   // Bind image to texture index[7].  - Car1 cargo
   glBindTexture(GL_TEXTURE_2D, texture[7]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[7]->sizeX, image[7]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[7]->data);

   // Bind image to texture index[8].  - Car2 shaft
   glBindTexture(GL_TEXTURE_2D, texture[8]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[8]->sizeX, image[8]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[8]->data);

   // Bind image to texture index[9].  - Car2 pipe
   glBindTexture(GL_TEXTURE_2D, texture[9]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[9]->sizeX, image[9]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[9]->data);

   // Bind image to texture index[10].  - Car2 cargo
   glBindTexture(GL_TEXTURE_2D, texture[10]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[10]->sizeX, image[10]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[10]->data);

   // Bind image to texture index[11].  - Car3 shaft
   glBindTexture(GL_TEXTURE_2D, texture[11]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[11]->sizeX, image[11]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[11]->data);

   // Bind image to texture index[12].  - Car3 pipe
   glBindTexture(GL_TEXTURE_2D, texture[12]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[12]->sizeX, image[12]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[12]->data);
   
   // Bind image to texture index[13].  - Car3 cargo
   glBindTexture(GL_TEXTURE_2D, texture[13]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[13]->sizeX, image[13]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[13]->data);
   
   // Bind image to texture index[14].  - meter
   glBindTexture(GL_TEXTURE_2D, texture[14]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[14]->sizeX, image[14]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[14]->data);

   // Bind image to texture index[15].  - box specialTexture
   glBindTexture(GL_TEXTURE_2D, texture[15]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[15]->sizeX, image[15]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[15]->data);

     // Bind image to texture index[16].  - box accelerateTexture
   glBindTexture(GL_TEXTURE_2D, texture[16]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[16]->sizeX, image[16]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[16]->data);
	
     // Bind image to texture index[17].  - box decelerateTexture
   glBindTexture(GL_TEXTURE_2D, texture[17]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[17]->sizeX, image[17]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[17]->data);

   // Bind image to texture index[18].  - bus back texture
   glBindTexture(GL_TEXTURE_2D, texture[18]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[18]->sizeX, image[18]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[18]->data);

   // Bind image to texture index[19].  - bus front texture
   glBindTexture(GL_TEXTURE_2D, texture[19]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[19]->sizeX, image[19]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[19]->data);

   // Bind image to texture index[20].  - bus left texture
   glBindTexture(GL_TEXTURE_2D, texture[20]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[20]->sizeX, image[20]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[20]->data);

   // Bind image to texture index[21].  - bus right texture
   glBindTexture(GL_TEXTURE_2D, texture[21]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[21]->sizeX, image[21]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[21]->data);

   // Bind image to texture index[22].  - Game logo
   glBindTexture(GL_TEXTURE_2D, texture[22]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[22]->sizeX, image[22]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[22]->data);
}
