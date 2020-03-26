/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns a newly allocated window
*/

#include "graphical_def.h"
#include "my_rpg.h"

window_t *window_create(uint width, uint height, char const *title)
{
    window_t *window = NULL;
    video_mode mode = {width, height, WIN_BPP};

    window = sfRenderWindow_create(mode, title, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, FPS_LIMIT);
    return (window);
}