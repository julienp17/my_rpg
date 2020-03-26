/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns a newly allocated map structure
*/

#include <stdlib.h>
#include "map.h"

map_t *map_create(void)
{
    map_t *map = NULL;

    map = malloc(sizeof(map_t));
    if (map == NULL) {
        my_puterr("Couldn't allocate memory for map structure.\n");
        return (NULL);
    }
    map->tileset = NULL;
    map->vertices = NULL;
    return (map);
}