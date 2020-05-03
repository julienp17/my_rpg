/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_update
*/

#include "button.h"

static void update_button_state(window_t *win, button_t *button);
static void apply_changes(button_t *button);

void button_update(window_t *win, button_t *button)
{
    update_button_state(win, button);
    apply_changes(button);
}

static void update_button_state(window_t *win, button_t *button)
{
    frect bounds = frect(0.0f, 0.0f, 0.0f, 0.0f);
    v2i mouse_pos = v2i(0, 0);

    bounds = sfRectangleShape_getGlobalBounds(button->shape);
    mouse_pos = sfMouse_getPositionRenderWindow(win);
    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
        button->is_hovered = true;
        button->is_pressed = sfMouse_isButtonPressed(sfMouseLeft);
    } else {
        button->is_hovered = false;
    }
}

static void apply_changes(button_t *button)
{
    sfColor outline_color = sfTransparent;
    float outline_thickness = 0.0f;

    outline_color = (button->is_hovered) ? ORANGE_WEIRD : sfBlack;
    outline_thickness = (button->is_hovered) ? 4.0f : 2.0f;
    sfRectangleShape_setOutlineColor(button->shape, outline_color);
    sfRectangleShape_setOutlineThickness(button->shape, outline_thickness);
}