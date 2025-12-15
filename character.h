#ifndef CHARACTER_H // prevents multiple inclusion of the same header file
#define CHARACTER_H

struct Character // basically the name, health, atk dmg, lvl, exp for character.
{
    char name[20];
    int hp;
    int attack;
    int level;
    int exp;
};

#endif
