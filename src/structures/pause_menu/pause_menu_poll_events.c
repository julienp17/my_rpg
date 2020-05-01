/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu_poll_events
*/

#include "game.h"

static void handle_key_pressed(sfKeyCode key, game_t *game);

void pause_menu_poll_events(game_t *game)
{
    sfEvent event;

    while (game->state == PAUSE_MENU && POLL_EVENT(game->win, &event)) {
        if (event.type == sfEvtClosed)
            game->state = QUIT;
        if (event.type == sfEvtKeyPressed)
            handle_key_pressed(event.key.code, game);
    }
}

static void handle_key_pressed(sfKeyCode key, game_t *game)
{
    if (key == sfKeyEscape)
        game->state = INGAME;
}