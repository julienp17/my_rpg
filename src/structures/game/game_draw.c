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
    v2f player_pos = v2f(0.0, 0.0);
    v2i grid_pos = v2i(0, 0);
    v2i dir = v2i(0, 0);
    npc_t *npc = NULL;

    dir = get_dir_by_key(game->player->orientation);
    player_pos = sfSprite_getPosition(game->player->sprite);
    grid_pos = v2f_to_grid(player_pos, TILE_SIZE);
    grid_pos = v2i_add(grid_pos, dir);
    npc = map_get_npc_from_grid(game->map, grid_pos);
    npc_draw_text(game->win, npc, FONT("apple_kid"));
}