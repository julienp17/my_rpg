/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns an allocated player structure with initialized fields
*/

#include <stdlib.h>
#include "player.h"
#include "my.h"

player_t *player_create(void)
{
    player_t *player = NULL;

    player = malloc(sizeof(player_t));
    if (player == NULL) {
        my_puterr("Couldn't allocate memory for player structure.\n");
        return (NULL);
    }
    player->sprite = sfSprite_create();
    if (player->sprite == NULL) {
        my_puterr("Couldn't allocate memory for player sprite.\n");
        return (NULL);
    }
    player->anim = animation_create(DEFAULT_SWITCH_TIME);
    if (player->anim == NULL)
        return (NULL);
    player->tileset = NULL;
    player->orientation = sfKeyDown;
    player->move_speed = 0;
    return (player);
}