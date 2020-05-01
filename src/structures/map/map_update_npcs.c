/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Update the npcs of a map
*/

#include "map.h"

void map_update_npcs(map_t *map, int delta_time)
{
    for (uint i = 0 ; map->npcs[i] ; i++)
        npc_update(map->npcs[i], delta_time);
}