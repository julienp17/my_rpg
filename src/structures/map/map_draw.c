/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draws a map
*/

#include "map.h"

void map_draw(window_t *win, map_t *map, layer_name_t layer_name)
{
    layer_t *map_layer = NULL;
    sfRenderStates states;

    states.blendMode = sfBlendAlpha;
    states.shader = NULL;
    states.transform = sfTransform_Identity;
    states.texture = map->tileset;
    map_layer = (layer_name == BACK) ? map->back : map->top;
    sfRenderWindow_drawVertexArray(win, map_layer, &states);
}