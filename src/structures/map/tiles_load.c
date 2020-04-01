/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Load a map from a text file
*/

#include <stdlib.h>
#include "file_reading.h"
#include "map.h"
#include "my.h"

static tile_t **fill_tiles(tile_t **tiles, char **file_lines);

tile_t **tiles_load(char const *file_path)
{
    char **file_lines = NULL;
    tile_t **tiles = NULL;
    uint len = 0;

    file_lines = get_file_lines(file_path);
    if (file_lines == NULL)
        return (NULL);
    len = my_strarr_len(file_lines);
    tiles = malloc(sizeof(tile_t *) * (len + 1));
    if (tiles == NULL) {
        my_puterr("Couldn't allocate memory for tiles.\n");
        return (NULL);
    }
    tiles[len] = NULL;
    tiles = fill_tiles(tiles, file_lines);
    my_strarr_free(file_lines);
    return (tiles);
}

static tile_t **fill_tiles(tile_t **tiles, char **file_lines)
{
    char **str_nums = NULL;
    uint len = 0;

    for (uint i = 0 ; file_lines[i] ; i++) {
        str_nums = my_str_to_word_array(file_lines[i], CSV_SEP);
        if (str_nums == NULL)
            return (NULL);
        len = my_strarr_len(str_nums);
        tiles[i] = malloc(sizeof(tile_t) * (len + 1));
        if (tiles[i] == NULL) {
            my_puterr("Couldn't allocate memory for tiles row.\n");
            return (NULL);
        }
        tiles[i][len] = 0;
        for (uint j = 0 ; str_nums[j] ; j++)
            tiles[i][j] = my_atoi(str_nums[j]);
        my_strarr_free(str_nums);
    }
    return (tiles);
}