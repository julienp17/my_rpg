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
    for (uint i = 0 ; map->collision[i] ; i++)
        free(map->collision[i]);
    for (uint i = 0 ; map->npcs[i] ; i++)
        npc_destroy(map->npcs[i]);
    for (uint i = 0 ; map->warps[i] ; i++)
        warp_destroy(map->warps[i]);
    free(map->collision);
    free(map->npcs);
    free(map->warps);
    free(map->name);
    sfVertexArray_destroy(map->bottom);
    sfVertexArray_destroy(map->top);
    sfTexture_destroy(map->map_tileset);
    sfTexture_destroy(map->npc_sheet);
}