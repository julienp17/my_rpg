/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu_update
*/

#include "pause_menu.h"

void pause_menu_update(game_t *game, pause_menu_t *pause_menu)
{
    button_update(game->win, pause_menu->quit);
    if (pause_menu->quit->is_pressed)
        game->state = QUIT;
}