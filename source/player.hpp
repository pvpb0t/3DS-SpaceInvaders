#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(float x, float y, int width, int height, int health) : 
        m_x(x), m_y(y), m_width(width), m_height(height), m_health(health) {}
    void move(int deltaX, int deltaY);
    void shoot();
    void takeDamage(int damage);
    bool isAlive();
    float getX() const;
    void setX(float x);
    float getY() const;
    void setY(float y);
private:
    float m_x;
    float m_y;
    int m_width;
    int m_height;
    int m_health;
};

float Player::getX() const {
    return m_x;
}

void Player::setX(float x) {
    m_x = x;
}

float Player::getY() const {
    return m_y;
}

void Player::setY(float y) {
    m_y = y;
}


#endif
