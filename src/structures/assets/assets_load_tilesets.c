/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Load the tilesets for the game assets
*/

#include <SFML/Audio.h>
#include "assets.h"
#include "my.h"
#include "file_reading.h"

int assets_load_tilesets(assets_t *assets)
{
    dict_t *tilesets = NULL;
    texture_t *tileset = NULL;
    char *dir_path = NULL;
    char *file_path = NULL;
    char **file_names = NULL;

    dir_path = my_strdupcat(ASSETS_DIR, TILESET_DIR);
    if (dir_path == NULL)
        return (-1);
    file_names = get_filenames_in_dir(dir_path);
    if (file_names == NULL)
        return (-1);
    for (unsigned int i = 0 ; file_names[i] ; i++) {
        file_path = my_strdupcat(dir_path, file_names[i]);
        tileset = sfTexture_createFromFile(file_path, NULL);
        dict_set(&tilesets, get_pretty_filename(file_names[i]),(void *)tileset);
    }
    assets->tilesets = tilesets;
    return (0);
}