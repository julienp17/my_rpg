/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start_menu_draw_commands
*/

#include "start_menu.h"

static void draw_box(window_t *win, frect bounds);
static void draw_commands(window_t *win, frect bounds, font_t *font);
static void draw_text(window_t *win,frect bounds, char const *str,font_t *font);

void start_menu_draw_commands(window_t *win, font_t *font)
{
    v2u win_size = v2u(0, 0);
    frect bounds = frect(0.0f, 0.0f, 0.0f, 0.0f);

    win_size = sfRenderWindow_getSize(win);
    bounds.left = win_size.x / 6;
    bounds.top = win_size.y / 3;
    bounds.width = win_size.x - bounds.left * 2;
    bounds.height = win_size.y / 2 + win_size.y / 12;
    draw_box(win, bounds);
    draw_commands(win, bounds, font);
}

static void draw_box(window_t *win, frect bounds)
{
    rect_t *box = NULL;

    box = get_default_rect(bounds);
    if (box == NULL)
        return;
    sfRenderWindow_drawRectangleShape(win, box, NULL);
    sfRectangleShape_destroy(box);
}

static void draw_commands(window_t *win, frect bounds, font_t *font)
{
    bounds.width /= 3.0f;
    bounds.height /= 3.0f;
    bounds.left += bounds.width;
    draw_text(win, bounds, "A to run", font);
    bounds.top += bounds.height;
    draw_text(win, bounds, "E to interact", font);
    bounds.top += bounds.height;
    draw_text(win, bounds, "Directional keys to move", font);
}

static void draw_text(window_t *win,frect bounds, char const *str, font_t *font)
{
    text_t *text = NULL;

    text = get_default_text(bounds, str, font);
    if (text == NULL)
        return;
    sfRenderWindow_drawText(win, text, NULL);
}