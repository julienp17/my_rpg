/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Poll events when the game is playing
*/

#include <SFML/Graphics.h>
#include "game.h"

static void handle_keyboard_input(sfEvent *event, game_t *game);
static void check_window_quit(sfEvent *event, sfRenderWindow *window);

void game_poll_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->win, &event)) {
        check_window_quit(&event, game->win);
        if (event.type == sfEvtKeyReleased)
            handle_keyboard_input(&event, game);
    }
}

static void check_window_quit(sfEvent *event, window_t *window)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->key.code == sfKeyEscape || event->key.code == sfKeyQ)
        sfRenderWindow_close(window);
}

static void handle_keyboard_input(sfEvent *event, game_t *game)
{
    switch (event->key.code) {
    case sfKeyZ:
        (void)game;
    default:
        break;
    }
}