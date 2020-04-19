/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Header file for player structure
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include "graphical_def.h"
    #include "animation.h"
    #include "map.h"

    #define PLAYER_START_X          13
    #define PLAYER_START_Y          9
    #define PLAYER_START            PLAYER_START_X, PLAYER_START_Y
    #define PLAYER_TILE_SIZE        32
    #define PLAYER_SHEET_PATH       "assets/spritesheets/player.png"
    #define PLAYER_SHEET_ROWS       4
    #define PLAYER_SHEET_COLS       3

    typedef enum orientation {
        FRONT,
        BACK,
        LEFT,
        RIGHT,
    } orientation_t;

    typedef struct player {
        animation_t *anim;
        sprite_t *sprite;
        texture_t *tileset;
        orientation_t orientation;
    } player_t;

    player_t *player_create(void);
    int player_load(player_t *player, char const *tileset_path);
    void player_destroy(player_t *player);

    void player_draw(window_t *win, player_t *player);
    bool player_can_move(player_t *player, map_t *map, v2f offset);
    void player_move(player_t *player, v2f offset);
    void player_update(player_t *player, int delta_time);
    void player_update_animation(player_t *player);
#endif