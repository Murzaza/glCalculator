#include "Button.h"

using namespace std;

Button::Button()
{
}

Button::Button(string t)
{
	text = t;
}

Button::~Button()
{
}

void Button::draw()
{
	glRectf(botL.x, botL.y,
			topR.x, topR.y);
}

string Button::getText()
{
	return text; 
}

Vector2D Button::getTop()
{
	return topR;
}

Vector2D Button::getBot()
{
	return botL;
}

int Button::getValue()
{
	return value;
}

void Button::setText(string t)
{
	text = t;
}

void Button::setTop(Vector2D t)
{
	topR.x = t.x;
	topR.y = t.y;
}

void Button::setBot(Vector2D t)
{
	botL.x = t.x;
	botL.y = t.y;
}

void Button::setValue(int v)
{
	value = v;
}
