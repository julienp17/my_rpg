/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns an allocated stats structure with initialized fields
*/

#include <stdlib.h>
#include "stats.h"
#include "my.h"

stats_t *stats_create(void)
{
    stats_t *stats = NULL;

    stats = malloc(sizeof(stats_t));
    if (stats == NULL) {
        my_puterr("Couldn't allocate memory for stats structure.\n");
        return (NULL);
    }
    stats->health = 0;
    stats->mana = 0;
    stats->atk = 0;
    stats->def = 0;
    stats->xp = 0;
    return (stats);
}