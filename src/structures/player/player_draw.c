/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw the player
*/

#include "player.h"

void player_draw(window_t *win, player_t *player)
{
    sfRenderWindow_drawSprite(win, player->sprite, NULL);
}