/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns a newly allocated map structure
*/

#include <stdlib.h>
#include "map.h"
#include "my.h"

map_t *map_create(void)
{
    map_t *map = NULL;

    map = malloc(sizeof(map_t));
    if (map == NULL) {
        my_puterr("Couldn't allocate memory for map structure.\n");
        return (NULL);
    }
    map->name = NULL;
    map->size = v2f(0.0, 0.0);
    map->bottom = NULL;
    map->top = NULL;
    map->collision = NULL;
    map->npc_sheet = NULL;
    map->map_tileset = NULL;
    map->npcs = NULL;
    map->warps = NULL;
    return (map);
}