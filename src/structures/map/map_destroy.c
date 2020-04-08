/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Destroys a map structure
*/

#include <stdlib.h>
#include "map.h"

void map_destroy(map_t *map)
{
    for (uint i = 0 ; map->objects[i] ; i++)
        free(map->objects[i]);
    free(map->objects);
    sfVertexArray_destroy(map->bottom);
    sfVertexArray_destroy(map->top);
    sfTexture_destroy(map->tileset);
}