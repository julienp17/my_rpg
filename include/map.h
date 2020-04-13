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
    #include "npc.h"

    #define MAP_DIR_PATH            "assets/maps/"
    #define CSV_SEP                 ','
    #define TILE_SIZE               32
    #define TILE_ROW_END_VALUE      -84

    typedef int tile_t;
    typedef sfVertexArray layer_t;

    typedef enum map_object {
        COLLISION,
        NPC,
        PLAYER_SPAWN,
        ENEMY_SPAWN,
        WARP
    } mpa_object_t;

    typedef struct map {
        v2f size;
        tileset_t *map_tileset;
        tileset_t *npc_tileset;
        tile_t **objects;
        layer_t *bottom;
        layer_t *top;
        npc_t **npcs;
    } map_t;

    typedef enum layer_name {
        BOTTOM,
        TOP
    } layer_name_t;

    map_t *map_create(void);
    int map_load(map_t *map, char const *map_path, char const *tileset_path);
    vertex_arr_t *vertices_load(char const *map_path, texture_t *tileset);
    tile_t **tiles_load(char const *map_path);
    void map_destroy(map_t *map);

    bool map_collided(map_t *map, v2i coords);
    void map_draw_layer(window_t *win, map_t *map, layer_name_t layer_name);
    void map_draw_npcs(window_t *win, map_t *map);
#endif