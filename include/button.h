/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

    #include <stdbool.h>
    #include "graphical_def.h"

    #define BUTTON_HOVER_OUTLINE_COLOR      sfYellow

    typedef struct button {
        rect_t *shape;
        text_t *text;
        bool is_pressed;
        bool is_hovered;
    } button_t;

    button_t *button_create(void);
    void button_load(button_t *button, frect, char const *text, font_t *font);
    void button_destroy(button_t *button);

    void button_draw(window_t *win, button_t *button);
    void button_update(window_t *win, button_t *button);
#endif