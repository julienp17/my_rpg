/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw an NPC
*/

#include "npc.h"

void npc_draw(window_t *win, npc_t *npc)
{
    sfRenderWindow_drawSprite(win, npc->sprite, NULL);
}