/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Destroys an assets structure
*/

#include <stdlib.h>
#include "assets.h"

void assets_destroy(assets_t *assets)
{
    dict_destroy(assets->fonts);
    dict_destroy(assets->music);
    free(assets);
}