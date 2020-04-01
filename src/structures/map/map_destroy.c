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
    for (uint i = 0 ; map->collisions[i] ; i++)
        free(map->collisions[i]);
    free(map->collisions);
    sfVertexArray_destroy(map->back);
    sfVertexArray_destroy(map->top);
    sfTexture_destroy(map->tileset);
}