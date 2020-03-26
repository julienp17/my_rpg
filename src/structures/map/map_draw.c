/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draws a map
*/

#include "map.h"

void map_draw(window_t *window, map_t *map)
{
    sfRenderStates states;

    states.blendMode = sfBlendNone;
    states.shader = NULL;
    states.transform = sfTransform_Identity;
    states.texture = map->tileset;
    sfRenderWindow_drawVertexArray(window, map->map, &states);
}