/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Flip a sprite
*/

#include "graphical_def.h"

void sprite_flip(sprite_t *sprite)
{
    irect sprite_rect = irect(0, 0, 0, 0);

    sprite_rect = sfSprite_getTextureRect(sprite);
    sprite_rect.left += sprite_rect.width;
    sprite_rect.width = -sprite_rect.width;
    sfSprite_setTextureRect(sprite, sprite_rect);
}