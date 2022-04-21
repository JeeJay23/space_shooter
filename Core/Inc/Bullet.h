#pragma once
#include "gameObject.h"

class Bullet :
    public gameObject
{
private:
    const int MAX_TTL = 60 * 5;
    Vector curVelocity;
    int ttl = MAX_TTL;
public:

    Bullet(int x, int y, Vector vel, spriteType type)
        : gameObject(x,y,0,type)
        , curVelocity(vel) 
    {}

    void move();
    bool checkCollision(gameObject**, int);
    void die();
    void onCollisionEnter(gameObject*);
};

