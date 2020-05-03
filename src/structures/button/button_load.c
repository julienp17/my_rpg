/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_load
*/

#include "button.h"

static void init_shape(button_t *button, frect rect);
static void init_text(button_t *button, char const *text, font_t *font);

void button_load(button_t *button, frect rect, char const *text, font_t *font)
{
    init_shape(button, rect);
    init_text(button, text, font);
}

static void init_shape(button_t *button, frect rect)
{
    rect_t *default_rect = NULL;

    default_rect = get_default_rect(rect);
    button->shape = sfRectangleShape_copy(default_rect);
    sfRectangleShape_destroy(default_rect);
}

static void init_text(button_t *button, char const *text, font_t *font)
{
    frect rect_bounds = frect(0.0f, 0.0f, 0.0f, 0.0f);
    text_t *default_text = NULL;

    rect_bounds = sfRectangleShape_getGlobalBounds(button->shape);
    default_text = get_default_text(rect_bounds, text, font);
    button->text = sfText_copy(default_text);
    sfText_destroy(default_text);
}