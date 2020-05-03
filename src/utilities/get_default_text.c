/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_default_text
*/

#include "graphical_def.h"

text_t *get_default_text(frect bounds, char const *str, font_t *font)
{
    text_t *text = NULL;
    unsigned int char_size = 0;
    frect text_bounds = frect(0.0f, 0.0f, 0.0f, 0.0f);
    v2f pos = v2f(0.0f, 0.0f);

    text = sfText_create();
    if (text == NULL)
        return (NULL);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    char_size = TEXT_CHAR_SIZE(bounds);
    sfText_setCharacterSize(text, char_size);
    text_bounds = sfText_getGlobalBounds(text);
    pos.x = bounds.left + bounds.width / 2 - text_bounds.width / 2;
    pos.y = -(text_bounds.height) + bounds.top + bounds.height / 4;
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 1.0f);
    return (text);
}