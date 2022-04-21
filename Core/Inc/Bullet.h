#pragma once
#include "gameObject.h"

class Bullet :
    public gameObject
{
private:
    const int MAX_TTL = 60 * BULLET_TTL;
    Vector curVelocity;
    int ttl = MAX_TTL;
    int* playerBulletCount;
    bool isDead = false;
public:
    Bullet(int x, int y, Vector vel, spriteType type, int* pbc)
        : gameObject(x,y,0,type)
        , curVelocity(vel) 
    	, playerBulletCount(pbc)
    {}

    int getColIndex(int input);

    void move();
    bool checkCollision(gameObject**, int);
    void die();
    void onCollisionEnter(gameObject*);
};

