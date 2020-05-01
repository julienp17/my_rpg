/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Update the player animation
*/

#include "player.h"

void player_update_animation(player_t *player)
{
    irect sprite_rect;

    sprite_rect = sfSprite_getTextureRect(player->sprite);
    sprite_rect.top = sprite_rect.height * (player->orientation % sfKeyLeft);
    if (player_is_moving(player) == false) {
        sprite_rect.left = 0;
    } else {
        if (sprite_rect.left == sprite_rect.width)
            sprite_rect.left += sprite_rect.width;
        else
            sprite_rect.left = sprite_rect.width;
    }
    sfSprite_setTextureRect(player->sprite, sprite_rect);
}