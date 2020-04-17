/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns an allocated npc structure with initialized fields
*/

#include <stdlib.h>
#include "npc.h"
#include "my.h"

npc_t *npc_create(void)
{
    npc_t *npc = NULL;

    npc = malloc(sizeof(npc_t));
    if (npc == NULL) {
        my_puterr("Couldn't allocate memory for npc structure.\n");
        return (NULL);
    }
    npc->sprite = sfSprite_create();
    if (npc->sprite == NULL) {
        my_puterr("Couldn't allocate memory for npc sprite.\n");
        return (NULL);
    }
    npc->anim = animation_create(NPC_SWITCH_TIME);
    if (npc->anim == NULL)
        return (NULL);
    npc->name = NULL;
    npc->text = NULL;
    return (npc);
}