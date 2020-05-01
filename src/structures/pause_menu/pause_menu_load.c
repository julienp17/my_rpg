/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu_load
*/

#include "pause_menu.h"

void pause_menu_load(pause_menu_t *pause_menu, font_t *font)
{
    frect rect = frect(0.0f, 0.0f, 0.0f, 0.0f);

    rect = frect(200.0f, 400.0f, 100.0f, 100.0f);
    button_load(pause_menu->quit, rect, "Quit", font);
}