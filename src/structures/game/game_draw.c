/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw the game
*/

#include "game.h"

static void draw_npc_text(game_t *game);

void game_draw(game_t *game)
{
    sfRenderWindow_setView(game->win, game->view);
    sfRenderWindow_clear(game->win, sfBlack);
    map_draw_layer(game->win, game->map, BOTTOM);
    map_draw_npcs(game->win, game->map);
    player_draw(game->win, game->player);
    map_draw_layer(game->win, game->map, TOP);
    sfRenderWindow_setView(game->win, sfRenderWindow_getDefaultView(game->win));
    if (game->player->is_interacting)
        draw_npc_text(game);
    sfRenderWindow_display(game->win);
}

static void draw_npc_text(game_t *game)
{
    v2i grid_pos = v2i(0, 0);
    npc_t *npc = NULL;

    grid_pos = player_get_facing_tile(game->player);
    npc = map_get_npc_from_grid(game->map, grid_pos);
    if (npc)
        npc_draw_text(game->win, npc, FONT("apple_kid"));
}