/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Return a structure containing all the assets of the game
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
    assets->fonts = assets_load_fonts();
    assets->musics = assets_load_music();
    return (assets);
}