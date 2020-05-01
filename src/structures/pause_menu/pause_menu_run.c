/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu_run
*/

#include "game.h"
#include "pause_menu.h"

void pause_menu_run(game_t *game)
{
    pause_menu_t *pause_menu = NULL;

    pause_menu = pause_menu_create();
    if (pause_menu == NULL)
        return;
    pause_menu_load(pause_menu, FONT("apple_kid"));
    while (game->state == PAUSE_MENU)
        pause_menu_loop(game, pause_menu);
    pause_menu_destroy(pause_menu);
}