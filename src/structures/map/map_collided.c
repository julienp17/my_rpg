/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns true if the given tile is a collision, false otherwise
*/

#include <stdbool.h>
#include "map.h"

bool map_collided(map_t *map, v2i coord)
{
    return (map->collisions[coord.y][coord.x] != -1);
}