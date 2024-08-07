//
// Created by Saqib Bhatti on 13/7/24.
//

#include "Bullet.h"
#include "TextureHolder.h"


Bullet::Bullet() {
    m_BulletShape.setSize(Vector2f(2, 2));
//    m_BulletSprite = Sprite(TextureHolder::GetTexture("graphics/bullet.png"));
}


void Bullet::shoot(float startX, float startY, float xTarget, float yTarget) {
    m_InFlight = true;
    m_Position.x = startX;
    m_Position.y = startY;

    // Calculate the gradient of the flight path. trigonometry to determine the gradient of travel for a bullet.
    float gradient = (startX - xTarget) / (startY - yTarget);

    if (gradient < 0) {
        gradient *= -1;
    }

    // Calculate the ratio between x and y. This will allow us to change the bullet's horizontal and vertical position
    // by the correct amount each frame, based on the target the bullet is heading toward.
    float ratioXY = m_BulletSpeed / (1 + gradient);

    // Set the "speed" horizontally and vertically
    m_BulletDistanceY = ratioXY;
    m_BulletDistanceX = ratioXY * gradient;

    // Point the bullet in the right direction
    if (xTarget < startX) {
        m_BulletDistanceX *= -1;
    }

    if (yTarget < startY) {
        m_BulletDistanceY *= -1;
    }

    // Set a max range of 1000 pixels
    float range = 1000;
    m_MinX = startX - range;
    m_MaxX = startX + range;
    m_MinY = startY - range;
    m_MaxY = startY + range;

    // Position the bullet ready to be drawn
    m_BulletShape.setPosition(m_Position);
}



void Bullet::stop() {
    m_InFlight = false;
}


bool Bullet::isInFlight() {
    return m_InFlight;
}


FloatRect Bullet::getPosition() {
    return m_BulletShape.getGlobalBounds();
}


RectangleShape Bullet::getShape() {
    return m_BulletShape;
}


void Bullet::update(float elapsedTime) {
    m_Position.x += m_BulletDistanceX * elapsedTime;
    m_Position.y += m_BulletDistanceY * elapsedTime;

    // Move the bullet
    m_BulletShape.setPosition(m_Position);

    // Has the bullet gone out of range?
    if (m_Position.x < m_MinX || m_Position.x > m_MaxX ||
            m_Position.y < m_MinY || m_Position.y > m_MaxY) {

        m_InFlight = false;
    }
}