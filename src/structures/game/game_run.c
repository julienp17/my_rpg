/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_run
*/

#include "game.h"

int game_run(game_t *game)
{
    if (game_load(game) == -1)
        return (-1);
    sfMusic_setLoop(MUSIC("onett"), sfTrue);
    sfMusic_setVolume(MUSIC("onett"), 40.0f);
    sfMusic_play(MUSIC("onett"));
    while (game->state != QUIT)
        game_loop(game);
    return (0);
}