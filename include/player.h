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

    #define PLAYER_TILE_SIZE        32
    #define PLAYER_TILESET_PATH     "assets/tilesets/player.png"
    #define PLAYER_TILESET_ROWS     4
    #define PLAYER_TILESET_COLS     3

    typedef enum orientation {
        FRONT,
        LEFT,
        RIGHT,
        BACK
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
    bool player_can_move(player_t *player, map_t *map, sfKeyCode key);
    void player_move(player_t *player, v2f offset);
    void player_update(player_t *player, int delta_time);
    void player_update_animation(player_t *player);
#endif