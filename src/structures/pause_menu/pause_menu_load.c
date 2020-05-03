/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu_load
*/

#include "pause_menu.h"

static void init_buttons(pause_menu_t *pause_menu, v2u win_size, font_t *font);

void pause_menu_load(pause_menu_t *pause_menu, window_t *win, font_t *font)
{
    v2u win_size = v2u(0, 0);

    win_size = sfRenderWindow_getSize(win);
    init_buttons(pause_menu, win_size, font);
}

static void init_buttons(pause_menu_t *pause_menu, v2u win_size, font_t *font)
{
    frect rect = frect(0.0f, 0.0f, 0.0f, 0.0f);

    rect.left = win_size.x / 20;
    rect.top = win_size.y / 4;
    rect.width = win_size.x / 3;
    rect.height = (win_size.y / 2) / 4;
    button_load(pause_menu->stats, rect, "Stats", font);
    rect.top += rect.height + 10;
    button_load(pause_menu->inventory, rect, "Inventory", font);
    rect.top += rect.height + 10;
    button_load(pause_menu->start_menu, rect, "Start Menu", font);
    rect.top += rect.height + 10;
    button_load(pause_menu->quit, rect, "Quit", font);
}