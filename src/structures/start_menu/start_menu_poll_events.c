/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start_menu_poll_events
*/

#include "game.h"

void start_menu_poll_events(game_t *game)
{
    sfEvent event;

    while (game->state == START_MENU && POLL_EVENT(game->win, &event)) {
        if (event.type == sfEvtClosed)
            game->state = QUIT;
    }
}