/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start_menu_load
*/

#include "start_menu.h"

void start_menu_load(start_menu_t *start_menu, font_t *font)
{
    frect rect = frect(0.0f, 0.0f, 0.0f, 0.0f);

    rect = frect(200.0f, 200.0f, 100.0f, 100.0f);
    button_load(start_menu->start, rect, "Start", font);
    rect = frect(200.0f, 400.0f, 100.0f, 100.0f);
    button_load(start_menu->quit, rect, "Quit", font);
}