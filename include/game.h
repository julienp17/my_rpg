/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include <SFML/Graphics.h>
    #include "assets.h"

    typedef struct game {
        assets_t *assets;
        map_t *map;
        sfRenderWindow *window;
    } game_t;
#endif