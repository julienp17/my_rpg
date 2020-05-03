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
    #include <stdbool.h>

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
    typedef sfSoundBuffer                   sound_buf_t;
    typedef sfTexture                       texture_t;
    typedef sfTexture                       tileset_t;
    typedef sfTexture                       spritesheet_t;
    typedef spritesheet_t                   sheet_t;
    typedef sfVertexArray                   vertex_arr_t;
    typedef sfVertex                        vertex_t;
    typedef sfRenderWindow                  window_t;
    typedef sfEvent                         event_t;
    typedef sfSprite                        sprite_t;
    typedef sfView                          view_t;
    typedef sfText                          text_t;
    typedef sfClock                         gclock_t;
    typedef sfRectangleShape                rect_t;
    typedef sfCircleShape                   circle_t;
    typedef sfColor                         color_t;
    typedef sfShader                        shader_t;

    #define MIN(nb1, nb2)                   ((nb1 < nb2) ? nb1 : nb2)
    #define MAX(nb1, nb2)                   ((nb1 > nb2) ? nb1 : nb2)
    #define v2i(x, y)                       (v2i)   {(x), (y)}
    #define v2u(x, y)                       (v2u)   {(x), (y)}
    #define v2f(x, y)                       (v2f)   {(x), (y)}
    #define v3f(x, y)                       (v3f)   {(x), (y)}
    #define irect(x, y, w, h)               (irect) {(x), (y), (w), (h)}
    #define frect(x, y, w, h)               (frect) {(x), (y), (w), (h)}
    #define POLL_EVENT(win, event)          sfRenderWindow_pollEvent(win, event)
    #define RGB(r, g, b)                    sfColor_fromRGB(r, g, b)
    #define RGBA(r, g, b, a)                sfColor_fromRGBA(r, g, b, a)
    #define PURPLE                          RGB(128, 0, 128)
    #define ORANGE_WEIRD                    RGB(255, 200, 100)
    #define TRANSPARENT_GREY                RGBA(0, 0, 0, 125)
    #define TEXT_CHAR_SIZE(bounds) \
        ((bounds.width * bounds.height) / 555)

    bool v2i_eq(v2i vector1, v2i vector2);
    bool color_eq(color_t color1, color_t color2);

    irect irect_from_str(char const *str, char const sep);
    frect frect_from_str(char const *str, char const sep);
    v2f v2f_from_str(char const *str, char const sep);

    void frect_multiply(frect *rect, float multiplier);
    v2i v2i_add(v2i vector1, v2i vector2);
    v2f v2f_add(v2f vector1, v2f vector2);
    v2f v2f_multiply(v2f vector1, v2f vector2);
    v2i v2f_to_grid(v2f vector);

    int rand_in_range(int min, int max);
    rect_t *get_default_rect(frect bounds);
    text_t *get_default_text(frect bounds, char const *str, font_t *font);
    v2i get_dir_by_key(sfKeyCode key);
    v2f sprite_get_center(sprite_t *sprite);
    void sprite_flip(sprite_t *sprite);
#endif