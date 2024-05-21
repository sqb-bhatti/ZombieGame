//
// Created by Saqib Bhatti on 18/5/24.
//

#ifndef ZOMBIEGAME_PLAYER_H
#define ZOMBIEGAME_PLAYER_H


#include <SFML/Graphics.hpp>


using namespace sf;


class Player {
private:
    const float START_SPEED = 200;
    const float START_HEALTH = 100;

    // Where is the player
    Vector2f m_Position;

    Sprite m_Sprite;

    // And a texture
    Texture m_Texture;

    // Screen resolution
    Vector2f m_Resolution;

    // What size is the current arena
    IntRect m_Arena;

    // How big is each tile of the arena
    int m_TileSize;

    // Which direction(s) is the player currently moving in
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_LeftPressed;
    bool m_RightPressed;

    // How much health has the player got?
    int m_Health;

    // What is the maximum health the player can have
    int m_MaxHealth;

    // When was the player last hit
    Time m_LastHit; // for recording the time that the player last received a hit from a zombie.

    // Speed in pixels per second
    float m_Speed;

public:
    Player();
    void spawn(IntRect arena, Vector2f resolution, int tileSize);

    // Call this at the end of every game
    void resetPlayerStats();

    // Handle the player getting hit by a zombie
    bool hit(Time timeHit);

    // How long ago was the player last hit
    Time getLastHitTime();

    // Where is the player
    FloatRect getPosition();

    // Where is the center of the player
    Vector2f getCenter();

    // What angle is the player facing
    float getRotation();

    // Send a copy of the sprite to the main function
    Sprite getSprite();

    // The next four functions move the player
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    // Stop the player from moving in a specific direction
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();

    // call this function once every frame
    void update(float elapsedTime, Vector2i mousePosition);

    // Give the player a speed boost
    void upgradeSpeed();

    // Give the player some health
    void upgradeHealth();

    // Increase the maximum amount of health the player can have
    void increaseHealthLevel(int amount);

    // How much health has the player currently got?
    int getHealth();
};

#endif //ZOMBIEGAME_PLAYER_H
