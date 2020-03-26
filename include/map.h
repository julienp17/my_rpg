/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "graphical_def.h"

    #define CSV_SEP             ','
    #define TILE_SIZE           32
    #define MAP_SIZE            1920
    #define NB_TILES            ((MAP_SIZE) / (TILE_SIZE))

    typedef int tile_t;
    typedef struct map {
        vertex_arr_t *vertices;
        texture_t *tileset;
    } map_t;

    map_t *map_create(void);
    int map_load(map_t *map, char const *map_path, texture_t *tileset);
    vertex_arr_t *vertices_load(char const *map_path, texture_t *tileset);
    tile_t **tiles_load(char const *map_path);

    void map_draw(window_t *window, map_t *map);
#endif