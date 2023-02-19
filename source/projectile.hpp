#ifndef PROJECTILE_H
#define PROJECTILE_H

#pragma once

#include "vector2f.hpp"
#include "constants.hpp"

class Projectile {
public:
    Projectile();
    Projectile(float x, float y, float width, float height);
    virtual ~Projectile();

    void move(float dy);
    void draw();
    bool checkCollisions(float x, float y, float width, float height);

    bool isAlive();
    void setAlive(bool alive);

private:
    Vector2f m_position;
    float m_width;
    float m_height;

    bool m_alive;
};

Projectile::Projectile()
    : m_position(0.0f, 0.0f), m_width(0.0f), m_height(0.0f), m_alive(false)
{

}

Projectile::Projectile(float x, float y, float width, float height)
    : m_position(x, y), m_width(width), m_height(height),  m_alive(true)
{

}

Projectile::~Projectile()
{

}

void Projectile::move(float dy)
{
    m_position.setY(m_position.y() + dy);

    if (m_position.y() < 0.0f || m_position.y() > MAX_SCREEN_HEIGHT) {
        m_alive = false;
    }
}

void Projectile::draw()
{
    if (m_alive) {
    C2D_DrawRectangle(m_position.x(), m_position.y(), 0.0f, 4.0f, 10.0f, C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF), C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF), C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF), C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF));
    }
}

bool Projectile::checkCollisions(float x, float y, float width, float height)
{
    if (m_alive && x - width / 2.0f <= m_position.x() + m_width / 2.0f &&
       x + width / 2.0f >= m_position.x() - m_width / 2.0f &&
       y - height / 2.0f <= m_position.y() + m_height / 2.0f &&
       y + height / 2.0f >= m_position.y() - m_height / 2.0f) {
        m_alive = false;
        return true;
    }
    return false;
}

bool Projectile::isAlive()
{
    return m_alive;
}
void Projectile::setAlive(bool alive){
    m_alive=alive;
}

#endif
