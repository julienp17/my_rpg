/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Update_view
*/

#include "game.h"
#include "my_rpg.h"

void update_view(view_t *view, player_t *player, map_t *map)
{
    v2f view_size;
    v2f center;

    view_size = sfView_getSize(view);
    center = sprite_get_center(player->sprite);
    if (center.x - view_size.x / 2 < 0)
        center.x = view_size.x / 2;
    if (center.x + view_size.x / 2 > map->size.x)
        center.x = map->size.x - view_size.x / 2;
    if (center.y - view_size.y / 2 < 0)
        center.y = view_size.y / 2;
    if (center.y + view_size.y / 2 > map->size.y)
        center.y = map->size.y - view_size.y / 2;
    sfView_setCenter(view, center);
}