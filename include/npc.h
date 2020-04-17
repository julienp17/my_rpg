/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Non Playable Character structure
*/

#ifndef NPC_H_
    #define NPC_H_

    #include "graphical_def.h"
    #include "animation.h"

    #define NPC_EXT                 ".npc"
    #define NPC_SWITCH_TIME         500

    typedef struct npc {
        animation_t *anim;
        char *name;
        char *text;
        sprite_t *sprite;
    } npc_t;

    npc_t *npc_create(void);
    void npc_destroy(npc_t *npc);
    int npc_load(npc_t *npc, char const *pathname, tileset_t *npc_tileset);

    void npc_draw(window_t *win, npc_t *npc);
    void npc_update(npc_t *npc, int delta_time);
    void npc_update_animation(npc_t *npc);
#endif