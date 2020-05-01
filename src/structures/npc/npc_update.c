/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Update an npc
*/

#include "npc.h"

void npc_update(npc_t *npc, int delta_time)
{
    animation_update(npc, (void *)&npc_update_animation, delta_time);
}