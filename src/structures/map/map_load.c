/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Load a map from a file
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "map.h"
#include "my.h"

static int fill_map(sfVertexArray *map, tile_t **tiles, sfTexture *tileset);
static int append_tile(sfVertexArray *map, v2u pos, v2i tile);

sfVertexArray *map_load(tile_t **tiles, sfTexture *tileset)
{
    sfVertexArray *map = NULL;

    map = sfVertexArray_create();
    if (map == NULL) {
        my_puterr("Couldn't allocate memory for map.\n");
        return (false);
    }
    sfVertexArray_setPrimitiveType(map, sfQuads);
    if (fill_map(map, tiles, tileset) < 0)
        return (NULL);
    return (map);
}

static int fill_map(sfVertexArray *map, tile_t **tiles, sfTexture *tileset)
{
    int tile_number = 0;
    v2u map_pos;
    v2i tileset_pos;
    v2u texture_size;

    texture_size = sfTexture_getSize(tileset);
    for (uint row = 0 ; row < NB_TILES ; row++) {
        map_pos.y = row;
        for (uint col = 0 ; col < NB_TILES ; col++) {
            map_pos.x = col;
            tile_number = tiles[row][col];
            tileset_pos.x = tile_number % (texture_size.x / TILE_SIZE);
            tileset_pos.y = tile_number / (texture_size.x / TILE_SIZE);
            if (append_tile(map, map_pos, tileset_pos) == -1)
                return (-1);
        }
    }
    return (0);
}

static int append_tile(sfVertexArray *map, v2u pos, v2i tile)
{
    sfVertex *qs = malloc(sizeof(sfVertex) * 4);

    if (qs == NULL) {
        my_puterr("Couldn't allocate memory for quads.\n");
        return (-1);
    }
    qs[0].position  = v2f(pos.x * TILE_SIZE, pos.y * TILE_SIZE);
    qs[0].texCoords = v2f(tile.x * TILE_SIZE, tile.y * TILE_SIZE);
    qs[1].position  = v2f(pos.x * TILE_SIZE, (pos.y + 1) * TILE_SIZE);
    qs[1].texCoords = v2f(tile.x * TILE_SIZE, (tile.y + 1) * TILE_SIZE);
    qs[2].position  = v2f((pos.x + 1) * TILE_SIZE, (pos.y + 1) * TILE_SIZE);
    qs[2].texCoords = v2f((tile.x + 1) * TILE_SIZE, (tile.y + 1) * TILE_SIZE);
    qs[3].position  = v2f((pos.x + 1) * TILE_SIZE, pos.y * TILE_SIZE);
    qs[3].texCoords = v2f((tile.x + 1) * TILE_SIZE, tile.y * TILE_SIZE);
    for (uint i = 0 ; i < 4 ; i++) {
        qs[i].color = sfWhite;
        sfVertexArray_append(map, qs[i]);
    }
    free(qs);
    return (0);
}