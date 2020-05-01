/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Load the fonts for the game assets
*/

#include <SFML/Graphics.h>
#include "assets.h"
#include "my.h"
#include "file_control.h"

int assets_load_fonts(assets_t *assets)
{
    dict_t *fonts = NULL;
    font_t *font = NULL;
    char *dir_path = NULL;
    char *file_path = NULL;
    char **file_names = NULL;

    dir_path = my_strdupcat(ASSETS_DIR, FONTS_DIR);
    if (dir_path == NULL)
        return (-1);
    file_names = get_filenames_in_dir(dir_path);
    if (file_names == NULL)
        return (-1);
    for (unsigned int i = 0 ; file_names[i] ; i++) {
        file_path = my_strdupcat(dir_path, file_names[i]);
        font = sfFont_createFromFile(file_path);
        dict_set(&fonts, get_pretty_filename(file_names[i]), (void *) font);
    }
    assets->fonts = fonts;
    return (0);
}