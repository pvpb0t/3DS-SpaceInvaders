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