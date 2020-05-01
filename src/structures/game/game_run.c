/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_run
*/

#include "game.h"
#include "start_menu.h"
#include "pause_menu.h"

int game_run(game_t *game)
{
    if (game_load(game) == -1)
        return (-1);
    while (game->state != QUIT) {
        if (game->state == START_MENU)
            start_menu_run(game);
        if (game->state == INGAME)
            ingame_run(game);
        if (game->state == PAUSE_MENU)
            pause_menu_run(game);
    }
    return (0);
}