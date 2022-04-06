#pragma once

class Controller
{
private:
	void onKeyDown(SDL_KeyboardEvent*);
	void onKeyUp(SDL_KeyboardEvent*);
public:
	int up, down, left, right;
	Controller() : up(0), down(0), left(0), right(0) {};
	void processInput();
};

