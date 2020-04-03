/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Loads a map from a map CSV file and a tileset
*/

#include <stdlib.h>
#include "map.h"
#include "my.h"

static int load_tileset(map_t *map, char const *tileset_path);
static int load_vertices(map_t *map, char const *map_name);
static int load_collisions(map_t *map, char const *map_name);

int map_load(map_t *map, char const *map_name, char const *tileset_path)
{
    sfFloatRect map_bounds;

    if (load_tileset(map, tileset_path) < 0)
        return (-1);
    if (load_vertices(map, map_name) < 0)
        return (-1);
    if (load_collisions(map, map_name) < 0)
        return (-1);
    map_bounds = sfVertexArray_getBounds(map->bottom);
    map->size = v2f(map_bounds.width, map_bounds.height);
    return (0);
}

static int load_tileset(map_t *map, char const *tileset_path)
{
    if (map->tileset != NULL)
        sfTexture_destroy(map->tileset);
    map->tileset = sfTexture_createFromFile(tileset_path, NULL);
    if (map->tileset == NULL) {
        my_puterr("Couldn't load map tileset.\n");
        return (-1);
    }
    return (0);
}

static int load_vertices(map_t *map, char const *map_name)
{
    char *map_path = NULL;

    if (map->bottom != NULL)
        sfVertexArray_destroy(map->bottom);
    if (map->top != NULL)
        sfVertexArray_destroy(map->top);
    map_path = my_sdup(3, MAP_DIR_PATH, map_name, "_bottom.csv");
    map->bottom = vertices_load(map_path, map->tileset);
    free(map_path);
    map_path = my_sdup(3, MAP_DIR_PATH, map_name, "_top.csv");
    map->top = vertices_load(map_path, map->tileset);
    free(map_path);
    if (map->bottom == NULL)
        return (-1);
    return (0);
}

static int load_collisions(map_t *map, char const *map_name)
{
    char *map_path = NULL;

    map_path = my_sdup(3, MAP_DIR_PATH, map_name, "_collision.csv");
    map->collisions = tiles_load(map_path);
    if (map->collisions == NULL)
        return (-1);
    free(map_path);
    return (0);
}