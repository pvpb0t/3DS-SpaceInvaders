#ifndef ENEMY_H
#define ENEMY_H

#include "entity.hpp"

class Enemy : public Entity
{
public:
    Enemy();
    Enemy(int maxHP, float x, float y, float width, float height, int spriteIndex);
    virtual ~Enemy();

    
    void move(float dx, float dy);
};

Enemy::Enemy()
    : Entity(0, 0, 0, 0, 0, 0)
{

}

Enemy::Enemy(int maxHP, float x, float y, float width, float height, int spriteIndex)
    : Entity(maxHP, x, y, width, height, spriteIndex)
{

}

Enemy::~Enemy()
{

}

void Enemy::move(float dx, float dy)
{
    moveByX(dx);
    moveByY(dy);
}

#endif
