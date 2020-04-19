/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Load the warps of a map
*/

#include <stdlib.h>
#include "map.h"
#include "my.h"
#include "file_reading.h"

static int fill_warps(map_t *map, char const *map_path, char **filenames);

int map_load_warps(map_t *map, char const *map_name)
{
    char *map_path = NULL;
    char **filenames = NULL;
    int status = 0;

    map_path = my_sdup(3, MAP_DIR_PATH, map_name, "/");
    filenames = get_filenames_ext(map_path, WARP_EXT);
    if (filenames == NULL) {
        free(map_path);
        return (EXIT_FAILURE);
    }
    status = fill_warps(map, map_path, filenames);
    free(map_path);
    my_strarr_free(filenames);
    return (status);
}

static int fill_warps(map_t *map, char const *map_path, char **filenames)
{
    char *filename = NULL;
    unsigned int nb_warps = 0;

    for (nb_warps = 0; filenames[nb_warps] ; nb_warps++);
    map->warps = malloc(sizeof(warp_t *) * (nb_warps + 1));
    if (map->warps == NULL) {
        my_puterr("Couldn't allocate memory for map warps.\n");
        return (EXIT_FAILURE);
    }
    map->warps[nb_warps] = NULL;
    for (uint i = 0 ; filenames[i] ; i++) {
        filename = my_strdupcat(map_path, filenames[i]);
        map->warps[i] = warp_create();
        if (map->warps[i] == NULL)
            return (EXIT_FAILURE);
        if (warp_load(map->warps[i], filename) < 0)
            return (EXIT_FAILURE);
        free(filename);
    }
    return (EXIT_SUCCESS);
}