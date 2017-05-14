#include "Car2.h"


Car2::Car2(int shaftTexture, int pipeTexture, int cargoTexture)
{
	length = 22.5; // half
	width = 5; // half
	this->shaftTexture = shaftTexture;
	this->pipeTexture = pipeTexture;
	this->cargoTexture = cargoTexture;
	quadratic = gluNewQuadric();

	material_Black[0] = 0.0;
	material_Black[1] = 0.0;
	material_Black[2] = 0.0;
	material_Black[3] = 1.0;

	material_Orange[0] = 1.0;
	material_Orange[1] = 0.25;
	material_Orange[2] = 0.0;
	material_Orange[3] = 1.0;

	material_SlateBlue[0] = 0.0;
	material_SlateBlue[1] = 0.498039;
	material_SlateBlue[2] = 1.0;
	material_SlateBlue[3] = 1.0;

	materialShininess = 50.0;
}


Car2::~Car2()
{}

void Car2::drawCar()
{
	wheelRotateAngle += speed / 2.5f;
	drawCar2();
}

void Car2::drawTrailer()
{
	drawCar2TrailerAndHitch();
}

// draw motocycle
void Car2::drawCar2()
{
	drawCar2FrontShaft();
	drawCar2FrontLeftShaft();
	drawCar2FrontRightShaft();
	drawCar2LeftHandleBar();
	drawCar2RightHandleBar();
	drawCar2FrontPanel();
	drawCar2FrontLight();
	drawCar2FrontWheel();
	drawCar2FrontWheelMudTile();
	drawCar2FrontConnectShaft();
	drawCar2GasTank();
	drawCar2Engine();
	drawCar2Battery();
	drawCar2Seat();
	drawCar2RearLeftShaft();
	drawCar2RearRightShaft();
	drawCar2FrontSlantPipe();
	drawCar2RearSlantPipe();
	drawCar2MiddleHorizontalPipe();
	drawCar2ExhaustPipe();
	drawCar2RearWheel();
	drawCar2RearWheelMudTile();
	drawCar2RearLight();
}

// draw trailer
void Car2::drawCar2TrailerAndHitch()
{
	drawCar2Hitch();
	drawCar2HitchTorus();
	drawCar2TrailerLeftWheel();
	drawCar2TrailerRightWheel();
	drawCar2TrailerLeftWheelMudTile();
	drawCar2TrailerRightWheelMudTile();
	drawCar2TrailerWheelConnectingShaft();
	drawCar2TrailerCargo();
}

// draw wheel shaft
void Car2::drawCar2WheelShaft(float x, float y, float z)
{
	glPushMatrix();
	glTranslatef(x + y * sin(wheelRotateAngle), y * cos(wheelRotateAngle), z);
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	glRotatef(0.0, 0.0, 0.0, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(quadratic, 0.1f, 0.1f, 1.7f, 10, 20); // shaft at angle 0
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(x + y * sin(wheelRotateAngle - 72 * PI/180), y * cos(wheelRotateAngle - 72 * PI/180), z);
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	glRotatef(72, 0.0, 0.0, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(quadratic, 0.1f, 0.1f, 1.7f, 10, 20); // shaft at angle -72
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(x + y * sin(wheelRotateAngle - 144 * PI/180), y * cos(wheelRotateAngle - 144 * PI/180), z);
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	glRotatef(144, 0.0, 0.0, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(quadratic, 0.1f, 0.1f, 1.7f, 10, 20); // shaft at angle -144
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(x + y * sin(wheelRotateAngle - 216 * PI/180), y * cos(wheelRotateAngle - 216 * PI/180), z);
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	glRotatef(216, 0.0, 0.0, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(quadratic, 0.1f, 0.1f, 1.7f, 10, 20); // shaft at angle 72
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + y * sin(wheelRotateAngle - 288 * PI/180), y * cos(wheelRotateAngle - 288 * PI/180), z);
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	glRotatef(288, 0.0, 0.0, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(quadratic, 0.1f, 0.1f, 1.7f, 10, 20); // shaft at angle 144
	glPopMatrix();
}

// draw wheel mud tile
void Car2::drawCar2WheelMudTile()
{ 
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Orange);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Orange);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Orange);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(1.0, 0.25, 0.0); // OrangeRed
	
	int size = calculateIncreasingArc(0.0, 0.0, 0.6, 80, 0, -10);
		
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < size; ++i) // wheel mud tile - increasing quads - right
	{
		glVertex3f(xList[i], yList[i], 0.8);
		glVertex3f(xList[i], yList[i] - 1.0, 0.8);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < size; ++i) // wheel mud tile - increasing quads - left
	{
		glVertex3f(xList[i], yList[i], -0.8);
		glVertex3f(xList[i], yList[i] - 1.0, -0.8);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < size; ++i) // wheel mud tile - increasing quads - top
	{
		glVertex3f(xList[i], yList[i], -0.8);
		glVertex3f(xList[i], yList[i], 0.8);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < size; ++i) // wheel mud tile - increasing quads - bottom
	{
		glVertex3f(xList[i], yList[i] - 1.0, -0.8);
		glVertex3f(xList[i], yList[i] - 1.0, 0.8);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP); // wheel mud tile - increasing quads - back
	glVertex3f(xList[0], yList[0], 0.8);
	glVertex3f(xList[0], yList[0] - 1.0, 0.8);
	glVertex3f(xList[0], yList[0] - 1.0, -0.8);
	glVertex3f(xList[0], yList[0], -0.8);
	glEnd();

	size = calculateDecreasingArc(xList[size-1], yList[size-1], 0.6, 5, 90, 10);
		
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < size; ++i) // wheel mud tile - decreasing quads - right
	{
		glVertex3f(xList[i], yList[i], 0.8);
		glVertex3f(xList[i], yList[i] - 1.0, 0.8);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < size; ++i) // wheel mud tile - decreasing quads - left
	{
		glVertex3f(xList[i], yList[i], -0.8);
		glVertex3f(xList[i], yList[i] - 1.0, -0.8);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < size; ++i) // wheel mud tile - decreasing quads - top
	{
		glVertex3f(xList[i], yList[i], -0.8);
		glVertex3f(xList[i], yList[i], 0.8);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < size; ++i) // wheel mud tile - decreasing quads - bottom
	{
		glVertex3f(xList[i], yList[i] - 1.0, -0.8);
		glVertex3f(xList[i], yList[i] - 1.0, 0.8);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP); // wheel mud tile - decreasing quads - front
	glVertex3f(xList[size-1], yList[size-1], 0.8);
	glVertex3f(xList[size-1], yList[size-1] - 1.0, 0.8);
	glVertex3f(xList[size-1], yList[size-1] - 1.0, -0.8);
	glVertex3f(xList[size-1], yList[size-1], -0.8);
	glEnd();
}

void Car2::drawCar2FrontWheel()
{
	glPushMatrix();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(20.0, 0.0, 0.0);
	glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	glutSolidTorus(0.5, 2.5, 10, 20); // front wheel
	glPopMatrix();

	glPushMatrix();
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glTranslatef(20.0, 0.0, -1.0);
	glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	gluCylinder(quadratic, 0.3f, 0.3f, 2.0f, 10, 20); // shaft in center of front wheel
	glPopMatrix();

	drawCar2WheelShaft(20.0, 0.3, 0.0);
	
	glPopMatrix();
}

void Car2::drawCar2FrontWheelMudTile()
{
	glPushMatrix();
	glTranslatef(16.8, 0.6, 0.0);
	drawCar2WheelMudTile();
	glPopMatrix();
}

void Car2::drawCar2FrontLeftShaft()
{
	glPushMatrix();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_SlateBlue);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.498039, 1.0); // SlateBlue
	glTranslatef(20.0, 0.0, -1.0);
	glRotatef(30, 0.0, 0.0, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0); 
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // Specify how texture values combine with current surface color values.
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, shaftTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 10.0f, 10, 20); // left shaft to connect front wheel
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void Car2::drawCar2FrontRightShaft()
{
	glPushMatrix();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_SlateBlue);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.498039, 1.0); // SlateBlue
	glTranslatef(20.0, 0.0, 1.0);
	glRotatef(30, 0.0, 0.0, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0); 
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // Specify how texture values combine with current surface color values.
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, shaftTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 10.0f, 10, 20); // right shaft to connect front wheel
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void Car2::drawCar2FrontShaft()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_SlateBlue);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.498039, 1.0); // SlateBlue
	glTranslatef(15.0, 10.0 * cos(30 * PI/180), -5.0);
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // Specify how texture values combine with current surface color values.
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, shaftTexture);
	gluCylinder(quadratic, 0.4f, 0.4f, 10.0f, 10, 20); // front shaft to connect handle bars
	glDisable(GL_TEXTURE_2D);
		
	glPopMatrix();
}

void Car2::drawCar2LeftHandleBar()
{
	glPushMatrix();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0);
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glTranslatef(15.0, 10.0 * cos(30 * PI/180), -5.0);
	glRotatef(-150, 0.0, 1.0, 0.0);
	gluCylinder(quadratic, 0.5f, 0.5f, 2.0f, 10, 20); // left handle bar
	
	glPopMatrix();
}

void Car2::drawCar2RightHandleBar()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0);
	gluQuadricDrawStyle(quadratic, GLU_FILL);

	glTranslatef(15.0, 10.0 * cos(30 * PI/180), 5.0);
	glRotatef(-30, 0.0, 1.0, 0.0);
	gluCylinder(quadratic, 0.5f, 0.5f, 2.0f, 10, 20); // right handle bar
	
	glPopMatrix();
}

void Car2::drawCar2FrontPanel()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_SlateBlue);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.0, 0.498039, 1.0); // SlateBlue
	glTranslatef(16.5, 8.0 * cos(30 * PI/180), 0.0);
	glScalef(0.5, 1.0, 1.0);
	glutSolidCube(1.5); // front panel
	
	glPopMatrix();
}

void Car2::drawCar2FrontLight()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Orange);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Orange);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Orange);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(1.0, 0.25, 0.0); // OrangeRed
	glTranslatef(18.0, 8.0 * cos(30 * PI/180), 0.0);
	glRotatef(90, 0.0, 0.0, 1.0);
	int lightRadius = 1.0;
	int verticalSlice = 10; 
	int horizontalSlice = 10; 
	for(int i = 0; i < verticalSlice; i++)
	{
		glBegin(GL_TRIANGLE_STRIP);			// front light
		for(int j = 0; j <= horizontalSlice; j++)
		{
			glVertex3f( lightRadius * cos( (float)(i+1)/verticalSlice * PI/2.0 ) * cos( 2.0 * (float)j/horizontalSlice * PI ),
						lightRadius * sin( (float)(i+1)/verticalSlice * PI/2.0 ),
						lightRadius * cos( (float)(i+1)/verticalSlice * PI/2.0 ) * sin( 2.0 * (float)j/horizontalSlice * PI ) );
			glVertex3f( lightRadius * cos( (float)i/verticalSlice * PI/2.0 ) * cos( 2.0 * (float)j/horizontalSlice * PI ),
						lightRadius * sin( (float)i/verticalSlice * PI/2.0 ),
						lightRadius * cos( (float)i/verticalSlice * PI/2.0 ) * sin( 2.0 * (float)j/horizontalSlice * PI ) );         
		}
		glEnd();		
	}
	
	float t = 0;
	glRotatef(90, 1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);							// front light cover
	for(int i = 0; i < 10; ++i)
	{
		glVertex3f(lightRadius * cos(t), lightRadius * sin(t), 0.0);
		t += 2 * PI / 10;
	}
	glEnd();
	
	glPopMatrix();
}

void Car2::drawCar2FrontConnectShaft()
{
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_SlateBlue);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	glColor3f(0.0, 0.498039, 1.0); // SlateBlue
	glTranslatef(18.0, 4.0 * cos(30 * PI/180), -1.0);
	glScalef(0.5, 1.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // Specify how texture values combine with current surface color values.
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, pipeTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 2.0f, 10, 20); // front
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.498039, 1.0); // SlateBlue
	glTranslatef(14.8, -0.9, 0.0);
	glRotatef(-38, 0.0, 0.0, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // Specify how texture values combine with current surface color values.
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, pipeTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 5.7f, 10, 20);  // slant long
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.0, 0.498039, 1.0); // SlateBlue
	glTranslatef(14.8, -0.8, 0.0);
	glRotatef(-90, 0.0, 1.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // Specify how texture values combine with current surface color values.
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, pipeTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 6.5f, 10, 20);  // horizontal
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Car2::drawCar2GasTank()
{
	glPushMatrix(); 
		
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Orange);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Orange);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Orange);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(1.0, 0.25, 0.0); // OrangeRed
	
	glTranslatef(11.0, 2.5, 0.0);
		
	int size = calculateIncreasingArc(0.0, 0.0, 0.6, 45, 0, -5);
		
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	glBindTexture (GL_TEXTURE_2D, cargoTexture);	
	glBegin(GL_QUADS);
	for (int i = 0; i < size - 1; ++i) // gas tank increasing quads - right
	{
		glTexCoord2d (0, 0);
		glVertex3f(xList[i], 0, 2.0);
		glTexCoord2d (1, 0);
		glVertex3f(xList[i+1], 0, 2.0);
		glTexCoord2d (1, 1);
		glVertex3f(xList[i+1], yList[i+1], 2.0);
		glTexCoord2d (0, 1);
		glVertex3f(xList[i], yList[i], 2.0);
	}
	glEnd();
	
	glBegin(GL_QUADS);
	for (int i = 0; i < size - 1; ++i) // gas tank increasing quads - left
	{
		glTexCoord2d (0, 0);
		glVertex3f(xList[i], 0, -2.0);
		glTexCoord2d (1, 0);
		glVertex3f(xList[i+1], 0, -2.0);
		glTexCoord2d (1, 1);
		glVertex3f(xList[i+1], yList[i+1], -2.0);
		glTexCoord2d (0, 1);
		glVertex3f(xList[i], yList[i], -2.0);
	}
	glEnd();
	
	glBegin(GL_QUADS);
	for (int i = 0; i < size - 1; ++i) // gas tank increasing quads - top
	{
		glTexCoord2d (0, 0);
		glVertex3f(xList[i], yList[i], -2.0);
		glTexCoord2d (1, 0);
		glVertex3f(xList[i+1], yList[i+1], -2.0);
		glTexCoord2d (1, 1);
		glVertex3f(xList[i+1], yList[i+1], 2.0);
		glTexCoord2d (0, 1);
		glVertex3f(xList[i], yList[i], 2.0);
	}
	glEnd();
	
	size = calculateDecreasingArc(xList[size-1], yList[size-1], 0.6, 45, 90, 10);
		
	glBegin(GL_QUADS);
	for (int i = 0; i < size - 1; ++i) // gas tank decreasing quads - right
	{
		glTexCoord2d (0, 0);
		glVertex3f(xList[i], 0, 2.0);
		glTexCoord2d (1, 0);
		glVertex3f(xList[i+1], 0, 2.0);
		glTexCoord2d (1, 1);
		glVertex3f(xList[i+1], yList[i+1], 2.0);
		glTexCoord2d (0, 1);
		glVertex3f(xList[i], yList[i], 2.0);
	}
	glEnd();
	
	glBegin(GL_QUADS);
	for (int i = 0; i < size; ++i) // gas tank decreasing quads - left
	{
		glTexCoord2d (0, 0);
		glVertex3f(xList[i], 0, -2.0);
		glTexCoord2d (1, 0);
		glVertex3f(xList[i+1], 0, -2.0);
		glTexCoord2d (1, 1);
		glVertex3f(xList[i+1], yList[i+1], -2.0);
		glTexCoord2d (0, 1);
		glVertex3f(xList[i], yList[i], -2.0);
	}
	glEnd();
	
	glBegin(GL_QUADS);
	for (int i = 0; i < size - 1; ++i) // gas tank decreasing quads - top
	{
		glTexCoord2d (0, 0);
		glVertex3f(xList[i], yList[i], -2.0);
		glTexCoord2d (1, 0);
		glVertex3f(xList[i+1], yList[i+1], -2.0);
		glTexCoord2d (1, 1);
		glVertex3f(xList[i+1], yList[i+1], 2.0);
		glTexCoord2d (0, 1);
		glVertex3f(xList[i], yList[i], 2.0);
	}
	glEnd();
	
	glBegin(GL_QUADS);
	glTexCoord2d (0, 0);
	glVertex3f(xList[size-1], 0.0, -2.0);
	glTexCoord2d (1, 0);
	glVertex3f(xList[size-1], yList[size-1], -2.0);
	glTexCoord2d (1, 1);
	glVertex3f(xList[size-1], yList[size-1], 2.0);
	glTexCoord2d (0, 1);
	glVertex3f(xList[size-1], 0.0, 2.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, -2.0);
	glVertex3f(0.0, 0.0, 2.0); 
	glVertex3f(xList[size-1], yList[size-1], 2.0);
	glVertex3f(xList[size-1], yList[size-1], -2.0); // gas tank bottom
	glEnd();
	
	glPopMatrix();
}

void Car2::drawCar2Engine()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(14.5, 1.9, 1.0);
	glRotatef(-25, 0.0, 0.0, 1.0);
	glScalef(2.5, 0.3, 2.0);
	glutSolidCube(1.0); // engine parts
	glPopMatrix();

	glPushMatrix();
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glTranslatef(14.0, 0.2, 1.0);
	glRotatef(-30, 0.0, 0.0, 1.0);
	glRotatef(-100, 1.0, 0.0, 0.0);
	gluCylinder(quadratic, 0.3f, 0.3f, 1.5f, 10, 20);  
	glPopMatrix();

	glPushMatrix();
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glTranslatef(13.3, 0.6, 1.0);
	glRotatef(-30, 0.0, 0.0, 1.0);
	glRotatef(-100, 1.0, 0.0, 0.0);
	gluCylinder(quadratic, 0.3f, 0.3f, 1.5f, 10, 20);  
	glPopMatrix();

	glPushMatrix();
	glTranslatef(12.0, 1.9, 1.0);
	glRotatef(25, 0.0, 0.0, 1.0);
	glScalef(2.5, 0.3, 2.0);
	glutSolidCube(1.0); // engine parts
	glPopMatrix();

	glPushMatrix();
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glTranslatef(12.5, 0.2, 1.0);
	glRotatef(30, 0.0, 0.0, 1.0);
	glRotatef(-100, 1.0, 0.0, 0.0);
	gluCylinder(quadratic, 0.3f, 0.3f, 1.5f, 10, 20);  
	glPopMatrix();

	glPushMatrix();
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glTranslatef(13.3, 0.6, 1.0);
	glRotatef(30, 0.0, 0.0, 2.0);
	glRotatef(-100, 1.0, 0.0, 0.0);
	gluCylinder(quadratic, 0.3f, 0.3f, 1.5f, 10, 20);  
	glPopMatrix();

	glPushMatrix();
	glTranslatef(13.3, 0.1, 1.0);
	glutSolidSphere(0.8, 10, 10); // engine parts
	glPopMatrix();
}

void Car2::drawCar2Battery()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(9.5, 1.7, 0.0);
	glRotatef(30, 0.0, 0.0, 1.0);
	glutSolidCube(1.4); // battery parts
	glPopMatrix();
	glPushMatrix();
	glTranslatef(10.0, 0.2, 0.0);
	glutSolidCube(1.4); // battery parts
	glPopMatrix();
}

void Car2::drawCar2FrontSlantPipe()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_SlateBlue);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.0, 0.498039, 1.0); // SlateBlue
	glTranslatef(14.4, -0.9, 2.0);
	glRotatef(-30, 0.0, 0.0, 1.0);
	glRotatef(-100, 1.0, 0.0, 0.0);
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // Specify how texture values combine with current surface color values.
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, pipeTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 2.5f, 10, 20);  // front slant pipe
	glDisable(GL_TEXTURE_2D);
		
	glPopMatrix();
}

void Car2::drawCar2RearSlantPipe()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_SlateBlue);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.0, 0.498039, 1.0); // SlateBlue
	glTranslatef(12.3, -0.9, 2.0);
	glRotatef(30, 0.0, 0.0, 1.0);
	glRotatef(-100, 1.0, 0.0, 0.0);
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // Specify how texture values combine with current surface color values.
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, pipeTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 2.5f, 10, 20);  // back slant pipe
	glDisable(GL_TEXTURE_2D);
		
	glPopMatrix();
}

void Car2::drawCar2MiddleHorizontalPipe()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_SlateBlue);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.0, 0.498039, 1.0); // SlateBlue
	glTranslatef(14.5, -1.0, 2.0);
	glRotatef(-90, 0.0, 1.0, 0.0);
	
	glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // Specify how texture values combine with current surface color values.
		gluQuadricDrawStyle(quadratic, GLU_FILL);
		gluQuadricNormals (quadratic, GLU_SMOOTH);
		gluQuadricTexture (quadratic, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, pipeTexture);
		gluCylinder(quadratic, 0.3f, 0.4f, 7.0f, 10, 20);
		glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();
}

void Car2::drawCar2ExhaustPipe()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_SlateBlue);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.0, 0.498039, 1.0); // SlateBlue
	glTranslatef(7.5, -1.0, 2.0);
	glRotatef(-90, 0.0, 1.0, 0.0);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // Specify how texture values combine with current surface color values.
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, pipeTexture);
	gluCylinder(quadratic, 0.6f, 0.6f, 6.0f, 10, 20);  // exhaust pipe
	glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();
}

void Car2::drawCar2RearLeftShaft()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_SlateBlue);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.0, 0.498039, 1.0); // SlateBlue
	glTranslatef(5.0, 0.0, -1.0);
	glRotatef(-30, 0.0, 0.0, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0); 
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // Specify how texture values combine with current surface color values.
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, shaftTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 4.0f, 10, 20); // left shaft to connect rear wheel
	glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();
}

void Car2::drawCar2RearRightShaft()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_SlateBlue);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.0, 0.498039, 1.0); // SlateBlue
	glTranslatef(5.0, 0.0, 1.0);
	glRotatef(-30, 0.0, 0.0, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0); 
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // Specify how texture values combine with current surface color values.
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	gluQuadricNormals (quadratic, GLU_SMOOTH);
	gluQuadricTexture (quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, shaftTexture);
	gluCylinder(quadratic, 0.3f, 0.3f, 4.0f, 10, 20); // right shaft to connect rear wheel
	glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();
}

void Car2::drawCar2RearWheel()
{
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(5.0, 0.0, 0.0);
	glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	glutSolidTorus(0.5, 2.5, 10, 20); // rear wheel
	glPopMatrix();

	glPushMatrix();
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glTranslatef(5.0, 0.0, -1.0);
	glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	gluCylinder(quadratic, 0.3f, 0.3f, 2.0f, 10, 20); // shaft in center of rear wheel
	glPopMatrix();

	drawCar2WheelShaft(5.0, 0.3, 0.0);
}

void Car2::drawCar2RearWheelMudTile()
{
	glPushMatrix();
	glTranslatef(1.8, 0.6, 0.0);
	drawCar2WheelMudTile();
	glPopMatrix();
}

void Car2::drawCar2RearLight()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Orange);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Orange);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Orange);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(1.0, 0.25, 0.0); // OrangeRed
	glTranslatef(1.7, 2.5 * cos(30 * PI/180), 0.0);
	glRotatef(-90, 0.0, 0.0, 1.0);
	int lightRadius = 1.0;
	int verticalSlice = 10; 
	int horizontalSlice = 10;
	for(int i = 0; i < verticalSlice; i++)
	{
		glBegin(GL_TRIANGLE_STRIP);			// rear light
		for(int j = 0; j <= horizontalSlice; j++)
		{
			glVertex3f( lightRadius * cos( (float)(i+1)/verticalSlice * PI/2.0 ) * cos( 2.0 * (float)j/horizontalSlice * PI ),
						lightRadius * sin( (float)(i+1)/verticalSlice * PI/2.0 ),
						lightRadius * cos( (float)(i+1)/verticalSlice * PI/2.0 ) * sin( 2.0 * (float)j/horizontalSlice * PI ) );
			glVertex3f( lightRadius * cos( (float)i/verticalSlice * PI/2.0 ) * cos( 2.0 * (float)j/horizontalSlice * PI ),
						lightRadius * sin( (float)i/verticalSlice * PI/2.0 ),
						lightRadius * cos( (float)i/verticalSlice * PI/2.0 ) * sin( 2.0 * (float)j/horizontalSlice * PI ) );         
		}
		glEnd();
	}
	float t = 0;
	glRotatef(90, 1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);							// rear light cover
	for(int i = 0; i < 10; ++i)
	{
		glVertex3f(lightRadius * cos(t), lightRadius * sin(t), 0.0);
		t += 2 * PI / 10;
	}
	glEnd();
	glPopMatrix();
}

void Car2::drawCar2Seat()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0); 
	
	glTranslatef(7.5, 3.9, 0.0);
	glRotatef(30, 0.0, 0.0, 1.0);
	glRotatef(180, 1.0, 0.0, 0.0);
	int size = calculateIncreasingArc(0.0, 0.0, 0.4, 50, 0, -5);
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < size; ++i) // seat right
	{
		glVertex3f(xList[i], yList[i], 2.0);
		glVertex3f(xList[i], yList[i] + 1.0, 2.0);
	}
	glEnd();
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < size; ++i) // seat left
	{
		glVertex3f(xList[i], yList[i], -2.0);
		glVertex3f(xList[i], yList[i] + 1.0, -2.0);
	}
	glEnd();
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < size; ++i) // seat top
	{
		glVertex3f(xList[i], yList[i] + 1.0, -2.0);
		glVertex3f(xList[i], yList[i] + 1.0, 2.0);
	}
	glEnd();
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < size; ++i) // seat bottom
	{
		glVertex3f(xList[i], yList[i], -2.0);
		glVertex3f(xList[i], yList[i], 2.0);
	}
	glEnd();
	glBegin(GL_QUADS); // seat back
	glVertex3f(xList[0], yList[0], 2.0);
	glVertex3f(xList[0], yList[0] + 1.0, 2.0);
	glVertex3f(xList[0], yList[0] + 1.0, -2.0);
	glVertex3f(xList[0], yList[0], -2.0);
	glEnd();
	glBegin(GL_QUADS); // seat front
	glVertex3f(xList[size-1], yList[size-1], 2.0);
	glVertex3f(xList[size-1], yList[size-1] + 1.0, 2.0);
	glVertex3f(xList[size-1], yList[size-1] + 1.0, -2.0);
	glVertex3f(xList[size-1], yList[size-1], -2.0);
	glEnd();
	
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.0, 3.7, 0.0);
	glScalef(4.0, 0.6, 4.0);
	glutSolidCube(1.0); // flat seat part
	glPopMatrix();
}

void Car2::drawCar2Hitch()
{
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Orange);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Orange);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Orange);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	glColor3f(1.0, 0.25, 0.0); // OrangeRed
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glTranslatef(1.8, 0.0, 0.0);
	glRotatef(-90, 0.0, 1.0, 0.0);
	gluCylinder(quadratic, 0.1f, 0.1f, 1.0f, 10, 20);  // connecting rod
	glPopMatrix();

	glPushMatrix();
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glTranslatef(0.9, 0.0, 0.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(quadratic, 0.1f, 0.1f, 0.5f, 10, 20);  // hitch bottom
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.9, 0.8, 0.0);
	glutSolidSphere(0.3, 10, 10); // hitch top
	glPopMatrix();
}

void Car2::drawCar2HitchTorus()
{
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_SlateBlue);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	glColor3f(0.0, 0.498039, 1.0); // SlateBlue
	glTranslatef(0.9, 0.3, 0.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidTorus(0.1, 0.5, 10, 20); // torus to fit for hitch
	glPopMatrix();
	
	glPushMatrix();
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glTranslatef(0.3, 0.3, 0.0);
	glRotatef(-90, 0.0, 1.0, 0.0);
	gluCylinder(quadratic, 0.1f, 0.3f, 4.0f, 10, 20);  // connecting rod
	glPopMatrix();
}

void Car2::drawCar2TrailerCargo()
{
	glPushMatrix(); 
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_SlateBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_SlateBlue);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	
	glColor3f(0.0, 0.498039, 1.0); // SlateBlue
	
	glTranslatef(-10.0, 0.3, 0.0);
	glRotatef(180, 0.0, 1.0, 0.0); 
	int size = calculateIncreasingArc(0.0, 0.0, 1.2, 50, 0, -5);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	glBindTexture (GL_TEXTURE_2D, cargoTexture);	
	glBegin(GL_QUADS);
	for (int i = 0; i < size - 1; ++i) // increasing quads - left
	{
		glTexCoord2d (0, 0);
		glVertex3f(xList[i], 0, 4.0);
		glTexCoord2d (1, 0);
		glVertex3f(xList[i+1], 0, 4.0);
		glTexCoord2d (1, 1);
		glVertex3f(xList[i+1], yList[i+1], 4.0);
		glTexCoord2d (0, 1);
		glVertex3f(xList[i], yList[i], 4.0);
	}
	glEnd();

	glBegin(GL_QUADS);
	for (int i = 0; i < size - 1; ++i) // increasing quads - right
	{
		glTexCoord2d (0, 0);
		glVertex3f(xList[i], 0, -4.0);
		glTexCoord2d (1, 0);
		glVertex3f(xList[i+1], 0, -4.0);
		glTexCoord2d (1, 1);
		glVertex3f(xList[i+1], yList[i+1], -4.0);
		glTexCoord2d (0, 1);
		glVertex3f(xList[i], yList[i], -4.0);
	}
	glEnd();
	
	glBegin(GL_QUADS);
	for (int i = 0; i < size - 1; ++i) // increasing quads - top
	{
		glTexCoord2d (0, 0);
		glVertex3f(xList[i], yList[i], -4.0);
		glTexCoord2d (1, 0);
		glVertex3f(xList[i+1], yList[i+1], -4.0);
		glTexCoord2d (1, 1);
		glVertex3f(xList[i+1], yList[i+1], 4.0);
		glTexCoord2d (0, 1);
		glVertex3f(xList[i], yList[i], 4.0);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glBegin(GL_TRIANGLES);
	glVertex3f(xList[0], yList[0], 4.0);
	glVertex3f(-6.3, -0.3, 0.0);
	glVertex3f(xList[0], yList[0], -4.0); // top triangle part
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(xList[1], yList[1], 4.0);
	glVertex3f(-6.3, 0.3, 0.0);
	glVertex3f(xList[1], yList[1], -4.0); // top triangle part
	glEnd();
	glBegin(GL_QUAD_STRIP);
	glVertex3f(xList[0], yList[0], -4.0);
	glVertex3f(xList[1], yList[1], -4.0);
	glVertex3f(-6.3, 0.3, 0.0);
	glVertex3f(-6.3, -0.3, 0.0);
	glEnd();
	glBegin(GL_QUAD_STRIP);
	glVertex3f(xList[0], yList[0], 4.0);
	glVertex3f(xList[1], yList[1], 4.0);
	glVertex3f(-6.3, 0.3, 0.0);
	glVertex3f(-6.3, -0.3, 0.0);
	glEnd();

	size = calculateDecreasingArc(xList[size-1], yList[size-1], 1.0, 40, 90, 10);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	glBindTexture (GL_TEXTURE_2D, cargoTexture);	
	glBegin(GL_QUADS);
	for (int i = 0; i < size - 1; ++i) // decreasing quads - right
	{
		glTexCoord2d (0, 0);
		glVertex3f(xList[i], 0, 4.0);
		glTexCoord2d (1, 0);
		glVertex3f(xList[i+1], 0, 4.0);
		glTexCoord2d (1, 1);
		glVertex3f(xList[i+1], yList[i+1], 4.0);
		glTexCoord2d (0, 1);
		glVertex3f(xList[i], yList[i], 4.0);
	}
	glEnd();
	
	glBegin(GL_QUADS);
	for (int i = 0; i < size - 1; ++i) // decreasing quads - left
	{
		glTexCoord2d (0, 0);
		glVertex3f(xList[i], 0, -4.0);
		glTexCoord2d (1, 0);
		glVertex3f(xList[i+1], 0, -4.0);
		glTexCoord2d (1, 1);
		glVertex3f(xList[i+1], yList[i+1], -4.0);
		glTexCoord2d (0, 1);
		glVertex3f(xList[i], yList[i], -4.0);
	}
	glEnd();
	
	glBegin(GL_QUADS);
	for (int i = 0; i < size - 1; ++i) // decreasing quads - top
	{
		glTexCoord2d (0, 0);
		glVertex3f(xList[i], yList[i], -4.0);
		glTexCoord2d (1, 0);
		glVertex3f(xList[i+1], yList[i+1], -4.0);
		glTexCoord2d (1, 1);
		glVertex3f(xList[i+1], yList[i+1], 4.0);
		glTexCoord2d (0, 1);
		glVertex3f(xList[i], yList[i], 4.0);
	}
	glEnd();
	
	glBegin(GL_QUADS);
	glTexCoord2d (0, 0);
	glVertex3f(xList[size-1], 0.0, -4.0);
	glTexCoord2d (1, 0);
	glVertex3f(xList[size-1], yList[size-1], -4.0);
	glTexCoord2d (1, 1);
	glVertex3f(xList[size-1], yList[size-1], 4.0);
	glTexCoord2d (0, 1);
	glVertex3f(xList[size-1], 0.0, 4.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, -4.0);
	glVertex3f(0.0, 0.0, 4.0); 
	glVertex3f(xList[size-1], 0.0, 4.0);
	glVertex3f(xList[size-1], 0.0, -4.0); // bottom
	glEnd();
		
	glPopMatrix();
}

void Car2::drawCar2TrailerLeftWheel()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-20.0, 0.0, -5.0);
	glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	glutSolidTorus(0.5, 2.5, 10, 20); // left wheel
	
	glPopMatrix();
	
	drawCar2WheelShaft(-20.0, 0.3, -5.0);
}

void Car2::drawCar2TrailerRightWheel()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-20.0, 0.0, 5.0);
	glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	glutSolidTorus(0.5, 2.5, 10, 20); // right wheel
	
	glPopMatrix();
	
	drawCar2WheelShaft(-20.0, 0.3, 5.0);
}

void Car2::drawCar2TrailerWheelConnectingShaft()
{
	glPushMatrix();
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Black);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);

	glColor3f(0.0, 0.0, 0.0);
	gluQuadricDrawStyle(quadratic, GLU_FILL);
	glTranslatef(-20.0, 0.0, -5.0);
	glRotatef(-wheelRotateAngle * 180 / PI, 0.0, 0.0, 1.0);
	gluCylinder(quadratic, 0.3f, 0.3f, 10.0f, 10, 20); // shaft in center of left wheel
	
	glPopMatrix();
}

void Car2::drawCar2TrailerLeftWheelMudTile()
{
	glPushMatrix();
	glTranslatef(-23.2, 0.6, -5.0);
	drawCar2WheelMudTile();
	glPopMatrix();
}

void Car2::drawCar2TrailerRightWheelMudTile()
{
	glPushMatrix();
	glTranslatef(-23.2, 0.6, 5.0);
	drawCar2WheelMudTile();
	glPopMatrix();
}

int Car2::calculateIncreasingArc(float x, float y, float length, int startAngle, int endAngle, int angleChange)
{
	int endCondition = (startAngle - endAngle) / abs(angleChange) + 1; // calculate array capacity
	xList = new float[endCondition];
	yList = new float[endCondition]; // create array
	xList[0] = x;
	yList[0] = y; // array first value
	int i = 1;
	for (int angle = startAngle; angle >= endAngle; angle = angle + angleChange) // increasing arc values
	{
		x = length * cos(angle * PI/180) + x;
		y = length * sin(angle * PI/180) + y;	
		xList[i] = x;
		yList[i] = y;
		++i;
	}
	return endCondition;
}

int Car2::calculateDecreasingArc(float x, float y, float length, int startAngle, int endAngle, int angleChange)
{
	int endCondition = (endAngle - startAngle) / abs(angleChange) + 1; // calculate array capacity
	xList = new float[endCondition];
	yList = new float[endCondition]; // create array
	xList[0] = x;
	yList[0] = y; // array first value
	int i = 1;
	for (int angle = startAngle; angle <= endAngle; angle = angle + angleChange) // decreasing arc values
	{
		x = length * cos(angle * PI/180) + x;
		y = y - length * sin(angle * PI/180);
		xList[i] = x;
		yList[i] = y;
		++i;
	}
	return endCondition;
}
