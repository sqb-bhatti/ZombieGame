//
// Created by Saqib Bhatti on 28/5/24.
//

#ifndef ZOMBIEGAME_ZOMBIE_H
#define ZOMBIEGAME_ZOMBIE_H


#include <SFML/Graphics.hpp>

using namespace  sf;



class Zombie {
private:
    // How fast is each zombie type?
    const float BLOATER_SPEED = 40;
    const float CHASER_SPEED = 80;
    const float CRAWLER_SPEED = 20;

    // How tough is each zombie type
    const float BLOATER_HEALTH = 5;
    const float CHASER_HEALTH = 1;
    const float CRAWLER_HEALTH = 3;

    // Make each zombie vary its speed slightly. will help us determine the individual speed of each zombie.
    const int MAX_VARRIANCE = 30;
    const int OFFSET = 101 - MAX_VARRIANCE;

    // zombie position
    Vector2f m_Position;
    Sprite m_Sprite;
    float m_Speed;
    float m_Health;

    // Is zombie still alive?
    bool m_Alive;

public:
    // Handle when a bullet hits a zombie
    bool hit();

    // Find out if the zombie is alive
    bool isAlive();

    // Spawn a new zombie
    void spawn(float startX, float startY, int type, int seed);

    // Return a rectangle that is the position in the world
    FloatRect getPosition();

    // Get a copy of the sprite to draw
    Sprite getSprite();

    // Update the zombie each frame
    void update(float elapsedTime, Vector2f playerLocation);
};


#endif //ZOMBIEGAME_ZOMBIE_H
