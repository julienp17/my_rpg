/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start_menu_run
*/

#include "game.h"
#include "start_menu.h"

void start_menu_run(game_t *game)
{
    start_menu_t *start_menu = NULL;

    start_menu = start_menu_create();
    if (start_menu == NULL)
        return;
    start_menu_load(start_menu, FONT("apple_kid"));
    while (game->state == START_MENU)
        start_menu_loop(game, start_menu);
    start_menu_destroy(start_menu);
}