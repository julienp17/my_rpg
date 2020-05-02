/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns a defined default rectangle
*/

#include "graphical_def.h"

rect_t *get_default_rect(frect bounds)
{
    rect_t *rect = NULL;
    v2f pos = v2f(0.0f, 0.0f);
    v2f size = v2f(0.0f, 0.0f);

    rect = sfRectangleShape_create();
    if (rect == NULL)
        return (NULL);
    pos = v2f(bounds.left, bounds.top);
    size = v2f(bounds.width, bounds.height);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, TRANSPARENT_GREY);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, 2.0f);
    return (rect);
}