#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void battle(struct Character *player, struct Character enemy)
// * is used for player so that after "battle" function, the changes are updated, not recycled
{
    int choice;

    while (player->hp > 0 && enemy.hp > 0)
    {
        showStats(player);
        printf("\nEnemy HP: %d\n", enemy.hp);

        printf("\n1. Attack\n2. Heal\nChoose: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int damage = getRandom(1, player->attack);
            enemy.hp -= damage;
            printf("You dealt %d damage!\n", damage);
        }
        else if (choice == 2)
        {
            int heal = getRandom(2, 5);
            player->hp += heal;
            printf("You healed %d HP!\n", heal);
        }
        else
        {
            printf("Invalid choice!\n");
            continue;
        }

        if (enemy.hp > 0)
        {
            int enemyDamage = getRandom(1, enemy.attack);
            player->hp -= enemyDamage;
            printf("%s attacks and deals %d damage!\n", enemy.name, enemyDamage);
        }
    }

    if (player->hp > 0)
    {
        printf("\nYou defeated %s!\n", enemy.name);
    }
}

void levelUp(struct Character *player)
{
    if (player->exp >= 20)
    {
        player->level++;
        player->attack += 2;
        player->hp += 10;
        player->exp = 0;

        printf("\n*** LEVEL UP! ***\n");
        printf("You are now Level %d\n", player->level);
    }
}

int getRandom(int min, int max)
{
    return rand() % (max - min + 1) + min; //  % → limits range; + min → shifts range
}
