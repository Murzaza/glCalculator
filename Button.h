#ifndef __BUTTON__
#define __BUTTON__

#ifdef __APPLE__
#	include <GLUT/glut.h>
#else
#	include <GL/glut.h>
#endif
#include <iostream>
#include <string>

struct Vector2D
{
	GLfloat x;
	GLfloat y;
};

class Button
{
	public:
	Button();
	Button(std::string t);
	~Button();
	void draw();
	/**Getters**/	
	std::string getText();
	Vector2D getTop();
	Vector2D getBot();
	int getValue();

	/**Setters**/
	void setText(std::string t);
	void setTop(Vector2D t);
	void setBot(Vector2D t);
	void setValue(int v);

	private:
	std::string text;
	Vector2D topR;
	Vector2D botL;
	int value;	
};
#endif
