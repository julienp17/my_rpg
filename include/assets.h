/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Game assets header file
*/

#ifndef ASSETS_H_
    #define ASSETS_H_

    #include "graphical_def.h"
    #include "dict.h"

    #define ASSETS_DIR            "assets/"
    #define FONTS_DIR             "fonts/"
    #define MUSIC_DIR             "music/"

    typedef struct assets {
        dict_t *fonts;
        dict_t *musics;
        dict_t *sounds;
        dict_t *tilesets;
    } assets_t;

    assets_t *assets_create(void);
    int assets_load(assets_t *assets);
    int assets_load_fonts(assets_t *assets);
    int assets_load_music(assets_t *assets);
#endif
