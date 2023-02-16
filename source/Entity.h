#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include <3ds.h>
#include <citro2d.h>

class Entity
{
public:
    Entity(int maxHP, float x, float y, float width, float height, int spriteIndex);
    ~Entity();

    // Getters //
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
    int getHP() const;
    bool isMoving() const;
    int getSprite() const;

    // Setters //
    void gotoX(float x);
    void gotoY(float y);
    void gotoPosition(float x, float y);
    void moveByX(float value);
    void moveByY(float value);
    void moveByVector(float valueX, float valueY);
    void killEntity();
    void takeDamage();
    void shoot();

private:
    // Values that can be used for the gameplay //
    bool m_isAlive;
    int m_hp;
    int m_maxHP;

    // Values related to rendering //
    float m_x;
    float m_y;
    float m_width;
    float m_height;
    int m_spriteIndex;
    bool m_isMoving;
};

#endif