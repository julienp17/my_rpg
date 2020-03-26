/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include <SFML/Graphics.h>
    #include "graphical_def.h"
    #include "assets.h"
    #include "map.h"

    typedef struct game {
        assets_t *assets;
        map_t *map;
        window_t *window;
    } game_t;
#endif