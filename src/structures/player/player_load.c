/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Load a player structure
*/

#include <stdlib.h>
#include "player.h"
#include "my.h"

static int init_sprite(player_t *player, char const *tileset_path);
static void init_stats(player_t *player);

int player_load(player_t *player, char const *tileset_path)
{
    if (init_sprite(player, tileset_path) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    init_stats(player);
    player_update_animation(player);
    return (0);
}

static int init_sprite(player_t *player, char const *tileset_path)
{
    irect sprite_rect = irect(0, 0, 0, 0);
    v2u tileset_size = v2u(0, 0);

    player->tileset = sfTexture_createFromFile(tileset_path, NULL);
    if (player->tileset == NULL) {
        my_puterr("Couldn't allocate memory for player sprite.\n");
        return (EXIT_FAILURE);
    }
    tileset_size = sfTexture_getSize(player->tileset);
    sprite_rect.width  = tileset_size.x / PLAYER_SHEET_COLS;
    sprite_rect.height = tileset_size.y / PLAYER_SHEET_ROWS;
    sfSprite_setTexture(player->sprite, player->tileset, sfFalse);
    sfSprite_setTextureRect(player->sprite, sprite_rect);
    sfSprite_setPosition(player->sprite, v2f(0, 0));
    return (EXIT_SUCCESS);
}

static void init_stats(player_t *player)
{
    player->stats->health = 21;
    player->stats->mana = 14;
    player->stats->atk = 8;
    player->stats->def = 6;
    player->stats->xp = 4;
}