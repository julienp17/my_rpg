/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Poll events when the game is playing
*/

#include "game.h"

static bool is_movement_key(sfKeyCode key);
static void handle_key_pressed(sfKeyCode key, game_t *game);
static void handle_key_released(sfKeyCode key, game_t *game);

void ingame_poll_events(game_t *game)
{
    sfEvent event;

    while (game->state == INGAME && POLL_EVENT(game->win, &event)) {
        if (event.type == sfEvtClosed)
            game->state = QUIT;
        if (event.type == sfEvtKeyPressed)
            handle_key_pressed(event.key.code, game);
        else if (event.type == sfEvtKeyReleased)
            handle_key_released(event.key.code, game);
    }
}

static void handle_key_pressed(sfKeyCode key, game_t *game)
{
    if (key == sfKeyEscape) {
        game->state = PAUSE_MENU;
        game->player->move_speed = 0.0f;
    }
    if (is_movement_key(key) && game->player->is_interacting == false) {
        if (game->player->orientation != key) {
            game->player->orientation = key;
            player_update_animation(game->player);
        }
        game->player->move_speed = PLAYER_WALK_MOVE_SPEED;
    }
    if (key == sfKeyE) {
        if (game->player->is_interacting)
            game->player->is_interacting = false;
        else if (player_can_interact(game->player, game->map))
            game->player->is_interacting = true;
    }
    if (key == sfKeyA && player_is_moving(game->player))
        game->player->move_speed = PLAYER_RUN_MOVE_SPEED;
}

static void handle_key_released(sfKeyCode key, game_t *game)
{
    if (is_movement_key(key))
        game->player->move_speed = 0.0f;
    if (key == sfKeyA && player_is_moving(game->player))
        game->player->move_speed = PLAYER_WALK_MOVE_SPEED;
}

static bool is_movement_key(sfKeyCode key)
{
    return (key == sfKeyUp || key == sfKeyDown
            || key == sfKeyRight || key == sfKeyLeft);
}