#include <stdio.h>
#include "character.h"

void showStats(struct Character *player) // pointer for character struct to access original data
{
    printf("\nPlayer Stats:\n");
    printf("Name: %s\n", player->name); // "->"" is the same as "*";
    printf("HP: %d\n", player->hp);     // -> is used for accessing values inside Character struct */
    printf("Attack: %d\n", player->attack);
    printf("Level: %d\n", player->level);
    printf("EXP: %d\n", player->exp);
}
