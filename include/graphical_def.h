/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Typedefs and defines to abstract SFML
*/

#ifndef GRAPHICAL_DEF_H_
    #define GRAPHICAL_DEF_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    #define WIN_BPP                         32

    typedef unsigned int                    uint;
    typedef unsigned char                   uchar;
    typedef sfVector2i                      v2i;
    typedef sfVector2u                      v2u;
    typedef sfVector2f                      v2f;
    typedef sfVector3f                      v3f;
    typedef sfVideoMode                     video_mode;
    typedef sfFont                          font_t;
    typedef sfMusic                         music_t;
    typedef sfSound                         sound_t;
    typedef sfTexture                       texture_t;
    typedef sfTexture                       tileset_t;
    typedef sfVertexArray                   vertex_arr_t;
    typedef sfRenderWindow                  window_t;
    typedef sfEvent                         event_t;
    typedef sfSprite                        sprite_t;

    #define v2i(x, y)           ((v2i) {(x), (y)})
    #define v2u(x, y)           ((v2u) {(x), (y)})
    #define v2f(x, y)           ((v2f) {(x), (y)})
    #define v3f(x, y)           ((v3f) {(x), (y)})
    #define RGBA(r, g, b, a)    ((sfColor_fromRGBA(r, g, b, a)))
#endif