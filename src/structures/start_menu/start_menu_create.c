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
    if (start_menu->start == NULL || start_menu->quit == NULL)
        return (NULL);
    return (start_menu);
}