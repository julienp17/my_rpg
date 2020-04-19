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
static void handle_player_movement(sfKeyCode key, game_t *game);
static void handle_wrap(map_t *map, player_t *player);

void game_poll_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->win);
        else if (event.type == sfEvtKeyPressed)
            handle_key_pressed(event.key.code, game);
    }
}

static void handle_key_pressed(sfKeyCode key, game_t *game)
{
    if (key == sfKeyEscape)
        sfRenderWindow_close(game->win);
    else if (is_movement_key(key))
        handle_player_movement(key, game);
}

static void handle_player_movement(sfKeyCode key, game_t *game)
{
    v2f offset = v2f(0, 0);

    switch (key) {
    case sfKeyUp:    game->player->orientation = BACK;  break;
    case sfKeyDown:  game->player->orientation = FRONT; break;
    case sfKeyLeft:  game->player->orientation = LEFT;  break;
    case sfKeyRight: game->player->orientation = RIGHT; break;
    default:                                            break;
    }
    player_update_animation(game->player);
    offset = get_offset_by_key(key);
    if (player_can_move(game->player, game->map, offset)) {
        player_move(game->player, offset);
        handle_wrap(game->map, game->player);
    }
}

static void handle_wrap(map_t *map, player_t *player)
{
    warp_t *warp = NULL;
    v2f pos = v2f(0, 0);

    pos = sfSprite_getPosition(player->sprite);
    for (uint i = 0 ; map->warps[i] && warp == NULL ; i++)
        if (sfFloatRect_contains(&(map->warps[i]->zone), pos.x, pos.y))
            warp = map->warps[i];
    if (warp) {
        map_load(map, warp->map_name);
        sfSprite_setPosition(player->sprite, warp->dest);
    }
}

static bool is_movement_key(sfKeyCode key)
{
    return (key == sfKeyUp || key == sfKeyDown
            || key == sfKeyRight || key == sfKeyLeft);
}