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

static int load_tileset(map_t *map, char const *tileset_path);
static int load_vertices(map_t *map, char const *map_name);
static int load_objects(map_t *map, char const *map_name);
static int load_npcs(map_t *map, char const *map_name);
static int load_warps(map_t *map, char const *map_name);

int map_load(map_t *map, char const *map_name, char const *tileset_path)
{
    frect map_bounds;
    int (*load_functions[])(map_t *, char const *) = {
        &load_vertices, &load_objects, &load_npcs, &load_warps, NULL
    };

    if (load_tileset(map, tileset_path) < 0)
        return (-1);
    for (uint i = 0 ; load_functions[i] ; i++)
        if (load_functions[i](map, map_name) < 0)
            return (-1);
    map_bounds = sfVertexArray_getBounds(map->bottom);
    map->size = v2f(map_bounds.width, map_bounds.height);
    map->name = my_strdup(map_name);
    return (0);
}

static int load_tileset(map_t *map, char const *tileset_path)
{
    if (map->npc_tileset == NULL)
        map->npc_tileset = sfTexture_createFromFile(NPC_TILESET_PATH, NULL);
    if (map->npc_tileset == NULL) {
        my_puterr("Couldn't load npcs tileset.\n");
        return (-1);
    }
    if (map->map_tileset != NULL)
        sfTexture_destroy(map->map_tileset);
    map->map_tileset = sfTexture_createFromFile(tileset_path, NULL);
    if (map->map_tileset == NULL) {
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
    map_path = my_sdup(5, MAP_DIR_PATH, map_name, "/", map_name, "_bottom.csv");
    map->bottom = vertices_load(map_path, map->map_tileset);
    free(map_path);
    map_path = my_sdup(5, MAP_DIR_PATH, map_name, "/", map_name, "_top.csv");
    map->top = vertices_load(map_path, map->map_tileset);
    free(map_path);
    if (map->bottom == NULL)
        return (-1);
    return (0);
}

static int load_objects(map_t *map, char const *map_name)
{
    char *map_path = NULL;

    map_path = my_sdup(5, MAP_DIR_PATH,map_name, "/", map_name, "_objects.csv");
    map->objects = tiles_load(map_path);
    if (map->objects == NULL)
        return (-1);
    free(map_path);
    return (0);
}

static int load_npcs(map_t *map, char const *map_name)
{
    char *map_path = NULL;
    char **filenames = NULL;
    char *filename = NULL;
    unsigned int nb_npcs = 0;

    map_path = my_sdup(3, MAP_DIR_PATH, map_name, "/");
    filenames = get_filenames_ext(map_path, NPC_EXT);
    if (filenames == NULL) {
        free(map_path);
        return (0);
    }
    for (nb_npcs = 0; filenames[nb_npcs] ; nb_npcs++);
    map->npcs = malloc(sizeof(npc_t *) * (nb_npcs + 1));
    if (map->npcs == NULL) {
        my_puterr("Couldn't allocate memory for map npcs.\n");
        return (-1);
    }
    map->npcs[nb_npcs] = NULL;
    for (uint i = 0 ; filenames[i] ; i++) {
        filename = my_strdupcat(map_path, filenames[i]);
        map->npcs[i] = npc_create();
        if (map->npcs[i] == NULL)
            return (-1);
        if (npc_load(map->npcs[i], filename, map->npc_tileset) < 0)
            return (-1);
        free(filename);
    }
    free(map_path);
    my_strarr_free(filenames);
    return (0);
}

static int load_warps(map_t *map, char const *map_name)
{
    char *map_path = NULL;
    char **filenames = NULL;
    char *filename = NULL;
    unsigned int nb_warps = 0;

    map_path = my_sdup(3, MAP_DIR_PATH, map_name, "/");
    filenames = get_filenames_ext(map_path, WARP_EXT);
    if (filenames == NULL) {
        free(map_path);
        return (0);
    }
    for (nb_warps = 0; filenames[nb_warps] ; nb_warps++);
    map->warps = malloc(sizeof(warp_t *) * (nb_warps + 1));
    if (map->warps == NULL) {
        my_puterr("Couldn't allocate memory for map warps.\n");
        return (-1);
    }
    map->warps[nb_warps] = NULL;
    for (uint i = 0 ; filenames[i] ; i++) {
        filename = my_strdupcat(map_path, filenames[i]);
        map->warps[i] = warp_create();
        if (map->warps[i] == NULL)
            return (-1);
        if (warp_load(map->warps[i], filename) < 0)
            return (-1);
        free(filename);
    }
    free(map_path);
    my_strarr_free(filenames);
    return (0);
}