#include "Car3.h"
#include <GL/glut.h>

Car3::Car3(int shaftTexture, int pipeTexture, int cargoTexture)
{
	length = 11; // half
	width = 3.5; // half

	this->shaftTexture = shaftTexture;
	this->pipeTexture = pipeTexture;
	this->cargoTexture = cargoTexture;

	quadratic = gluNewQuadric();

	rotate_trailer_wheel= 0;
	rotate_moto_wheel = 0;
	rotate_moto_wheel_speed = 3;
	rotate_trailer_wheel_speed = 5;
}


Car3::~Car3(void)
{}

void Car3::drawCar()
{
	drawCar3();
}

void Car3::drawTrailer()
{
	drawCar3TrailerAndHitch();
}

void Car3::drawCar3()
{
	GLfloat wheel_color[] = {0.5, 0.35, 0.05,1};
	GLfloat shaft_color[] = {0.25, 0.25, 0.3,1};
	GLfloat engine_color[] = {1, 0, 0,1};
	GLfloat foot_color[] = {1, 0, 0,1};
	GLfloat gas_color[] = {1, 0, 0,1};
	GLfloat seat_color[] = {1, 0, 0,1};
	GLfloat handle_color[] = {0.55, 0.55, 0.6,1};
	GLfloat hand_color[] = {0.0, 0.6, 0.6, 1};
	GLfloat lrs_color[] = {0.55, 0.55, 0.6, 1};
	GLfloat pipe_color[] = {0.75,0.75,0.7,1};
	GLfloat shininess[] = {5};

	GLfloat white_color[] = {1,1,1,1};
	GLfloat blue_color[] = {0,0,1,1};

	GLfloat white_circle_ambient[] = {1, 1, 1};
	GLfloat white_circle_diffuse[] = {1, 1, 1};

	GLfloat blue_field_ambient[] = {0, 0, 1};
	GLfloat blue_field_diffuse[] = {0, 0, 1};

	GLfloat slate_ambient[] = {0.02, 0.02, 0.02};
	GLfloat slate_diffuse[] = {0.02, 0.01, 0.01};
	GLfloat slate_specular[] = {0.4, 0.4, 0.4};
	GLfloat slate_shininess[] = {.78125};

	GLfloat matEmission[] = {1.0, 1.0, 0, 1.0};
	GLfloat noEmission[] = {0.0, 0.0, 0.0, 1.0};

	//===============================================================================shaft-in the center of the front wheel
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, shaft_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, shaft_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, shaft_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
    glColor3f(0.25, 0.25, 0.3);
	glPushMatrix();
		glTranslatef(9.0, 0.0, -1.0);
			gluQuadricDrawStyle(quadratic, GLU_FILL);
			gluCylinder(quadratic,0.25,0.25,2.0,30,30); 
   glPopMatrix(); 
  
   //===============================================================================front wheel
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wheel_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  wheel_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, wheel_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
    glColor3f(0.5, 0.35, 0.05);
   
    if( getSpeed() > 0)
    {
	   rotate_moto_wheel -= rotate_moto_wheel_speed + getSpeed();	
    }
    if(rotate_moto_wheel <= -360)	rotate_moto_wheel += 360;

    glPushMatrix();
   glTranslatef(9.0, 0.0, 0.0);
   glRotatef(rotate_moto_wheel, 0.0, 0.0, 1.0);
			glutSolidTorus(0.5, 2.0, 10, 20);  
       glPushMatrix();
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
		glPopMatrix();
	   glPushMatrix();
			glRotatef(-90,0.0,1.0,0.0);
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
		glPopMatrix();
		glPushMatrix();
			glRotatef(45,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0);
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
		glPopMatrix();
	   glPushMatrix();
			glRotatef(135,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
		glPopMatrix();
		glPushMatrix();
			glRotatef(225,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
		glPopMatrix();
		glPushMatrix();
			glRotatef(315,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
		glPopMatrix();
	   glPushMatrix();
			glRotatef(90,1.0,0.0,0.0); 
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
		glPopMatrix();
	   glPushMatrix();
			glRotatef(-90,1.0,0.0,0.0); 
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
	   glPopMatrix();
	glPopMatrix();

	//===============================================================================rear wheel
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wheel_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  wheel_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, wheel_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
  
	glPushMatrix();
    glRotatef(rotate_moto_wheel, 0.0, 0.0, 1.0);
			glutSolidTorus(0.5, 2.0, 10, 20);  
       glPushMatrix();
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
		glPopMatrix();
	   glPushMatrix();
			glRotatef(-90,0.0,1.0,0.0);
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
		glPopMatrix();
		glPushMatrix();
			glRotatef(45,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0);
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
		glPopMatrix();
	   glPushMatrix();
			glRotatef(135,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
		glPopMatrix();
		glPushMatrix();
			glRotatef(225,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
		glPopMatrix();
		glPushMatrix();
			glRotatef(315,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
		glPopMatrix();
	    glPushMatrix();
			glRotatef(90,0.0,0.0,1.0); 
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
		glPopMatrix();
	    glPushMatrix();
			glRotatef(-90,0.0,0.0,1.0); 
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.1,0.1,1.5,10,10);
	   glPopMatrix();  
	glPopMatrix();
   
   //===============================================================================engine
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, engine_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, engine_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, engine_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
   glColor3f(1, 0, 0);  
   glPushMatrix();
   glBegin(GL_QUADS);
		glVertex3f( 3.5,0.5,1 );//b //front
		glVertex3f( 3.5,-1.5,1 );//a
		glVertex3f( 6.5,-1.5,1);//d
		glVertex3f( 6.5,0.5,1);//c
		glVertex3f( 3.5,-1.5,1);//a//bottom
		glVertex3f(  6.5,-1.5,1);//d
		glVertex3f( 6.5,-1.5,-1);//d'
		glVertex3f( 3.5,-1.5,-1);//a'
		glVertex3f( 3.5,-1.5,-1);//a'//rear
		glVertex3f( 6.5,-1.5,-1);//d'
		glVertex3f( 6.5,0.5,-1);//c'
		glVertex3f( 3.5,0.5,-1);//b'
		glVertex3f(3.5,0.5,1 );//b//top
		glVertex3f( 6.5,0.5,1);//c
		glVertex3f( 6.5,0.5,-1);//c'
		glVertex3f( 3.5,0.5,-1);//b'
		glVertex3f(  6.5,-1.5,1);//d//right
		glVertex3f( 6.5,-1.5,-1);//d'
		glVertex3f( 6.5,0.5,-1);//c'
		glVertex3f( 6.5,0.5,1);//c
		glVertex3f( 3.5,-1.5,1);//a//left
		glVertex3f( 3.5,-1.5,-1);//a'
		glVertex3f( 3.5,0.5,-1);//b'
		glVertex3f( 3.5,0.5,1);//b
	glEnd();
	glPopMatrix(); 
	
   //===============================================================================where to put feet
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  foot_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, foot_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, foot_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
   glColor3f(1, 0, 0);
   glPushMatrix();
   glBegin(GL_QUADS);
		glVertex3f( 2.5, -1, 2);//b //front
		glVertex3f( 2.5,-1.5, 2);//a
		glVertex3f( 3.5, -1.5, 2);//d
		glVertex3f( 3.5,-1, 2);//c
		glVertex3f( 2.5,-1.5, 2);//a//bottom
		glVertex3f( 3.5, -1.5, 2);//d
		glVertex3f( 3.5,-1.5, -2);//d'
		glVertex3f( 2.5,-1.5, -2);//a'
		glVertex3f( 2.5,-1.5, -2);//a'//rear
		glVertex3f( 3.5,-1.5, -2);//d'
		glVertex3f( 3.5,-1, -2);//c'
		glVertex3f( 2.5,-1, -2);//b'
		glVertex3f( 2.5, -1, 2);//b//top
		glVertex3f( 3.5,-1, 2);//c
		glVertex3f( 3.5,-1, -2);//c'
		glVertex3f( 2.5,-1, -2);//b'
		glVertex3f( 3.5, -1.5, 2);//d//right
		glVertex3f( 3.5,-1.5, -2);//d'
		glVertex3f( 3.5,-1, -2);//c'
		glVertex3f( 3.5,-1, 2);//c
		glVertex3f( 2.5,-1.5, 2);//a//left
		glVertex3f( 2.5,-1.5, -2);//a'
		glVertex3f( 2.5,-1, -2);//b'
		glVertex3f( 2.5, -1, 2);//b
   glEnd();
   glPopMatrix(); 


   
   //===============================================================================gas tank
		GLfloat mat1_specular[] = {1.0, 0.0, 0.0, 1.0};
		GLfloat mat1_ambient[] = {1.0, 0.0, 0.0, 1.0};
		GLfloat mat1_diffuse[] = {1.0, 0.0, 0.0, 1.0};
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat1_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, 100.0f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat1_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat1_diffuse);
		
    glColor3f(01, 0, 0);
   glPushMatrix();
   glBegin(GL_TRIANGLE_STRIP);//curve top
		glVertex3f(5.5+cos((PI/180.0) * 0),0.5+sin((PI/180.0) * 0),1);
		glVertex3f(5.5+cos((PI/180.0) * 0),0.5+sin((PI/180.0) * 0),-1);
		glVertex3f(5.5+cos((PI/180.0) * 10),0.5+sin((PI/180.0) * 10),1);
		glVertex3f(5.5+cos((PI/180.0) * 10),0.5+sin((PI/180.0) * 10),-1);
		glVertex3f(5.5+cos((PI/180.0) * 20),0.5+sin((PI/180.0) * 20),1);
		glVertex3f(5.5+cos((PI/180.0) * 20),0.5+sin((PI/180.0) * 20),-1);
		glVertex3f(5.5+cos((PI/180.0) * 30),0.5+sin((PI/180.0) * 30),1);
		glVertex3f(5.5+cos((PI/180.0) * 30),0.5+sin((PI/180.0) * 30),-1);
		glVertex3f(5.5+cos((PI/180.0) * 40),0.5+sin((PI/180.0) * 40),1);
		glVertex3f(5.5+cos((PI/180.0) * 40),0.5+sin((PI/180.0) * 40),-1);
		glVertex3f(5.5+cos((PI/180.0) * 50),0.5+sin((PI/180.0) * 50),1);
		glVertex3f(5.5+cos((PI/180.0) * 50),0.5+sin((PI/180.0) * 50),-1);
		glVertex3f(5.5+cos((PI/180.0) * 60),0.5+sin((PI/180.0) * 60),1);
		glVertex3f(5.5+cos((PI/180.0) * 60),0.5+sin((PI/180.0) * 60),-1);
		glVertex3f(5.5+cos((PI/180.0) * 70),0.5+sin((PI/180.0) * 70),1);
		glVertex3f(5.5+cos((PI/180.0) * 70),0.5+sin((PI/180.0) * 70),-1);
		glVertex3f(5.5+cos((PI/180.0) * 80),0.5+sin((PI/180.0) * 80),1);
		glVertex3f(5.5+cos((PI/180.0) * 80),0.5+sin((PI/180.0) * 80),-1);
		glVertex3f(5.5+cos((PI/180.0) * 90),0.5+sin((PI/180.0) * 90),1);
		glVertex3f(5.5+cos((PI/180.0) * 90),0.5+sin((PI/180.0) * 90),-1);  
   glEnd();
   glPopMatrix(); 
   glPushMatrix();
   glBegin(GL_POLYGON);//front curve
		glVertex3f(5.5,0.5,1);
		glVertex3f(5.5+cos((PI/180.0) * 0),0.5+sin((PI/180.0) * 0),1);
		glVertex3f(5.5+cos((PI/180.0) * 10),0.5+sin((PI/180.0) * 10),1);
		glVertex3f(5.5+cos((PI/180.0) * 20),0.5+sin((PI/180.0) * 20),1);
		glVertex3f(5.5+cos((PI/180.0) * 30),0.5+sin((PI/180.0) * 30),1);
		glVertex3f(5.5+cos((PI/180.0) * 40),0.5+sin((PI/180.0) * 40),1);
		glVertex3f(5.5+cos((PI/180.0) * 50),0.5+sin((PI/180.0) * 50),1);
		glVertex3f(5.5+cos((PI/180.0) * 60),0.5+sin((PI/180.0) * 60),1);
		glVertex3f(5.5+cos((PI/180.0) * 70),0.5+sin((PI/180.0) * 70),1);
		glVertex3f(5.5+cos((PI/180.0) * 80),0.5+sin((PI/180.0) * 80),1);
		glVertex3f(5.5+cos((PI/180.0) * 90),0.5+sin((PI/180.0) * 90),1);
   glEnd();
   glPopMatrix(); 
   glPushMatrix();
   glBegin(GL_POLYGON);//back curve
		glVertex3f(5.5,0.5,-1);
		glVertex3f(5.5+cos((PI/180.0) * 0),0.5+sin((PI/180.0) * 0),-1);
		glVertex3f(5.5+cos((PI/180.0) * 10),0.5+sin((PI/180.0) * 10),-1);
		glVertex3f(5.5+cos((PI/180.0) * 20),0.5+sin((PI/180.0) * 20),-1);
		glVertex3f(5.5+cos((PI/180.0) * 30),0.5+sin((PI/180.0) * 30),-1);
		glVertex3f(5.5+cos((PI/180.0) * 40),0.5+sin((PI/180.0) * 40),-1);
		glVertex3f(5.5+cos((PI/180.0) * 50),0.5+sin((PI/180.0) * 50),-1);
		glVertex3f(5.5+cos((PI/180.0) * 60),0.5+sin((PI/180.0) * 60),-1);
		glVertex3f(5.5+cos((PI/180.0) * 70),0.5+sin((PI/180.0) * 70),-1);
		glVertex3f(5.5+cos((PI/180.0) * 80),0.5+sin((PI/180.0) * 80),-1);
		glVertex3f(5.5+cos((PI/180.0) * 90),0.5+sin((PI/180.0) * 90),-1); 
   glEnd();
   glPopMatrix(); 
   glPushMatrix();
   glBegin(GL_TRIANGLES);//front triangle
		glVertex3f(3.5,0.5,1);
		glVertex3f(5.5,0.5,1);
		glVertex3f(5.5,1.5,1);
   glEnd();
   glPopMatrix(); 
   glPushMatrix();
   glBegin(GL_TRIANGLES);//back triangle
		glVertex3f(3.5,0.5,-1);
		glVertex3f(5.5,0.5,-1);
		glVertex3f(5.5,1.5,-1);
   glEnd();
   glPopMatrix(); 
   glPushMatrix();
   glBegin(GL_QUADS);//triangle top
		glVertex3f(3.5,0.5,1);
		glVertex3f(3.5,0.5,-1);
		glVertex3f(5.5,1.5,-1);
		glVertex3f(5.5,1.5,1);
   glEnd();
   glPopMatrix(); 




  
   //===============================================================================front light
    glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matEmission);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matEmission);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matEmission);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEmission);
   glColor3f(1.0, 1.0, 0);
   glPushMatrix();
		glTranslatef(7.5, 3.71, 0.0);
		glRotatef(-90,0.0,1.0,0.0);
			glutSolidCone(0.5, 0.5, 10, 10);
   glPopMatrix();
   glPopMatrix();


   //===============================================================================seat
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, seat_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, seat_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, seat_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
   glColor3f(1, 0, 0);  
   glPushMatrix();
   glBegin(GL_POLYGON);
		glVertex3f(3.5,0.5,1);
		glVertex3f(3,1.25,1);
		glVertex3f(2.5*cos((PI/180.0) *45),2.5*sin((PI/180.0) *45),1);
		glVertex3f(2.5*cos((PI/180.0) * 60),2.5*sin((PI/180.0) * 60),1);
		glVertex3f(2.5*cos((PI/180.0) * 75),2.5*sin((PI/180.0) * 75),1);
		glVertex3f(0,2.5,1);
		glVertex3f(-1,2.5,1);
		glVertex3f(-1,3.5,1);
		glVertex3f(0,3.5,1);
		glVertex3f(3.5*cos((PI/180.0) * 75),3.5*sin((PI/180.0) * 75),1);
		glVertex3f(3.5*cos((PI/180.0) * 60),3.5*sin((PI/180.0) *60),1);
		glVertex3f(3.5*cos((PI/180.0) * 45),3.5*sin((PI/180.0) *45),1);
		glVertex3f(3.5*cos((PI/180.0) * 30),3.5*sin((PI/180.0) *30),1);
		glVertex3f(3.5*cos((PI/180.0) * 25),3.5*sin((PI/180.0) *25),1);
   glEnd();
   glPopMatrix();
   glPushMatrix();
   glBegin(GL_POLYGON);
		glVertex3f(3.5,0.5,-1);
		glVertex3f(3,1.25,-1);
		glVertex3f(2.5*cos((PI/180.0) *45),2.5*sin((PI/180.0) *45),-1);
		glVertex3f(2.5*cos((PI/180.0) * 60),2.5*sin((PI/180.0) * 60),-1);
		glVertex3f(2.5*cos((PI/180.0) * 75),2.5*sin((PI/180.0) * 75),-1);
		glVertex3f(0,2.5,-1);
		glVertex3f(-1,2.5,-1);
		glVertex3f(-1,3.5,-1);
		glVertex3f(0,3.5,-1);
		glVertex3f(3.5*cos((PI/180.0) * 75),3.5*sin((PI/180.0) * 75),-1);
		glVertex3f(3.5*cos((PI/180.0) * 60),3.5*sin((PI/180.0) *60),-1);
		glVertex3f(3.5*cos((PI/180.0) * 45),3.5*sin((PI/180.0) *45),-1);
		glVertex3f(3.5*cos((PI/180.0) * 30),3.5*sin((PI/180.0) *30),-1);
		glVertex3f(3.5*cos((PI/180.0) * 25),3.5*sin((PI/180.0) *25),-1);
   glEnd();
   glPopMatrix();
   glPushMatrix();
   glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(3.5,0.5,1);
		glVertex3f(3.5,0.5,-1);
		glVertex3f(3,1.25,1);
		glVertex3f(3,1.25,-1);
		glVertex3f(2.5*cos((PI/180.0) *45),2.5*sin((PI/180.0) *45),1);
		glVertex3f(2.5*cos((PI/180.0) *45),2.5*sin((PI/180.0) *45),-1);
		glVertex3f(2.5*cos((PI/180.0) * 60),2.5*sin((PI/180.0) * 60),1);
		glVertex3f(2.5*cos((PI/180.0) * 60),2.5*sin((PI/180.0) * 60),-1);
		glVertex3f(2.5*cos((PI/180.0) * 75),2.5*sin((PI/180.0) * 75),1);
		glVertex3f(2.5*cos((PI/180.0) * 75),2.5*sin((PI/180.0) * 75),-1);
		glVertex3f(0,2.5,1);
		glVertex3f(0,2.5,-1);
		glVertex3f(-1,2.5,1);
		glVertex3f(-1,2.5,-1);
		glVertex3f(-1,3.5,1);
		glVertex3f(-1,3.5,-1);
		glVertex3f(0,3.5,1);
		glVertex3f(0,3.5,-1);
		glVertex3f(3.5*cos((PI/180.0) * 75),3.5*sin((PI/180.0) *75),1);
		glVertex3f(3.5*cos((PI/180.0) * 75),3.5*sin((PI/180.0) *75),-1);
		glVertex3f(3.5*cos((PI/180.0) * 60),3.5*sin((PI/180.0) *60),1);
		glVertex3f(3.5*cos((PI/180.0) * 60),3.5*sin((PI/180.0) *60),-1);
		glVertex3f(3.5*cos((PI/180.0) * 45),3.5*sin((PI/180.0) *45),1);
		glVertex3f(3.5*cos((PI/180.0) * 45),3.5*sin((PI/180.0) *45),-1);
		glVertex3f(3.5*cos((PI/180.0) * 30),3.5*sin((PI/180.0) *30),1);
		glVertex3f(3.5*cos((PI/180.0) * 30),3.5*sin((PI/180.0) *30),-1);
		glVertex3f(3.5*cos((PI/180.0) * 25),3.5*sin((PI/180.0) *25),1);
		glVertex3f(3.5*cos((PI/180.0) * 25),3.5*sin((PI/180.0) *25),-1);
   glEnd();
   glPopMatrix();
    
   //===============================================================================rear light
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,matEmission);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matEmission);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matEmission);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matEmission);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
   glColor3f(1.0, 1.0, 0);
   glPushMatrix();
		glTranslatef(-1.5, 3.0, 0.0);
		glRotatef(90,0.0,1.0,0.0);
			glutSolidCone(0.5, 0.5, 10, 10);
   glPopMatrix();

   //===============================================================================handle - ºá¸Ë
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, handle_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, handle_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, handle_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
   glColor3f(0.55, 0.55, 0.6);
	glPushMatrix();
		glTranslatef(7.0, 3.464,-2.5);
			glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
			gluQuadricDrawStyle(quadratic, GLU_FILL);
			gluQuadricNormals (quadratic, GLU_SMOOTH);
			gluQuadricTexture (quadratic, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, shaftTexture);
			gluCylinder(quadratic,0.25,0.25,5.0,10,10); 
			glDisable(GL_TEXTURE_2D);
   glPopMatrix();

   //===============================================================================handle bar - left
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hand_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, hand_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, hand_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
    glColor3f(0.0, 0.6, 0.6);
	glPushMatrix();
		glTranslatef(7.0, 3.464,-2.5);
		glRotatef(-150,0.0,1.0,0.0);
			gluQuadricDrawStyle(quadratic, GLU_FILL);
			gluCylinder(quadratic,0.25,0.35,0.8,10,10);  
   glPopMatrix();
   //===============================================================================handle bar - right
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, hand_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, hand_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, hand_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
   glColor3f(0.0, 0.6, 0.6);
	glPushMatrix();
		glTranslatef(7.0, 3.464,2.5);
		glRotatef(-30,0.0,1.0,0.0);
			gluQuadricDrawStyle(quadratic, GLU_FILL);
			gluCylinder(quadratic,0.25,0.35,0.8,10,10);  
   glPopMatrix();

   //===============================================================================left shaft
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, lrs_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lrs_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, lrs_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
   glColor3f(0.55, 0.55, 0.6);
	glPushMatrix();
		glTranslatef(9.0, 0.0,-1.0);
		glRotatef(30,0.0,0.0,1.0);
		glRotatef(-90,1.0,0.0,0.0);
			glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
			gluQuadricDrawStyle(quadratic, GLU_FILL);
			gluQuadricNormals (quadratic, GLU_SMOOTH);
			gluQuadricTexture (quadratic, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, shaftTexture);
			gluCylinder(quadratic,0.25,0.25,4.0,10,10);  
			glDisable(GL_TEXTURE_2D);
   glPopMatrix();
   //===============================================================================right shate
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, lrs_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lrs_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, lrs_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
   glColor3f(0.55, 0.55, 0.6);
	glPushMatrix();
		glTranslatef(9.0, 0.0,1.0);
		glRotatef(30,0.0,0.0,1.0);
		glRotatef(-90,1.0,0.0,0.0);
			glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
			gluQuadricDrawStyle(quadratic, GLU_FILL);
			gluQuadricNormals (quadratic, GLU_SMOOTH);
			gluQuadricTexture (quadratic, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, shaftTexture);
			gluCylinder(quadratic,0.25,0.25,4.0,10,10);  
			glDisable(GL_TEXTURE_2D);
   glPopMatrix();


   //===============================================================================exhaust pipe
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, pipe_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, pipe_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, pipe_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
   glColor3f(0.75, 0.75, 0.7); 
	glPushMatrix();
		glTranslatef(3.5, 0.0,0.8);
		glRotatef(-90,0.0,1.0,0.0);
			glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
			gluQuadricDrawStyle(quadratic, GLU_FILL);
			gluQuadricNormals (quadratic, GLU_SMOOTH);
			gluQuadricTexture (quadratic, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, pipeTexture);
			gluCylinder(quadratic,0.25,0.35,5.0,10,10);  
			glDisable(GL_TEXTURE_2D);
   glPopMatrix();
}

void Car3::drawCar3TrailerAndHitch()
{
	GLfloat noEmission[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat wheel_color[] = {0.5, 0.35, 0.05,1};
	GLfloat shininess[] = {5};
	GLfloat hitch_color[] = {0, 0, 0,1};
	GLfloat cargo_color[] = {1, 0, 0,1};

   //===============================================================================trailer hitch-connection of trailer and motor
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,hitch_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, hitch_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, hitch_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
	glColor3f(0, 0, 0);
	glPushMatrix();
		glTranslatef(-2, 1.0,0.0);
		glRotatef( 45,0.0,0.0,1.0);
		glRotatef(-90,0.0,1.0,0.0);
			gluCylinder(quadratic,0.1,0.1,2.5,10,10);
    glPopMatrix();


   //===============================================================================wheels of trailer - left 
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wheel_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  wheel_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, wheel_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
    glColor3f(0.5, 0.35, 0.05);

	if( getSpeed() > 0)
    {
	   rotate_trailer_wheel -= rotate_trailer_wheel_speed + getSpeed();	
    }
    if(rotate_trailer_wheel <= -360)	rotate_trailer_wheel += 360;

    glPushMatrix();
	glTranslatef(-9.0,-0.5,-2.5);
    glRotatef(rotate_trailer_wheel, 0.0, 0.0, 1.0);
			glutSolidTorus(0.5, 1.5, 10, 20);  
       glPushMatrix();
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.04,0.04,1,10,10);
		glPopMatrix();
	   glPushMatrix();
			glRotatef(-90,0.0,1.0,0.0);
				gluCylinder(quadratic,0.04,0.04,1,10,10);
		glPopMatrix();
		glPushMatrix();
			glRotatef(45,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0);
				gluCylinder(quadratic,0.04,0.04,1,10,10);
		glPopMatrix();
	   glPushMatrix();
			glRotatef(135,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.04,0.04,1,10,10);
		glPopMatrix();
		glPushMatrix();
			glRotatef(225,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.04,0.04,1,10,10);
		glPopMatrix();
		glPushMatrix();
			glRotatef(315,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.04,0.04,1,10,10);
		glPopMatrix();
	   glPushMatrix();
			glRotatef(90,1.0,0.0,0.0); 
				gluCylinder(quadratic,0.04,0.04,1,10,10);
		glPopMatrix();
	   glPushMatrix();
			glRotatef(-90,1.0,0.0,0.0); 
				gluCylinder(quadratic,0.04,0.04,1,10,10);
	   glPopMatrix();
	glPopMatrix();


   //===============================================================================cargo area
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cargo_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cargo_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cargo_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
    glColor3f(1, 0, 0);
	glPushMatrix();
    glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	glBindTexture(GL_TEXTURE_2D, cargoTexture);
    glBegin(GL_QUADS);
		glVertex3f( -11, 1.5, 2);//b //front
		glVertex3f( -11,-1.5,2);//a
		glVertex3f( -4,-1.5,2);//d
		glVertex3f( -4,1,2);//c
		glVertex3f( -11,-1.5,2);//a//bottom
		glVertex3f( -4,-1.5,2);//d
		glVertex3f( -4,-1.5,-2);//d'
		glVertex3f( -11,-1.5,-2);//a'
		glVertex3f( -11,-1.5,-2);//a'//rear
		glVertex3f( -4,-1.5,-2);//d'
		glVertex3f( -4,1,-2);//c'
		glVertex3f( -11, 1.5, -2);//b'
		glTexCoord2d (0, 0);
		glVertex3f( -11, 1.5, 2);//b//top
		glTexCoord2d (1, 0);
		glVertex3f( -4,1,2);//c
		glTexCoord2d (1, 1);
		glVertex3f( -4,1,-2);//c'
		glTexCoord2d (0, 1);
		glVertex3f( -11, 1.5, -2);//b'
		glVertex3f( -4,-1.5,2);//d//right
		glVertex3f( -4,-1.5,-2);//d'
		glVertex3f( -4,1,-2);//c'
		glVertex3f( -4,1,2);//c
		glTexCoord2d (1, 0);
		glVertex3f( -11,-1.5,2);//a//left
		glTexCoord2d (0, 0);
		glVertex3f( -11,-1.5,-2);//a'
		glTexCoord2d (0, 1);
		glVertex3f( -11, 1.5, -2);//b'
		glTexCoord2d (1, 1);
		glVertex3f( -11, 1.5, 2);//b
    glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

    //===============================================================================wheels of trailer - right
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wheel_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  wheel_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, wheel_color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);

    glColor3f(0.5, 0.35, 0.05);

	glPushMatrix();
	glTranslatef(-9.0,-0.5,2.5);
    glRotatef(rotate_trailer_wheel, 0.0, 0.0, 1.0);
			glutSolidTorus(0.5, 1.5, 10, 20);  
       glPushMatrix();
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.04,0.04,1,10,10);
		glPopMatrix();
	   glPushMatrix();
			glRotatef(-90,0.0,1.0,0.0);
				gluCylinder(quadratic,0.04,0.04,1,10,10);
		glPopMatrix();
		glPushMatrix();
			glRotatef(45,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0);
				gluCylinder(quadratic,0.04,0.04,1,10,10);
		glPopMatrix();
	   glPushMatrix();
			glRotatef(135,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.04,0.04,1,10,10);
		glPopMatrix();
		glPushMatrix();
			glRotatef(225,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.04,0.04,1,10,10);
		glPopMatrix();
		glPushMatrix();
			glRotatef(315,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0); 
				gluCylinder(quadratic,0.04,0.04,1,10,10);
		glPopMatrix();
	   glPushMatrix();
			glRotatef(90,1.0,0.0,0.0); 
				gluCylinder(quadratic,0.04,0.04,1,10,10);
		glPopMatrix();
	   glPushMatrix();
			glRotatef(-90,1.0,0.0,0.0); 
				gluCylinder(quadratic,0.04,0.04,1,10,10);
	   glPopMatrix();
	glPopMatrix();
}