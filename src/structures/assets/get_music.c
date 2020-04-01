/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns a music from an assets structure
*/

#include "assets.h"

music_t *get_music(assets_t *assets, char const *key)
{
    return (dict_get(assets->music, key));
}