#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include "entity.hpp"
#include "enemy.hpp"
#include "vector2f.hpp"
#include "constants.hpp"
#include "projectile.hpp"

class Player : public Entity
{
public:
    Player(int maxHP, float x, float y, float width, float height, int spriteIndex);
    virtual ~Player();

    void moveLeft();
    void moveRight();
    Projectile getProjectile();
    void setShooting(bool shooting);
    bool isShooting();
    bool shoot(float x, float y, float width, float height,int tickExisted);
private:
    Projectile m_projectile;
    int lastTickExisted = -1;
    bool m_shooting;
};

Player::Player(int maxHP, float x, float y, float width, float height, int spriteIndex)
    : Entity(maxHP, x, y, width, height, spriteIndex)
{

}

Player::~Player()
{

}

void Player::moveLeft()
{
    moveByX(-5.0f);
}

void Player::moveRight()
{
    moveByX(5.0f);
}

Projectile Player::getProjectile(){
    return m_projectile;
}

void Player::setShooting(bool shooting){
    m_shooting=shooting;
    if(m_shooting){
        m_projectile=Projectile(getX(), getY(), 4.0f, 8.0f);
        m_projectile.setAlive(true);

    }
}

bool Player::isShooting(){
     return m_shooting;
}


bool Player::shoot(float x, float y, float width, float height, int tickExisted){
    if(m_shooting){
        if(m_projectile.isAlive()){
            if(lastTickExisted!=tickExisted){
                lastTickExisted=tickExisted;
                m_projectile.move(-2.5f);

        }
            return(m_projectile.checkCollisions(x, y, width, height));
  
        }else{
            m_shooting=false;
        }
    }
    return false;
}





#endif
