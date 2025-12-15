// acts as a connection between files by declaring functions
#ifndef GAME_H
#define GAME_H

#include "character.h"

void battle(struct Character *player, struct Character enemy);
void levelUp(struct Character *player);
int getRandom(int min, int max); // reusable random number logic function declared
void showStats(struct Character *player);

#endif
