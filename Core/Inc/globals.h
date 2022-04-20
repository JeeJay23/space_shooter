#pragma once


// display settings
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Placeholder stuff
const int PLACEHOLDER_SPR_SIZE = 16;

// Player
const double PLAYER_MOVESPEED = 1.5;
const double PLAYER_MINSPEED = .5;
const double PLAYER_MAXSPEED = 10;
const double PLAYER_GRAVITY = 1;
const double PLAYER_DRAG = 0.8;

// firing
const int PLAYER_FIRE_COOLDOWN = 15; // in 1/60 seconds
const int PLAYER_MAX_BULLETS = 30;

// jetpack
const double PLAYER_MAXFUEL = 100;
const double PLAYER_FUELDRAIN = .5f;

// Bullets
const int BULLET_SPEED = 20;
const int BULLET_TTL = 1; // in seconds
const double BULLET_GRAVITY = .2;
const double BULLET_INITIAL_UPWARDS_MOMENTUM = 5;

// memory
const int MAX_GAMEOBJ_COUNT = 1000;
const int MAX_COLL_OBJ_COUNT = 22;

const int groundColumnsAmount = 4;

const int groundColumns[groundColumnsAmount] = { 
	SCREEN_HEIGHT, 
	SCREEN_HEIGHT-PLACEHOLDER_SPR_SIZE*2, 
	SCREEN_HEIGHT-PLACEHOLDER_SPR_SIZE*4,
	SCREEN_HEIGHT-PLACEHOLDER_SPR_SIZE*8
};
