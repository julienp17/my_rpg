/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** pause_menu_draw
*/

#include "game.h"
#include "pause_menu.h"

void pause_menu_draw(game_t *game, pause_menu_t *pause_menu)
{
    game_draw(game);
    button_draw(game->win, pause_menu->quit);
}