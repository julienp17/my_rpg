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
    assets_load_fonts(assets);
    assets_load_music(assets);
    return (0);
}