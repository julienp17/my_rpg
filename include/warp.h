/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Warp structure
*/

#ifndef WARP_H_
    #define WARP_H_

    #include "graphical_def.h"

    typedef struct warp {
        char *map_name;
        frect zone;
        v2f dest;
    } warp_t;

    warp_t *warp_create(void);
    void warp_destroy(warp_t *warp);
    int warp_load(warp_t *warp, char const *filename);
#endif