/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Return a structure containing all the assets of the game
*/

#include <stdlib.h>
#include "assets.h"
#include "my.h"

int assets_load(assets_t *assets)
{
    int (*load_funcs[])(assets_t *) = {
        assets_load_fonts, assets_load_music, NULL
    };

    for (uint i = 0 ; load_funcs[i] ; i++)
        if (load_funcs[i](assets) < 0)
            return (-1);
    return (0);
}