//
// Created by Saqib Bhatti on 13/7/24.
//

#ifndef ZOMBIEGAME_BULLET_H
#define ZOMBIEGAME_BULLET_H


#include <SFML/Graphics.hpp>


using namespace sf;


class Bullet {
private:
    Vector2f m_Position;

    // each bullet looks like
    RectangleShape m_BulletShape;

    // Is this bullet currently whizzing through the air. This will allow us to decide
    //whether we need to call its update function each frame and whether we need to run
    //collision detection checks.
    bool m_InFlight = false;

    float m_BulletSpeed = 1000;

    // What fraction of 1 pixel does the bullet travel, Horizontally and vertically each frame?
    float m_BulletDistanceX;
    float m_BulletDistanceY;

    // Some boundaries so the bullet doesn't fly forever
    float m_MaxX;
    float m_MinX;
    float m_MaxY;
    float m_MinY;

public:
    Bullet();

    // Stop the bullet
    void stop();

    // Returns the value of m_InFlight
    bool isInFlight();

    // Launch a new bullet
    void shoot(float startX, float startY, float xTarget, float yTarget);

    // Tell the calling code where the bullet is in the world
    FloatRect getPosition();

    // Return the actual shape (for drawing)
    RectangleShape getShape();

    // Update the bullet each frame
    void update(float elapsedTime);
};


#endif //ZOMBIEGAME_BULLET_H
