/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_update
*/

#include "player.h"

void player_update(player_t *player, int delta_time)
{
    player->anim->elapsed += delta_time;
    if (animation_can_update(player->anim) == false)
        return;
    player->anim->elapsed -= player->anim->switch_time;
    player_update_animation(player);
}