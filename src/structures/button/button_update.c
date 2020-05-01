/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_update
*/

#include "button.h"

void button_update(window_t *win, button_t *button)
{
    frect bounds = frect(0.0f, 0.0f, 0.0f, 0.0f);
    v2i mouse_pos = v2i(0, 0);
    sfColor outline_color = sfTransparent;

    bounds = sfRectangleShape_getGlobalBounds(button->shape);
    mouse_pos = sfMouse_getPositionRenderWindow(win);
    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
        button->is_hovered = true;
        button->is_pressed = sfMouse_isButtonPressed(sfMouseLeft);
    } else {
        button->is_hovered = false;
    }
    outline_color = (button->is_hovered) ? BUTTON_HOVER_OUTLINE_COLOR : sfBlack;
    sfRectangleShape_setOutlineColor(button->shape, outline_color);
}