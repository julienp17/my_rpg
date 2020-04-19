/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_rpg header file
*/

#ifndef MY_RPG_H_
    #define MY_RPG_H_

    #include "graphical_def.h"
    #include "game.h"

    #define ICON_PATH           "assets/icons/my_rpg_icon.png"
    #define FPS_LIMIT           60
    #define WIN_TITLE           "my_rpg"
    #define WIN_WIDTH           800
    #define WIN_HEIGHT          600
    #define WIN_SIZE            WIN_WIDTH, WIN_HEIGHT
    #define VIEW_WIDTH          480
    #define VIEW_HEIGHT         360
    #define VIEW_SIZE           VIEW_WIDTH, VIEW_HEIGHT

    int my_rpg(window_t *win);
    window_t *window_create(uint width, uint height, char const *title);

    void update_view(view_t *view, player_t *player, map_t *map);

    v2f get_offset_by_key(sfKeyCode key);
    v2f sprite_get_center(sprite_t *sprite);
    void sprite_flip(sprite_t *sprite);
#endif