#ifndef ENEMY_H
#define ENEMY_H

#include "entity.hpp"
#include "player.hpp"
#include "constants.hpp"

class Enemy : public Entity
{
public:
    Enemy();
    Enemy(int maxHP, float x, float y, float width, float height, int spriteIndex);
    virtual ~Enemy();

    void shoot(C3D_RenderTarget* top);
    void setProjectile(float x, float y);
    bool checkCollisions(Player& player);
    void move(float dx, float dy);
    void setShooting(bool keep);
    bool isShooting();
private:
    Vector2f m_projectilePosition;
    bool m_shooting;

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

bool Enemy::isShooting(){
    return m_shooting;
}

void Enemy::setProjectile(float x, float y){
    m_projectilePosition.setX(x);
    m_projectilePosition.setY(y);
}
void Enemy::setShooting(bool keep){
    m_shooting=keep;
}



void Enemy::shoot(C3D_RenderTarget* top){
    C2D_DrawRectangle(m_projectilePosition.x(), m_projectilePosition.y(), 0.0f, 4.0f, 10.0f, C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF), C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF), C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF), C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF));
    m_projectilePosition.setY(m_projectilePosition.y() - 6.0f);

    if(m_projectilePosition.y() > MAX_SCREEN_HEIGHT){
        m_shooting=false;
    }
    
}

bool Enemy::checkCollisions(Player& player) {
    if (m_projectilePosition.x() >= player.getX() - player.getWidth() / 2 && m_projectilePosition.x() <= player.getX() + player.getWidth() / 2 && m_projectilePosition.y() >= player.getY() - player.getHeight() / 2 && m_projectilePosition.y() <= player.getY() + player.getHeight() / 2) {
        printf("Player hit by projectile\n");
        m_shooting = false;
        return true;
    }

    return false;
}



#endif
