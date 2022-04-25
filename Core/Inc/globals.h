#pragma once


// display settings
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int FRONT_PORCH = 143;
const int VERT_PORCH = 30;

// Placeholder stuff
const int PLACEHOLDER_SPR_SIZE = 32;
const int PLACEHOLDER_SPR_SIZE_HALF = PLACEHOLDER_SPR_SIZE / 2;

// Player
const double PLAYER_MOVESPEED = 1.5;
const double PLAYER_MINSPEED = .5;
const double PLAYER_MAXSPEED = 5;
const double PLAYER_GRAVITY = 1;
const double PLAYER_DRAG = 0.95;
const int PLAYER_RADIUS = 32;
const int PLAYER1_RESPAWNX= 100;
const int PLAYER2_RESPAWNX= 600;
const int PLAYER_RESPAWNY= 100;
const int PLAYER_RESPAWN = 60 * 1;

// firing
const int PLAYER_FIRE_COOLDOWN = 15; // in 1/60 seconds
const int PLAYER_MAX_BULLETS = 4;

// jetpack
const double PLAYER_MAXFUEL = 100;
const double PLAYER_FUELDRAIN = .5f;

// Bullets
const int BULLET_SPEED = 20;
const int BULLET_TTL = 10; // in seconds
const double BULLET_GRAVITY = .2;
const double BULLET_INITIAL_UPWARDS_MOMENTUM = 5;

// memory
const int MAX_GAMEOBJ_COUNT = 1000;
const int MAX_COLL_OBJ_COUNT = 22;
const int MAX_TOADD_COUNT = 20;

const int groundColumnsAmount = 20;
const int BLOCK_SIZE = 16;

const int groundColumns[groundColumnsAmount] = { 
	SCREEN_HEIGHT-BLOCK_SIZE*2,
	SCREEN_HEIGHT-BLOCK_SIZE*3,
	SCREEN_HEIGHT-BLOCK_SIZE*4,
	SCREEN_HEIGHT-BLOCK_SIZE*6,
	SCREEN_HEIGHT-BLOCK_SIZE*7,
	SCREEN_HEIGHT-BLOCK_SIZE*5,
	SCREEN_HEIGHT-BLOCK_SIZE*3,
	SCREEN_HEIGHT-BLOCK_SIZE*3,
	SCREEN_HEIGHT-BLOCK_SIZE*6,
	SCREEN_HEIGHT-BLOCK_SIZE*10,
	SCREEN_HEIGHT-BLOCK_SIZE*12,
	SCREEN_HEIGHT-BLOCK_SIZE*10,
	SCREEN_HEIGHT-BLOCK_SIZE*9,
	SCREEN_HEIGHT-BLOCK_SIZE*6,
	SCREEN_HEIGHT-BLOCK_SIZE*4,
	SCREEN_HEIGHT-BLOCK_SIZE*5,
	SCREEN_HEIGHT-BLOCK_SIZE*2,
	SCREEN_HEIGHT-BLOCK_SIZE*4,
	SCREEN_HEIGHT-BLOCK_SIZE*3,
	SCREEN_HEIGHT-BLOCK_SIZE*2,
};

enum spriteType {	sprBlock = 0,
						sprPlayer1 = 1,
						sprPlayer2 = 2,
						sprBullet = 3
					};
