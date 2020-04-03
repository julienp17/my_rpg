/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Load a game structure
*/

#include "game.h"
#include "my_rpg.h"

int game_load(game_t *game)
{
    if (assets_load(game->assets) == -1)
        return (-1);
    if (map_load(game->map, "debug", "assets/tilesets/map1.png") == -1)
        return (-1);
    if (player_load(game->player, PLAYER_TILESET_PATH) == -1)
        return (-1);
    sfView_setSize(game->view, (v2f) {VIEW_SIZE});
    return (0);
}