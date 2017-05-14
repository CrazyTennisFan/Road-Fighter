#pragma once
#include <GL/glut.h>
#include <time.h>
#include <math.h>

class DrawScene {

public:
	DrawScene();
	DrawScene(int adTexture1, int adTexture2, int trackTexture);
	~DrawScene();
	
	void drawTrack();
	void UpdateParticles1(double *distanceArray);
	void DrawParticles(int carNumber);
	GLvoid drawBillboard();
	void setAd(int ad_texture1, int adTexture2);


	//////////////////////Draw some others
	void drawViewportDivideLine1();
	void drawViewportDivideLine2();
	void drawStartLine(int difficulty);
	void drawFinalLine(int difficulty);

private:
	float PI;
	int particleCount;
	int adTexture1;
	int adTexture2;
	int trackTexture; 
	float material_Grey[4];
	float material_Blue[4];
	float materialShininess;
	GLUquadric *quadratic;

	struct PARTICLES
	{
		double Xpos;
		double Ypos;
		double Zpos;
		double Xoriginpos;
		double Yoriginpos;
		double Zoriginpos;
		double Xmov;
		double Ymov;
		double Zmov;
		double Red;
		double Green;
		double Blue;
		double Direction;
		double Acceleration;
		double Deceleration;
		double Scalez;
		bool Visible;
	};

	PARTICLES Particle[200];

	void CreateParticles();
	
	
	////////////////////billboard functions
	GLvoid drawBillboardLeftLeg();
	GLvoid drawBillboardRightLeg();
	GLvoid drawBillboardFace(int adTexture);
	GLvoid drawBillboardArm();

	
	
	
	
};