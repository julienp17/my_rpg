/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Update the animation of a structure having an animation field
*/

#include "animation.h"
#include "npc.h"

void animation_update(void *entity, void (*anim_func)(void *), int delta_time)
{
    ((npc_t *)entity)->anim->elapsed += delta_time;
    if (animation_can_update(((npc_t *)entity)->anim)) {
        anim_func(entity);
        ((npc_t *)entity)->anim->elapsed -=((npc_t *)entity)->anim->switch_time;
    }
}