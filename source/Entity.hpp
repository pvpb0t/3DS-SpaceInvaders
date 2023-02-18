#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include <3ds.h>
#include <citro2d.h>

class Entity
{
public:
    Entity(int maxHP, float x, float y, float width, float height, int spriteIndex);
    virtual ~Entity();

    // Getters //
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
    int getHP() const;
    bool isMoving() const;
    int getSprite() const;
    bool isAlive() const;

    // Setters //
    void gotoX(float x);
    void gotoY(float y);
    void gotoPosition(float x, float y);
    void moveByX(float value);
    void moveByY(float value);
    void moveByVector(float valueX, float valueY);
    void killEntity();
    void takeDamage(int dmgAmount);
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

Entity::Entity(int maxHP, float x, float y, float width, float height,int spriteIndex)
{
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    m_maxHP = maxHP;
    m_hp = maxHP;
    m_spriteIndex = spriteIndex;
    m_isAlive = true;
    m_isMoving = false;
}

Entity::~Entity()
{

}

float Entity::getX() const {
    return m_x;
}
float Entity::getY() const {
    return m_y;
}
float Entity::getWidth() const {
    return m_width;
}
float Entity::getHeight() const {
    return m_height;
}
int Entity::getHP() const {
    return m_hp;
}
bool Entity::isMoving() const {
    return m_isMoving;
}
int Entity::getSprite() const {
    return m_spriteIndex;
}
bool Entity::isAlive() const {
    return m_isAlive;
}


void Entity::gotoX(float x) {
    m_x = x;
}
void Entity::gotoY(float y) {
    m_y = y;
}
void Entity::gotoPosition(float x, float y) {
    m_x = x;
    m_y = y;
}
void Entity::moveByX(float value) {
    m_x += value;
}
void Entity::moveByY(float value) {
    m_y += value;
}
void Entity::moveByVector(float valueX, float valueY) {
    m_x += valueX;
    m_y += valueY;
}
void Entity::killEntity() {
    m_isAlive = false;
    m_hp = 0;
}
void Entity::takeDamage(int dmgAmount) {
    m_hp -= dmgAmount;
}
void Entity::shoot() {
}

#endif
