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
    typedef sfIntRect                       irect;
    typedef sfFloatRect                     frect;
    typedef sfVideoMode                     video_mode;
    typedef sfFont                          font_t;
    typedef sfMusic                         music_t;
    typedef sfSound                         sound_t;
    typedef sfTexture                       texture_t;
    typedef sfTexture                       tileset_t;
    typedef sfTexture                       spritesheet_t;
    typedef spritesheet_t                   sheet_t;
    typedef sfVertexArray                   vertex_arr_t;
    typedef sfRenderWindow                  window_t;
    typedef sfEvent                         event_t;
    typedef sfSprite                        sprite_t;
    typedef sfView                          view_t;
    typedef sfText                          text_t;
    typedef sfClock                         gclock_t;

    #define v2i(x, y)                       ((v2i)   {(x), (y)})
    #define v2u(x, y)                       ((v2u)   {(x), (y)})
    #define v2f(x, y)                       ((v2f)   {(x), (y)})
    #define v3f(x, y)                       ((v3f)   {(x), (y)})
    #define irect(x, y, w, h)               ((irect) {(x), (y), (w), (h)})
    #define frect(x, y, w, h)               ((frect) {(x), (y), (w), (h)})
    #define RGBA(r, g, b, a)                ((sfColor_fromRGBA(r, g, b, a)))

    irect irect_from_str(char const *str, char const sep);
    frect frect_from_str(char const *str, char const sep);
    v2f v2f_from_str(char const *str, char const sep);

    void frect_multiply(frect *rect, float multiplier);
    v2f v2f_add(v2f vector1, v2f vector2);
    v2f v2f_multiply(v2f vector1, v2f vector2);
    v2i v2f_to_grid(v2f vector, int tile_size);
#endif