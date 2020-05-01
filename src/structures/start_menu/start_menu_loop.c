/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start_menu_loop
*/

#include "game.h"
#include "start_menu.h"

void start_menu_loop(game_t *game, start_menu_t *start_menu)
{
    start_menu_poll_events(game);
    start_menu_update(game, start_menu);
    sfRenderWindow_clear(game->win, sfWhite);
    start_menu_draw(game->win, start_menu);
    sfRenderWindow_display(game->win);
}
