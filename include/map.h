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
        tile_t ***tilesets;
    } map_t;

    sfVertexArray *map_load(tile_t **tiles, sfTexture *tileset);
    tile_t **tiles_load(char const *file_path);
#endif