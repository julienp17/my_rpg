/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start_menu_create
*/

#include <stdlib.h>
#include "start_menu.h"
#include "my.h"

static int allocate_circles(start_menu_t *start_menu);

start_menu_t *start_menu_create(void)
{
    start_menu_t *start_menu = NULL;

    start_menu = malloc(sizeof(start_menu_t));
    if (start_menu == NULL) {
        my_puterr("Couldn't allocate memory for start_menu structure.\n");
        return (NULL);
    }
    start_menu->game_name = sfText_create();
    if (start_menu->game_name == NULL)
        return (NULL);
    start_menu->start = button_create();
    start_menu->quit = button_create();
    start_menu->commands = button_create();
    if (!start_menu->start || !start_menu->quit || !start_menu->commands)
        return (NULL);
    start_menu->shader = sfShader_createFromFile(NULL, NULL, SHADER_PATH);
    if (start_menu->shader == NULL)
        return (NULL);
    if (allocate_circles(start_menu) == EXIT_FAILURE)
        return (NULL);
    return (start_menu);
}

static int allocate_circles(start_menu_t *start_menu)
{
    for (uint i = 0 ; i < START_MENU_NB_CIRCLES ; i++) {
        start_menu->circles[i] = sfCircleShape_create();
        if (start_menu->circles[i] == NULL)
            return (EXIT_FAILURE);
    }
    start_menu->circles[START_MENU_NB_CIRCLES] = NULL;
    return (EXIT_SUCCESS);
}