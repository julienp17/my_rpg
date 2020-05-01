/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start_menu_destroy
*/

#include <stdlib.h>
#include "start_menu.h"

void start_menu_destroy(start_menu_t *start_menu)
{
    button_destroy(start_menu->start);
    button_destroy(start_menu->quit);
    free(start_menu);
}