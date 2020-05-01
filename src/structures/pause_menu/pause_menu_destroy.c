/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu_destroy
*/

#include <stdlib.h>
#include "pause_menu.h"

void pause_menu_destroy(pause_menu_t *pause_menu)
{
    button_destroy(pause_menu->quit);
    free(pause_menu);
}