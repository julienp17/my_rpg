/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Load a game structure
*/

#include "game.h"

int game_load(game_t *game)
{
    if (assets_load(game->assets) == -1)
        return (-1);
    if (map_load(game->map, "assets/maps/map2.csv", get_tileset(game->assets, "map1")) == -1)
        return (-1);
    return (0);
}