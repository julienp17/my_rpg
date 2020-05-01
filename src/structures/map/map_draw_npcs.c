/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** Draw the npcs of a map
*/

#include "map.h"

void map_draw_npcs(window_t *win, map_t *map)
{
    for (uint i = 0 ; map->npcs[i] ; i++)
        npc_draw(win, map->npcs[i]);
}