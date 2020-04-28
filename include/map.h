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
    #include "warp.h"

    #define MAP_DIR_PATH            "assets/maps/"
    #define MAP_TILESET_PATH        "assets/tilesets/map1.png"
    #define NPC_SPRITESHEET_PATH    "assets/spritesheets/npcs.png"
    #define MAP_SPACING             0
    #define NPC_EXT                 ".npc"
    #define WARP_EXT                ".warp"
    #define CSV_SEP                 ','
    #define TILE_SIZE               32
    #define TILE_ROW_END_VALUE      -84

    typedef int tile_t;
    typedef sfVertexArray layer_t;

    typedef struct map {
        char *name;
        v2f size;
        tileset_t *map_tileset;
        spritesheet_t *npc_sheet;
        tile_t **collision;
        layer_t *bottom;
        layer_t *top;
        npc_t **npcs;
        warp_t **warps;
    } map_t;

    typedef enum layer_name {
        BOTTOM,
        TOP
    } layer_name_t;

    map_t *map_create(void);
    int map_load(map_t *map, char const *map_path);
    vertex_arr_t *vertices_load(char const *map_path, texture_t *tileset);
    tile_t **tiles_load(char const *map_path);
    int map_load_npcs(map_t *map, char const *map_name);
    int map_load_warps(map_t *map, char const *map_name);
    void map_destroy(map_t *map);

    void map_update(map_t *map, float delta_time);
    void map_update_npcs(map_t *map, float delta_time);
    bool map_collided(map_t *map, v2i coords);
    void map_draw_layer(window_t *win, map_t *map, layer_name_t layer_name);
    void map_draw_npcs(window_t *win, map_t *map);
#endif