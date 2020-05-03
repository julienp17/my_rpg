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
    button_destroy(pause_menu->stats);
    button_destroy(pause_menu->inventory);
    button_destroy(pause_menu->start_menu);
    button_destroy(pause_menu->quit);
    sfTexture_destroy(pause_menu->icons);
    free(pause_menu);
}