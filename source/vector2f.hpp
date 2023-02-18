#ifndef VECTOR2F_HPP
#define VECTOR2F_HPP
#include <cmath>
class Vector2f {
public:
    Vector2f(float x = 0, float y = 0);
    float x() const;
    float y() const;
    void setX(float x);
    void setY(float y);
    Vector2f operator+(const Vector2f& other) const;
    Vector2f operator-(const Vector2f& other) const;
    Vector2f operator*(float scalar) const;
    Vector2f operator/(float scalar) const;
    float dot(const Vector2f& other) const;
    float magnitude() const;
    Vector2f normalized() const;
private:
    float m_x;
    float m_y;
};
Vector2f::Vector2f(float x, float y)
    : m_x(x), m_y(y)
{
}

float Vector2f::x() const
{
    return m_x;
}

float Vector2f::y() const
{
    return m_y;
}

void Vector2f::setX(float x)
{
    m_x = x;
}

void Vector2f::setY(float y)
{
    m_y = y;
}

Vector2f Vector2f::operator+(const Vector2f& other) const
{
    return Vector2f(m_x + other.m_x, m_y + other.m_y);
}

Vector2f Vector2f::operator-(const Vector2f& other) const
{
    return Vector2f(m_x - other.m_x, m_y - other.m_y);
}

Vector2f Vector2f::operator*(float scalar) const
{
    return Vector2f(m_x * scalar, m_y * scalar);
}

Vector2f Vector2f::operator/(float scalar) const
{
    return Vector2f(m_x / scalar, m_y / scalar);
}

float Vector2f::dot(const Vector2f& other) const
{
    return m_x * other.m_x + m_y * other.m_y;
}

float Vector2f::magnitude() const
{
    return std::sqrt(m_x * m_x + m_y * m_y);
}

Vector2f Vector2f::normalized() const
{
    float mag = magnitude();
    return Vector2f(m_x / mag, m_y / mag);
}

#endif // VECTOR2F_HPP
