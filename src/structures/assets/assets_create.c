/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns a newly allocated assets structure
*/

#include <stdlib.h>
#include "assets.h"
#include "my.h"

assets_t *assets_create(void)
{
    assets_t *assets = NULL;

    assets = malloc(sizeof(assets_t));
    if (assets == NULL) {
        my_puterr("Couldn't allocate memory for assets structure.\n");
        return (NULL);
    }
    assets->fonts = NULL;
    assets->music = NULL;
    assets->tilesets = NULL;
    return (assets);
}