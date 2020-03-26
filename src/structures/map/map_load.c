/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Loads a map from a map CSV file and a tileset
*/

#include <stdlib.h>
#include "map.h"
#include "my.h"

int map_load(map_t *map, char const *map_path, texture_t *tileset)
{
    map->tileset = tileset;
    if (map->vertices != NULL)
        sfVertexArray_destroy(map->vertices);
    map->vertices = vertices_load(map_path, tileset);
    if (map->tileset == NULL || map->vertices == NULL)
        return (-1);
    return (0);
}