/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Poll events when the game is playing
*/

#include <SFML/Graphics.h>
#include "game.h"
#include "my_rpg.h"

static bool is_movement_key(sfKeyCode key);
static void handle_key_pressed(sfEvent *event, game_t *game);
static void check_window_quit(sfEvent *event, sfRenderWindow *window);

void game_poll_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->win, &event)) {
        check_window_quit(&event, game->win);
        if (event.type == sfEvtKeyPressed)
            handle_key_pressed(&event, game);
    }
}

static void check_window_quit(sfEvent *event, window_t *window)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->key.code == sfKeyEscape)
        sfRenderWindow_close(window);
}

static void handle_key_pressed(sfEvent *event, game_t *game)
{
    switch (event->key.code) {
    case sfKeyUp:    game->player->orientation = BACK; break;
    case sfKeyDown:  game->player->orientation = FRONT; break;
    case sfKeyLeft:  game->player->orientation = LEFT; break;
    case sfKeyRight: game->player->orientation = RIGHT; break;
    default: break;
    }
    if (is_movement_key(event->key.code)) {
        player_update_animation(game->player);
        if (player_can_move(game->player, game->map, event->key.code))
            player_move(game->player, get_offset_by_key(event->key.code));
    }
}

static bool is_movement_key(sfKeyCode key)
{
    return (key == sfKeyUp || key == sfKeyDown
            || key == sfKeyRight || key == sfKeyLeft);
}