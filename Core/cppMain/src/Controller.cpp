#include "Controller.h"

void Controller::onKeyDown(SDL_KeyboardEvent* event)
{
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
			up = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			down = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
			left = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			right = 1;
		}
	}	
}

void Controller::onKeyUp(SDL_KeyboardEvent* event)
{
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
			up = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			down = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
			left = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			right = 0;
		}
	}
}

void Controller::processInput()
{
	SDL_Event event{};
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			exit(0);
			break;

		case SDL_KEYDOWN:
			onKeyDown(&event.key);
			break;

		case SDL_KEYUP:
			onKeyUp(&event.key);
			break;

		default:
			break;
		}
	}
}
