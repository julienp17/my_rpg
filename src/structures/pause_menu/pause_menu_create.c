/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu_create
*/

#include <stdlib.h>
#include "pause_menu.h"
#include "my.h"

pause_menu_t *pause_menu_create(void)
{
    pause_menu_t *pause_menu = NULL;

    pause_menu = malloc(sizeof(pause_menu_t));
    if (pause_menu == NULL) {
        my_puterr("Couldn't allocate memory for pause_menu structure.\n");
        return (NULL);
    }
    pause_menu->quit = button_create();
    if (pause_menu->quit == NULL)
        return (NULL);
    return (pause_menu);
}