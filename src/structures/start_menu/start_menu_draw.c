/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** start_menu_draw
*/

#include "game.h"
#include "start_menu.h"
#include <stdio.h>
static void draw_background(window_t *win, texture_t *bg);

void start_menu_draw(window_t *win, start_menu_t *start_menu)
{
    draw_background(win, start_menu->bg);
    button_draw(win, start_menu->start);
    button_draw(win, start_menu->commands);
    button_draw(win, start_menu->quit);
    sfRenderWindow_drawText(win, start_menu->game_name, NULL);
}

static void draw_background(window_t *win, texture_t *bg)
{
    sprite_t *sprite = NULL;

    sprite = sfSprite_create();
    if (sprite == NULL)
        return;
    sfSprite_setTexture(sprite, bg, sfFalse);
    sfRenderWindow_drawSprite(win, sprite, NULL);
    sfSprite_destroy(sprite);
}