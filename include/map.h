/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #include <stdbool.h>
    #include "graphical_def.h"

    #define MAP_DIR_PATH        "assets/maps/"
    #define CSV_SEP             ','
    #define TILE_SIZE           32
    #define MAP_SIZE            1920
    #define NB_TILES            ((MAP_SIZE) / (TILE_SIZE))

    typedef int tile_t;
    typedef sfVertexArray layer_t;

    typedef struct map {
        tileset_t *tileset;
        tile_t **collisions;
        layer_t *back;
        layer_t *top;
    } map_t;

    typedef enum layer_name {
        BACK,
        TOP
    } layer_name_t;

    map_t *map_create(void);
    int map_load(map_t *map, char const *map_path, char const *tileset_path);
    vertex_arr_t *vertices_load(char const *map_path, texture_t *tileset);
    tile_t **tiles_load(char const *map_path);
    void map_destroy(map_t *map);

    void map_draw(window_t *win, map_t *map, layer_name_t layer_name);
#endif