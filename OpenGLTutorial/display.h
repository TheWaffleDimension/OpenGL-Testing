#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

class Display
{
public:
	Display(int width, int height, const std::string& title);
	virtual ~Display();

	bool isClosed();
	void clear(float r, float g, float b, float a);
	void update();
protected:
private:
	Display(const Display& other) {}
	Display& operator=(const Display& other) {}

	SDL_Window* m_window;
	SDL_GLContext m_glContext;

	bool m_isClosed;

};
