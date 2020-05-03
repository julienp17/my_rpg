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
    sfTime delta_time = sfTime_Zero;

    delta_time = sfClock_restart(game->clock);
    start_menu_poll_events(game);
    start_menu_update(game, start_menu, delta_time);
    sfRenderWindow_clear(game->win, sfBlack);
    start_menu_draw(game->win, start_menu, FONT("apple_kid"));
    sfRenderWindow_display(game->win);
}
