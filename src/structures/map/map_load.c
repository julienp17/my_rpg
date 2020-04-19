/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Loads a map from a map CSV file and a tileset
*/

#include <stdlib.h>
#include "file_reading.h"
#include "map.h"
#include "my.h"

static int load_textures(map_t *map);
static int load_vertices(map_t *map, char const *map_name);
static int load_objects(map_t *map, char const *map_name);

int map_load(map_t *map, char const *map_name)
{
    frect map_bounds;
    int (*load_functions[])(map_t *, char const *) = {
        &load_vertices, &load_objects,
        &map_load_npcs, &map_load_warps, NULL
    };

    if (load_textures(map) != EXIT_SUCCESS)
        return (EXIT_FAILURE);
    for (uint i = 0 ; load_functions[i] ; i++)
        if (load_functions[i](map, map_name) != EXIT_SUCCESS)
            return (EXIT_FAILURE);
    map_bounds = sfVertexArray_getBounds(map->bottom);
    map->size = v2f(map_bounds.width, map_bounds.height);
    map->name = my_strdup(map_name);
    return (EXIT_SUCCESS);
}

static int load_textures(map_t *map)
{
    if (map->npc_sheet == NULL)
        map->npc_sheet = sfTexture_createFromFile(NPC_SPRITESHEET_PATH, NULL);
    if (map->npc_sheet == NULL) {
        my_puterr("Couldn't load npcs tileset.\n");
        return (EXIT_FAILURE);
    }
    if (map->map_tileset == NULL)
        map->map_tileset = sfTexture_createFromFile(MAP_TILESET_PATH, NULL);
    if (map->map_tileset == NULL) {
        my_puterr("Couldn't load map tileset.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static int load_vertices(map_t *map, char const *map_name)
{
    char *map_path = NULL;

    if (map->bottom != NULL)
        sfVertexArray_destroy(map->bottom);
    if (map->top != NULL)
        sfVertexArray_destroy(map->top);
    map_path = my_sdup(5, MAP_DIR_PATH, map_name, "/", map_name, "_bottom.csv");
    map->bottom = vertices_load(map_path, map->map_tileset);
    free(map_path);
    map_path = my_sdup(5, MAP_DIR_PATH, map_name, "/", map_name, "_top.csv");
    map->top = vertices_load(map_path, map->map_tileset);
    free(map_path);
    if (map->bottom == NULL || map->top == NULL)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static int load_objects(map_t *map, char const *map_name)
{
    char *map_path = NULL;

    map_path = my_sdup(5, MAP_DIR_PATH,map_name, "/", map_name, "_objects.csv");
    map->objects = tiles_load(map_path);
    if (map->objects == NULL)
        return (EXIT_FAILURE);
    free(map_path);
    return (EXIT_SUCCESS);
}