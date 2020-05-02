/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu_draw_stats
*/

#include <stdlib.h>
#include "pause_menu.h"
#include "player.h"
#include "my.h"

static void draw_boxes(window_t *win, frect bounds);

void pause_menu_draw_stats(window_t *win, pause_menu_t *pause_menu,
                            stats_t *stats, font_t *font)
{
    frect bounds = frect(0.0f, 0.0f, 0.0f, 0.0f);
    v2u win_size = v2u(0, 0);

    win_size = sfRenderWindow_getSize(win);
    bounds.left = win_size.x / 10 + win_size.x / 3;
    bounds.top = win_size.y / 4;
    bounds.width = (win_size.x - bounds.left - win_size.x / 20) / 2;
    bounds.height = (win_size.y / 2 + 30) / 3;
    draw_boxes(win, bounds);
    pause_menu_draw_stats_sprites(win, bounds, pause_menu->stats_icons);
    pause_menu_draw_stats_value(win, bounds, stats, font);
}

static void draw_boxes(window_t *win, frect bounds)
{
    rect_t *box = NULL;

    box = get_default_rect(bounds);
    sfRenderWindow_drawRectangleShape(win, box, NULL);
    sfRectangleShape_move(box, v2f(bounds.width, 0.0f));
    sfRenderWindow_drawRectangleShape(win, box, NULL);
    sfRectangleShape_move(box, v2f(0.0f, bounds.height));
    sfRenderWindow_drawRectangleShape(win, box, NULL);
    sfRectangleShape_move(box, v2f(-(bounds.width), 0.0f));
    sfRenderWindow_drawRectangleShape(win, box, NULL);
    sfRectangleShape_move(box, v2f(0.0f, bounds.height));
    sfRectangleShape_setSize(box, v2f(bounds.width * 2, bounds.height));
    sfRenderWindow_drawRectangleShape(win, box, NULL);
    sfRectangleShape_destroy(box);
}