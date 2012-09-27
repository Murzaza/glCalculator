#include<GL/glew.h>
#include<iostream>


#ifdef __APPLE__
#	include <GLUT/glut.h>
#else
#	include <GL/glut.h>
#endif

#include "Button.h"
#include <vector>

using namespace std;

void display();
void reshape(int width, int height);
void init();
void mouse(int btn, int state, int x, int y);

Button buttons[21];

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(200, 350);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("GLCalculator");

	init();

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);

	glutMainLoop();
}

//To initialize things
void init()
{
	glEnable(GL_DEPTH_TEST);
	//Create Buttons
	Vector2D bot, top;
	bot.x = -2.0f; bot.y = -2.0f;
	top.x = 0.0f; top.y = 0.0f;
	
	buttons[0].setTop(top);
	buttons[0].setBot(bot);
}

//Rendering function
void display()
{
	glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	glPushMatrix();
	
	//Draw things
	glColor3f(0.0f, 0.0f, 0.0f);
	buttons[0].draw();
	glPopMatrix();
	glutSwapBuffers();
}

//Reshape function 
void reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width <= height)
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat) height / (GLfloat) width, 2.0 * (GLfloat) height / (GLfloat) width, -10.0, 10.0);
	else
		glOrtho(-2.0 * (GLfloat) width / (GLfloat) height, 2.0 * (GLfloat) width / (GLfloat) height, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

//For mouse button things. Just to exit for now.
void mouse(int btn, int state, int x, int y)
{
	if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//Actually do something later.
	}
	if(btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
		//NULL
	}
	if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		exit(1);
	}
}
