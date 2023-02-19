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
private:
    Vector2f m_projectilePosition;
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





#endif
