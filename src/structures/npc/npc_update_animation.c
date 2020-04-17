/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Update the npc animation
*/

#include "npc.h"
#include "my_rpg.h"

void npc_update_animation(npc_t *npc)
{
    sprite_flip(npc->sprite);
}