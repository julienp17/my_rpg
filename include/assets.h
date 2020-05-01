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

    #define FONT(font_name)       (get_font(game->assets, font_name))
    #define MUSIC(music_name)     (get_music(game->assets, music_name))

    typedef struct assets {
        dict_t *fonts;
        dict_t *music;
    } assets_t;

    assets_t *assets_create(void);
    void assets_destroy(assets_t *assets);
    int assets_load(assets_t *assets);
    int assets_load_fonts(assets_t *assets);
    int assets_load_music(assets_t *assets);

    font_t *get_font(assets_t *assets, char const *key);
    music_t *get_music(assets_t *assets, char const *key);
#endif
