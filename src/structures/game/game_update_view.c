/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Update the view of the game
*/

#include "game.h"

void game_update_view(game_t *game)
{
    v2f view_size = v2f(0, 0);
    v2f center = v2f(0, 0);

    view_size = sfView_getSize(game->view);
    center    = sprite_get_center(game->player->sprite);
    if (center.x - view_size.x / 2 < 0)
        center.x = view_size.x / 2;
    if (center.x + view_size.x / 2 > game->map->size.x)
        center.x = game->map->size.x - view_size.x / 2;
    if (center.y - view_size.y / 2 < 0)
        center.y = view_size.y / 2;
    if (center.y + view_size.y / 2 > game->map->size.y)
        center.y = game->map->size.y - view_size.y / 2;
    sfView_setCenter(game->view, center);
    sfRenderWindow_setView(game->win, game->view);
}