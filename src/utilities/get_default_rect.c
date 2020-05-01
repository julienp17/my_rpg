/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns a defined default rectangle
*/

#include "graphical_def.h"

rect_t *get_default_rect(v2f pos, v2f size)
{
    rect_t *rect = NULL;

    rect = sfRectangleShape_create();
    if (rect == NULL)
        return (NULL);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, TRANSPARENT_GREY);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, 2.0f);
    return (rect);
}