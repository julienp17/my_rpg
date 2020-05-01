/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** start_menu_draw
*/

#include "game.h"
#include "start_menu.h"

void start_menu_draw(window_t *win, start_menu_t *start_menu)
{
    button_draw(win, start_menu->start);
    button_draw(win, start_menu->quit);
}