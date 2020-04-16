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
    v2f player_start_pos = v2f(0, 0);

    if (assets_load(game->assets) < 0)
        return (-1);
    if (map_load(game->map, "debug") < 0)
        return (-1);
    if (player_load(game->player, PLAYER_TILESET_PATH) < 0)
        return (-1);
    sfView_setSize(game->view, (v2f) {VIEW_SIZE});
    player_start_pos = (v2f) {PLAYER_START_POS};
    v2f_multiply(&player_start_pos, TILE_SIZE);
    sfSprite_setPosition(game->player->sprite, player_start_pos);
    sfClock_restart(game->clock);
    return (0);
}