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
    #define W_WIDTH             800
    #define W_HEIGHT            600
    #define W_TITLE             "my_rpg"
    #define VIEW_SIZE           720, 480

    int my_rpg(window_t *win);
    window_t *window_create(uint width, uint height, char const *title);

    void update_view(view_t *view, player_t *player, map_t *map);

    v2f get_offset_by_key(sfKeyCode key);
    v2f sprite_get_center(sprite_t *sprite);
#endif