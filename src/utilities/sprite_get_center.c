/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Get the center of a sprite
*/

#include "graphical_def.h"

v2f sprite_get_center(sprite_t *sprite)
{
    v2f pos;
    sfFloatRect bounds;

    pos = sfSprite_getPosition(sprite);
    bounds = sfSprite_getGlobalBounds(sprite);
    return (v2f(pos.x + bounds.width / 2, pos.y + bounds.height / 2));
}