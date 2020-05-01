/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start_menu_create
*/

#include <stdlib.h>
#include "start_menu.h"
#include "my.h"

start_menu_t *start_menu_create(void)
{
    start_menu_t *start_menu = NULL;

    start_menu = malloc(sizeof(start_menu_t));
    if (start_menu == NULL) {
        my_puterr("Couldn't allocate memory for start_menu structure.\n");
        return (NULL);
    }
    start_menu->start = button_create();
    start_menu->quit = button_create();
    start_menu->commands = button_create();
    if (!start_menu->start || !start_menu->quit || !start_menu->commands)
        return (NULL);
    start_menu->bg = sfTexture_createFromFile(START_MENU_BG_IMAGE, NULL);
    if (start_menu->bg == NULL)
        return (NULL);
    start_menu->game_name = sfText_create();
    if (start_menu->game_name == NULL)
        return (NULL);
    return (start_menu);
}