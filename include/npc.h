/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Non Playable Character structure
*/

#ifndef NPC_H_
    #define NPC_H_

    #include "graphical_def.h"

    #define NPC_EXT         ".npc"

    typedef struct npc {
        char *name;
        char *text;
        sprite_t *sprite;
    } npc_t;

    npc_t *npc_create(void);
    void npc_destroy(npc_t *npc);
    int npc_load(npc_t *npc, char const *pathname, tileset_t *npc_tileset);

    void npc_draw(window_t *win, npc_t *npc);
#endif