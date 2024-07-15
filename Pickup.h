//
// Created by Saqib Bhatti on 15/7/24.
//

#ifndef ZOMBIEGAME_PICKUP_H
#define ZOMBIEGAME_PICKUP_H


#include <SFML/Graphics.hpp>


using namespace sf;


class Pickup {
private:
    const int HEALTH_START_VALUE = 50;  // used to set the starting value of all health pickups.
    const int AMMO_START_VALUE = 12;
    const int START_WAIT_TIME = 10;  // how long a pickup will wait before it respawns after disappearing.
    const int START_SECONDS_TO_LIVE = 5;  // determines how long a pickup will last between spawning and being de-spawned.

    Sprite m_Sprite;

    IntRect m_Arena;

    // How much is this pickup worth?
    int m_Value;

    // What type of pickup is this? 1 = health, 2 = ammo
    int m_Type;

    // Handle spawning and disappearing
    bool m_Spawned;
    float m_SecondsSinceSpawn;
    float m_SecondsSinceDeSpawn;
    float m_SecondsToLive;
    float m_SecondsToWait;

public:
    Pickup(int type);
    void setArena(IntRect arena);
    void spawn();
    FloatRect getPosition();
    Sprite getSprite();

    // Let the pickup update itself each frame
    void update(float elapsedTime);

    // Is this pickup currently spawned?
    bool isSpawned();

    // will be called when a collision is detected with the player.
    int gotIt();

    // Upgrade the value of each pickup
    void upgrade();
};


#endif //ZOMBIEGAME_PICKUP_H
