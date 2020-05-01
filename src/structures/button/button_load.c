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
    v2f pos = v2f(0.0f, 0.0f);
    v2f size = v2f(0.0f, 0.0f);

    pos = v2f(rect.left, rect.top);
    size = v2f(rect.width, rect.height);
    default_rect = get_default_rect(pos, size);
    button->shape = sfRectangleShape_copy(default_rect);
    sfRectangleShape_destroy(default_rect);
}

static void init_text(button_t *button, char const *text, font_t *font)
{
    frect rect_bounds = frect(0.0f, 0.0f, 0.0f, 0.0f);
    frect text_bounds = frect(0.0f, 0.0f, 0.0f, 0.0f);
    v2f pos = v2f(0.0f, 0.0f);
    unsigned int char_size = 0;

    rect_bounds = sfRectangleShape_getGlobalBounds(button->shape);
    sfText_setString(button->text, text);
    sfText_setFont(button->text, font);
    char_size = rect_bounds.width * rect_bounds.height /BUTTON_CHAR_SIZE_FACTOR;
    sfText_setCharacterSize(button->text, char_size);
    text_bounds = sfText_getGlobalBounds(button->text);
    pos.x = rect_bounds.left + rect_bounds.width / 2 - text_bounds.width / 2;
    pos.y = -(text_bounds.height) + rect_bounds.top + rect_bounds.height / 4;
    sfText_setPosition(button->text, pos);
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineColor(button->text, sfBlack);
    sfText_setOutlineThickness(button->text, 1.0f);
}