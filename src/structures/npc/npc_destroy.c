/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Destroy an npc structure
*/

#include <stdlib.h>
#include "npc.h"

void npc_destroy(npc_t *npc)
{
    sfSprite_destroy(npc->sprite);
    free(npc->name);
    free(npc->text);
    free(npc);
}