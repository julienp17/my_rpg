/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** npc_load_from_file
*/

#include "my_rpg.h"
#include "file_reading.h"
#include "npc.h"
#include "my.h"
#include "map.h"

int npc_load(npc_t *npc, char const *pathname, tileset_t *npc_tileset)
{
    char **file_lines = NULL;
    v2f pos = v2f(0, 0);
    irect sprite_rect = irect(0, 0, 0, 0);

    file_lines = get_file_lines(pathname);
    if (file_lines == NULL)
        return (-1);
    npc->name = my_strdup(file_lines[0]);
    pos = v2f_from_str(file_lines[1], ' ');
    pos = v2f_multiply(pos, v2f(TILE_SIZE, TILE_SIZE));
    sprite_rect = irect_from_str(file_lines[2], ' ');
    sfSprite_setPosition(npc->sprite, pos);
    sfSprite_setTexture(npc->sprite, npc_tileset, sfFalse);
    sfSprite_setTextureRect(npc->sprite, sprite_rect);
    my_strarr_free(file_lines);
    return (0);
}