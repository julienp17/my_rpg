/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Destroy an warp structure
*/

#include <stdlib.h>
#include "warp.h"

void warp_destroy(warp_t *warp)
{
    free(warp->map_name);
    free(warp);
}