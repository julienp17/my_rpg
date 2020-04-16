/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** warp_load_from_file
*/

#include <stdlib.h>
#include "file_reading.h"
#include "warp.h"
#include "my.h"
#include "map.h"

int warp_load(warp_t *warp, char const *pathname)
{
    char **file_lines = NULL;

    file_lines = get_file_lines(pathname);
    if (file_lines == NULL)
        return (-1);
    warp->map_name = my_strdup(file_lines[0]);
    warp->zone = frect_from_str(file_lines[1], ' ');
    warp->dest = v2f_from_str(file_lines[2], ' ');
    frect_multiply(&(warp->zone), TILE_SIZE);
    v2f_multiply(&(warp->dest), TILE_SIZE);
    my_strarr_free(file_lines);
    return (0);
}