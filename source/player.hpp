#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include "entity.hpp"
#include "vector2f.hpp"

class Player : public Entity
{
public:
    Player(int maxHP, float x, float y, float width, float height, int spriteIndex);
    virtual ~Player();

    void moveLeft();
    void moveRight();
    void shoot(bool& keep, C3D_RenderTarget* top);
    void setProjectile(float x, float y);
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

void Player::setProjectile(float x, float y){
    m_projectilePosition.setX(x);
    m_projectilePosition.setY(y);
}


void Player::shoot(bool& keep, C3D_RenderTarget* top){
    printf("Projectile Y: %f\n", m_projectilePosition.y());
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_SceneBegin(top);
    C2D_DrawRectangle(m_projectilePosition.x(), m_projectilePosition.y(), 0.0f, 10.0f, 20.0f, C2D_Color32(0xFF, 0x00, 0x00, 0xFF), C2D_Color32(0xFF, 0x00, 0x00, 0xFF), C2D_Color32(0xFF, 0x00, 0x00, 0xFF), C2D_Color32(0xFF, 0x00, 0x00, 0xFF));
    C3D_FrameEnd(0);
    m_projectilePosition.setY(m_projectilePosition.y() - 4.0f);

    if(m_projectilePosition.y() < 0.0f){
        keep=false;
    }
}

#endif
