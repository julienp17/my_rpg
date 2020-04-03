/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_rpg main file
*/

#include "game.h"
#include "my_rpg.h"

int my_rpg(window_t *win)
{
    game_t *game = NULL;

    game = game_create(win);
    if (game == NULL)
        return (-1);
    if (game_load(game) == -1)
        return (-1);
    while (sfRenderWindow_isOpen(game->win)) {
        game_poll_events(game);
        update_view(game->view, game->player, game->map);
        sfRenderWindow_setView(game->win, game->view);
        game_draw(game);
    }
    return (0);
}