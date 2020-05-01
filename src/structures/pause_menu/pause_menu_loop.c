/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu_loop
*/

#include "game.h"
#include "pause_menu.h"

void pause_menu_loop(game_t *game, pause_menu_t *pause_menu)
{
    pause_menu_poll_events(game);
    pause_menu_update(game, pause_menu);
    sfRenderWindow_clear(game->win, sfBlack);
    pause_menu_draw(game, pause_menu);
    sfRenderWindow_display(game->win);
}
