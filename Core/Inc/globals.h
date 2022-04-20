#pragma once

// display settings
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int FRONT_PORCH = 143;
const int VERT_PORCH = 30;

// Placeholder stuff
const int PLACEHOLDER_SPR_SIZE = 32;

// Player
const double PLAYER_MOVESPEED = 1.5;
const double PLAYER_MINSPEED = .5;
const double PLAYER_MAXSPEED = 10;
const double PLAYER_GRAVITY = 1;
const double PLAYER_DRAG = 0.8;
const int PLAYER_RADIUS = 32;

// firing
const int PLAYER_FIRE_COOLDOWN = 15; // in 1/60 seconds
const int PLAYER_MAX_BULLETS = 10;

// jetpack
const double PLAYER_MAXFUEL = 100;
const double PLAYER_FUELDRAIN = .5f;

// Bullets
const int BULLET_SPEED = 15;
const int BULLET_TTL = 1; // in seconds
const double BULLET_GRAVITY = .2;
const double BULLET_INITIAL_UPWARDS_MOMENTUM = 5;

// memory
const int MAX_GAMEOBJ_COUNT = 80;
const int MAX_TOADD_COUNT = 10;
const int MAX_COLL_OBJ_COUNT = 22;

//gemeObjects enum
enum spriteType {	sprBlock = 0,
						sprPlayer1 = 1,
						sprPlayer2 = 2,
						sprBullet = 3
					};
