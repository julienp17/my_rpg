/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Get the center of a sprite
*/

#include "graphical_def.h"

v2f sprite_get_center(sprite_t *sprite)
{
    sfFloatRect bounds;

    bounds = sfSprite_getGlobalBounds(sprite);
    return (v2f(bounds.left + bounds.width / 2,bounds.top + bounds.height / 2));
}