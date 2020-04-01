/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Destroys a map structure
*/

#include "map.h"

void map_destroy(map_t *map)
{
    sfVertexArray_destroy(map->vertices);
    sfTexture_destroy(map->tileset);
}