/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Load a game structure
*/

#include <stdlib.h>
#include "game.h"
#include "my_rpg.h"

int game_load(game_t *game)
{
    v2f player_start = v2f(0, 0);

    if (assets_load(game->assets) < 0)
        return (-1);
    if (map_load(game->map, "debug") != EXIT_SUCCESS)
        return (-1);
    if (player_load(game->player, PLAYER_SHEET_PATH) < 0)
        return (-1);
    sfView_setSize(game->view, (v2f) {VIEW_SIZE});
    player_start = v2f_multiply((v2f){PLAYER_START}, v2f(TILE_SIZE, TILE_SIZE));
    sfSprite_setPosition(game->player->sprite, player_start);
    sfClock_restart(game->clock);
    return (0);
}