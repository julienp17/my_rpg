/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns true if the player can move, false otherwise
*/

#include <stdbool.h>
#include "player.h"
#include "map.h"
#include "my_rpg.h"

static bool is_out_of_bounds(v2f new_pos, v2i player_size, map_t *map);
static bool tile_collided(v2f new_pos, v2i player_size, map_t *map, v2f offset);

bool player_can_move(player_t *player, map_t *map, v2f offset)
{
    v2f player_pos;
    v2i player_size;
    v2f new_pos;
    sfIntRect texture_rect;

    player_pos    = sfSprite_getPosition(player->sprite);
    texture_rect  = sfSprite_getTextureRect(player->sprite);
    player_size.x = texture_rect.width;
    player_size.y = texture_rect.height;
    new_pos = v2f_add(player_pos, offset);
    if (is_out_of_bounds(new_pos, player_size, map))
        return (false);
    if (tile_collided(new_pos, player_size, map, offset))
        return (false);
    return (true);
}

static bool is_out_of_bounds(v2f new_pos, v2i player_size, map_t *map)
{
    return (
        new_pos.x < 0
        || new_pos.y < 0
        || new_pos.x + player_size.x > map->size.x
        || new_pos.y + player_size.y > map->size.y
    );
}

static bool tile_collided(v2f new_pos, v2i player_size, map_t *map, v2f offset)
{
    v2i new_pos_grid;

    new_pos_grid = v2f_to_grid(new_pos, TILE_SIZE);
    if (offset.x > 0)
        new_pos_grid.x = (new_pos.x + player_size.x) / TILE_SIZE;
    else if (offset.y > 0)
        new_pos_grid.y = (new_pos.y + player_size.y) / TILE_SIZE;
    return (map_collided(map, new_pos_grid));
}