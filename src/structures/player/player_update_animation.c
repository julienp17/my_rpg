/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Update the player animation
*/

#include "player.h"

void player_update_animation(player_t *player)
{
    v2u tileset_size = v2u(0, 0);
    irect sprite_rect = irect(0, 0, 0, 0);

    tileset_size = sfTexture_getSize(player->tileset);
    sprite_rect = sfSprite_getTextureRect(player->sprite);
    sprite_rect.top = sprite_rect.height * (player->orientation % sfKeyLeft);
    if (sprite_rect.left + sprite_rect.width >= (int)tileset_size.x)
        sprite_rect.left = 0;
    else
        sprite_rect.left += sprite_rect.width;
    sfSprite_setTextureRect(player->sprite, sprite_rect);
}