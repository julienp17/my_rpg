/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Load the musics for the game assets
*/

#include <SFML/Audio.h>
#include "assets.h"
#include "my.h"
#include "file_reading.h"

dict_t *assets_load_music(void)
{
    dict_t *musics = NULL;
    char *dir_path = NULL;
    char *file_path = NULL;
    char **file_names = NULL;
    sfMusic *music = NULL;

    dir_path = my_strdupcat(ASSETS_DIR, MUSIC_DIR);
    if (dir_path == NULL)
        return (NULL);
    file_names = get_filenames_in_dir(dir_path);
    if (file_names == NULL)
        return (NULL);
    for (unsigned int i = 0 ; file_names[i] ; i++) {
        file_path = my_strdupcat(dir_path, file_names[i]);
        music = sfMusic_createFromFile(file_path);
        dict_set(&musics, file_names[i], (void *) music);
    }
    return (musics);
}