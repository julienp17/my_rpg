/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start_menu_update
*/

#include "start_menu.h"

void start_menu_update(game_t *game, start_menu_t *start_menu)
{
    button_update(game->win, start_menu->start);
    button_update(game->win, start_menu->quit);
    if (start_menu->start->is_pressed)
        game->state = INGAME;
    if (start_menu->quit->is_pressed)
        game->state = QUIT;
}