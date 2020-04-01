/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns a font from an assets structure
*/

#include "assets.h"

font_t *get_font(assets_t *assets, char const *key)
{
    return (dict_get(assets->fonts, key));
}