/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Load the npcs of a map
*/

#include <stdlib.h>
#include "map.h"
#include "my.h"
#include "file_reading.h"

static int fill_npcs(map_t *map, char const *map_path, char **filenames);

int map_load_npcs(map_t *map, char const *map_name)
{
    char *map_path = NULL;
    char **filenames = NULL;
    int status = 0;

    map_path = my_sdup(3, MAP_DIR_PATH, map_name, "/");
    filenames = get_filenames_ext(map_path, NPC_EXT);
    if (filenames == NULL) {
        free(map_path);
        return (0);
    }
    status = fill_npcs(map, map_path, filenames);
    free(map_path);
    my_strarr_free(filenames);
    return (status);
}

static int fill_npcs(map_t *map, char const *map_path, char **filenames)
{
    char *filename = NULL;
    unsigned int nb_npcs = 0;

    for (nb_npcs = 0; filenames[nb_npcs] ; nb_npcs++);
    map->npcs = malloc(sizeof(npc_t *) * (nb_npcs + 1));
    if (map->npcs == NULL) {
        my_puterr("Couldn't allocate memory for map npcs.\n");
        return (EXIT_FAILURE);
    }
    map->npcs[nb_npcs] = NULL;
    for (uint i = 0 ; filenames[i] ; i++) {
        filename = my_strdupcat(map_path, filenames[i]);
        map->npcs[i] = npc_create();
        if (map->npcs[i] == NULL)
            return (EXIT_FAILURE);
        if (npc_load(map->npcs[i], filename, map->npc_sheet) < 0)
            return (EXIT_FAILURE);
        free(filename);
    }
    return (EXIT_SUCCESS);
}