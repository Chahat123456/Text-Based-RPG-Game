#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

int main()
{
    srand(time(0)); // eeds the random number generator to ensure different outputs on each run

    struct Character player;
    printf("Enter your character name: ");
    scanf("%19s", player.name); // prevents buffer overflow

    player.hp = 30;
    player.attack = 5;
    player.level = 1;
    player.exp = 0;

    printf("\nWelcome, %s! Your adventure begins...\n", player.name);

    struct Character enemies[3] = {
        {"Goblin", 15, 3, 1, 0},
        {"Orc", 20, 4, 1, 0},
        {"Dragon", 25, 6, 1, 0}};

    printf("=== TEXT BASED RPG GAME ===\n");

    for (int i = 0; i < 3; i++)
    {
        printf("\nA wild %s appears!\n", enemies[i].name);

        battle(&player, enemies[i]); //&player → pass address

        if (player.hp <= 0)
        {
            printf("\nYou were defeated. GAME OVER.\n");
            return 0;
        }

        player.exp += 10;
        levelUp(&player);
    }

    printf("\nCongratulations! You won the game!\n");
    return 0;
}
