/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_draw
*/

#include "button.h"

void button_draw(window_t *win, button_t *button)
{
    sfRenderWindow_drawRectangleShape(win, button->shape, NULL);
    sfRenderWindow_drawText(win, button->text, NULL);
}