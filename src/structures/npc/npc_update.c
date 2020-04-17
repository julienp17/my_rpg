/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Update an npc
*/

#include "npc.h"

void npc_update(npc_t *npc, int delta_time)
{
    npc->anim->elapsed += delta_time;
    if (animation_can_update(npc->anim)) {
        npc_update_animation(npc);
        npc->anim->elapsed -= npc->anim->switch_time;
    }
}