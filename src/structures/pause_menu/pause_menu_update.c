/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu_update
*/

#include "pause_menu.h"

void pause_menu_update(game_t *game, pause_menu_t *pause_menu)
{
    button_update(game->win, pause_menu->stats);
    button_update(game->win, pause_menu->inventory);
    button_update(game->win, pause_menu->start_menu);
    button_update(game->win, pause_menu->quit);
    if (pause_menu->stats->is_pressed)
        pause_menu->show_stats = !(pause_menu->show_stats);
    if (pause_menu->inventory->is_pressed)
        pause_menu->show_inventory = !(pause_menu->show_inventory);
    if (pause_menu->start_menu->is_pressed) {
        game->state = START_MENU;
        sfMusic_stop(MUSIC("onett"));
    }
    if (pause_menu->quit->is_pressed)
        game->state = QUIT;
}