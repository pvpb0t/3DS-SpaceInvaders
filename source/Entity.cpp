#include "Entity.h"

Entity::Entity(int maxHP, float x, float y, float width, float height)
{
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    m_maxHP, m_hp = maxHP;
    m_spriteIndex = 0;
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