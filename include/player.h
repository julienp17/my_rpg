/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Header file for player structure
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include "graphical_def.h"

    #define PLAYER_TILE_SIZE        32
    #define PLAYER_TILESET_PATH     "assets/tilesets/player.png"

    typedef struct player {
        sprite_t *sprite;
        texture_t *tileset;
    } player_t;

    player_t *player_create(void);
    int player_load(player_t *player, char const *tileset_path);
    void player_destroy(player_t *player);

    void player_draw(window_t *win, player_t *player);
#endif