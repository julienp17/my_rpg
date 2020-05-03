/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start_menu_create
*/

#include <stdlib.h>
#include "start_menu.h"
#include "my.h"

static int create_buttons(start_menu_t *start_menu);
static int allocate_circles(start_menu_t *start_menu);
static void allocate_particles(start_menu_t *start_menu);

start_menu_t *start_menu_create(void)
{
    start_menu_t *start_menu = NULL;

    start_menu = malloc(sizeof(start_menu_t));
    if (start_menu == NULL) {
        my_puterr("Couldn't allocate memory for start_menu structure.\n");
        return (NULL);
    }
    if (create_buttons(start_menu) == EXIT_FAILURE)
        return (NULL);
    start_menu->game_name = sfText_create();
    start_menu->shader = sfShader_createFromFile(NULL, NULL, SHADER_PATH);
    if (start_menu->game_name == NULL || start_menu->shader == NULL)
        return (NULL);
    if (allocate_circles(start_menu) == EXIT_FAILURE)
        return (NULL);
    allocate_particles(start_menu);
    start_menu->show_commands = false;
    return (start_menu);
}

static int create_buttons(start_menu_t *start_menu)
{
    start_menu->start = button_create();
    start_menu->quit = button_create();
    start_menu->commands = button_create();
    start_menu->go_back = button_create();
    if (start_menu->start == NULL || start_menu->quit == NULL)
        return (EXIT_FAILURE);
    if (start_menu->commands == NULL || start_menu->go_back == NULL)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
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

static void allocate_particles(start_menu_t *start_menu)
{
    start_menu->vertices = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(start_menu->vertices, sfPoints);
    sfVertexArray_resize(start_menu->vertices, START_MENU_NB_PARTICLES);
    for (uint i = 0 ; i < START_MENU_NB_PARTICLES ; i++)
        particle_reset(&(start_menu->particles[i]));
}