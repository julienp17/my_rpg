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
static void handle_key_pressed(sfKeyCode key, game_t *game);
static void handle_key_released(sfKeyCode key, game_t *game);

void game_poll_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->win);
        if (event.type == sfEvtKeyPressed)
            handle_key_pressed(event.key.code, game);
        else if (event.type == sfEvtKeyReleased)
            handle_key_released(event.key.code, game);
    }
}

static void handle_key_pressed(sfKeyCode key, game_t *game)
{
    if (key == sfKeyEscape)
        sfRenderWindow_close(game->win);
    else if (is_movement_key(key)) {
        if (game->player->orientation != key) {
            game->player->orientation = key;
            player_update_animation(game->player);
        }
        game->player->move_speed = 1;
    }
}

static void handle_key_released(sfKeyCode key, game_t *game)
{
    if (is_movement_key(key))
        game->player->move_speed = 0;
}

static bool is_movement_key(sfKeyCode key)
{
    return (key == sfKeyUp || key == sfKeyDown
            || key == sfKeyRight || key == sfKeyLeft);
}