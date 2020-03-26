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

    typedef unsigned int                    uint;
    typedef unsigned char                   uchar;
    typedef sfVector2i                      v2i;
    typedef sfVector2u                      v2u;
    typedef sfVector2f                      v2f;
    typedef sfVector3f                      v3f;
    typedef sfFont                          font_t;
    typedef sfMusic                         music_t;
    typedef sfSound                         sound_t;
    typedef sfTexture                       texture_t;
    typedef sfVertexArray                   vertex_array_t;
    typedef sfRenderWindow                  window_t;

    #define v2i(x, y)           ((v2i) {(x), (y)})
    #define v2u(x, y)           ((v2u) {(x), (y)})
    #define v2f(x, y)           ((v2f) {(x), (y)})
    #define v3f(x, y)           ((v3f) {(x), (y)})
#endif