/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Load a player structure
*/

#include "player.h"
#include "my.h"

int player_load(player_t *player, char const *tileset_path)
{
    sfIntRect sprite_rect = {0, 0, 0, 0};
    v2u tileset_size;

    player->tileset = sfTexture_createFromFile(tileset_path, NULL);
    if (player->tileset == NULL) {
        my_puterr("Couldn't allocate memory for player sprite.\n");
        return (-1);
    }
    tileset_size = sfTexture_getSize(player->tileset);
    sprite_rect.width  = tileset_size.x / 4;
    sprite_rect.height = tileset_size.y / 4;
    sfSprite_setTexture(player->sprite, player->tileset, sfFalse);
    sfSprite_setTextureRect(player->sprite, sprite_rect);
    sfSprite_setPosition(player->sprite, v2f(0, 0));
    return (0);
}