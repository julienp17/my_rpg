/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns a tileset from an assets structure
*/

#include "assets.h"

texture_t *get_tileset(assets_t *assets, char const *key)
{
    return (dict_get(assets->tilesets, key));
}