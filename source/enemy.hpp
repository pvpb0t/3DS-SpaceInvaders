#ifndef ENEMY_H
#define ENEMY_H

#pragma once


#include "entity.hpp"
#include "vector2f.hpp"
#include "constants.hpp"
#include "projectile.hpp"

class Player; // forward declaration

class Enemy : public Entity
{
public:
    Enemy();
    Enemy(int maxHP, float x, float y, float width, float height, int spriteIndex);
    virtual ~Enemy();

    void move(float dx, float dy);
    Projectile getProjectile();
    void setShooting(bool shooting);
    bool isShooting();
    void shoot(float x, float y, float width, float height);

private:
    Projectile m_projectile;
    bool m_shooting;

};

Enemy::Enemy()
    : Entity(0, 0, 0, 0, 0, 0)
{

}

Enemy::Enemy(int maxHP, float x, float y, float width, float height, int spriteIndex)
    : Entity(maxHP, x, y, width, height, spriteIndex)
    , m_shooting(false)
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


Projectile Enemy::getProjectile(){
    return m_projectile;
}

void Enemy::setShooting(bool shooting){
    m_shooting=shooting;
    if(m_shooting){
        m_projectile=Projectile(getX(), getY(), 4.0f, 10.0f);
        m_projectile.setAlive(true);

    }
}

bool Enemy::isShooting(){
     return m_shooting;
}


void Enemy::shoot(float x, float y, float width, float height){
    if(m_shooting){
        if(m_projectile.isAlive()){
            m_projectile.move(+3.0f);
            m_projectile.checkCollisions(x, y, width, height);
        }else{
            m_shooting=false;
        }
    }
}

#endif
