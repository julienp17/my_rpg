/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns a newly allocated window
*/

#include "game.h"

static void set_icon(window_t *win, char const *icon_path);

window_t *window_create(uint width, uint height, char const *title)
{
    window_t *win = NULL;
    video_mode mode = {width, height, WIN_BPP};

    win = sfRenderWindow_create(mode, title, sfClose | sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(win, FPS_LIMIT);
    sfRenderWindow_setVerticalSyncEnabled(win, sfTrue);
    set_icon(win, ICON_PATH);
    return (win);
}

static void set_icon(window_t *win, char const *icon_path)
{
    sfImage *icon = NULL;
    v2u icon_size = v2u(0, 0);
    sfUint8 const *pixels = NULL;

    icon = sfImage_createFromFile(icon_path);
    icon_size = sfImage_getSize(icon);
    pixels = sfImage_getPixelsPtr(icon);
    sfRenderWindow_setIcon(win, icon_size.x, icon_size.y, pixels);
    sfImage_destroy(icon);
}