//
// Created by Saqib Bhatti on 22/5/24.
//

#ifndef ZOMBIEGAME_CREATEBACKGROUND_H
#define ZOMBIEGAME_CREATEBACKGROUND_H


#include <SFML/Graphics.hpp>
#include "Zombie.h"

using namespace sf;


int createBackground(VertexArray& rVA, IntRect arena);
Zombie* createHorde(int numZombies, IntRect arena);





#endif //ZOMBIEGAME_CREATEBACKGROUND_H
