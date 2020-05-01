/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start_menu_update
*/

#include "start_menu.h"

static void update_circles(start_menu_t *start_menu, v2u win_size);

void start_menu_update(game_t *game, start_menu_t *start_menu)
{
    v2u win_size = v2u(0, 0);

    win_size = sfRenderWindow_getSize(game->win);
    update_circles(start_menu, win_size);
    button_update(game->win, start_menu->start);
    button_update(game->win, start_menu->commands);
    button_update(game->win, start_menu->quit);
    if (start_menu->start->is_pressed)
        game->state = INGAME;
    if (start_menu->quit->is_pressed)
        game->state = QUIT;
    if (game->state != START_MENU)
        sfMusic_stop(MUSIC("menu_theme"));
}

static void update_circles(start_menu_t *start_menu, v2u win_size)
{
    circle_t *circle = NULL;
    color_t color = RGBA(0, 0, 0, 0);
    v2f pos = v2f(0.0f, 0.0f);
    float radius = 0.0f;

    for (uint i = 0 ; start_menu->circles[i] ; i++) {
        circle = start_menu->circles[i];
        radius = sfCircleShape_getRadius(circle);
        color = sfCircleShape_getOutlineColor(start_menu->circles[i]);
        if (radius < 10.0f || radius > win_size.y) {
            if (color_eq(color, CIRCLE_COLOR1))
                color = CIRCLE_COLOR2;
            else
                color = CIRCLE_COLOR1;
            sfCircleShape_setOutlineColor(circle, color);
        }
        radius += (color_eq(color, CIRCLE_COLOR1) ? 0.2f : -0.2f);
        pos = v2f(win_size.x / 2 - radius, win_size.y / 2 - radius);
        sfCircleShape_setRadius(circle, radius);
        sfCircleShape_setPosition(circle, pos);
    }
}