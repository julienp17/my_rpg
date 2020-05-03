/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Update the view of the game
*/

#include "game.h"

void ingame_update_view(game_t *game)
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
    if (view_size.x > game->map->size.x && view_size.y > game->map->size.y)
        center = v2f(game->map->size.x / 2.0f, game->map->size.y / 2.0f);
    sfView_setCenter(game->view, center);
}