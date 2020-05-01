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
    v2f pos = v2f(0.0f, 0.0f);
    v2f size = v2f(0.0f, 0.0f);

    pos = v2f(rect.left, rect.top);
    size = v2f(rect.width, rect.height);
    sfRectangleShape_setPosition(button->shape, pos);
    sfRectangleShape_setSize(button->shape, size);
    sfRectangleShape_setFillColor(button->shape, TRANSPARENT_GREY);
    sfRectangleShape_setOutlineColor(button->shape, sfBlack);
    sfRectangleShape_setOutlineThickness(button->shape, 2.0f);
}

static void init_text(button_t *button, char const *text, font_t *font)
{
    frect bounds = frect(0.0f, 0.0f, 0.0f, 0.0f);
    v2f pos = v2f(0.0f, 0.0f);

    sfText_setString(button->text, text);
    sfText_setFont(button->text, font);
    bounds = sfRectangleShape_getGlobalBounds(button->shape);
    pos = v2f(bounds.left + bounds.width / 4, bounds.top + bounds.height / 4);
    sfText_setPosition(button->text, pos);
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineColor(button->text, sfBlack);
    sfText_setOutlineThickness(button->text, 1.0f);
}