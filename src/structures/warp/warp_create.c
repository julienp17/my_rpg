/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns an allocated warp structure with initialized fields
*/

#include <stdlib.h>
#include "warp.h"
#include "my.h"

warp_t *warp_create(void)
{
    warp_t *warp = NULL;

    warp = malloc(sizeof(warp_t));
    if (warp == NULL) {
        my_puterr("Couldn't allocate memory for warp structure.\n");
        return (NULL);
    }
    warp->map_name = NULL;
    warp->zone = frect(0.0, 0.0, 0.0, 0.0);
    warp->dest = v2f(0.0, 0.0);
    return (warp);
}