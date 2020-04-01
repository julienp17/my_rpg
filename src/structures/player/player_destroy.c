/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Destroys a player structure
*/

#include <stdlib.h>
#include "player.h"

void player_destroy(player_t *player)
{
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->tileset);
    free(player);
}