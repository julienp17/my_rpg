/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** stats
*/

#ifndef STATS_H_
    #define STATS_H_

    #define STATS_NB_FIELDS         5

    typedef struct stats {
        int health;
        int mana;
        int atk;
        int def;
        int xp;
    } stats_t;

    stats_t *stats_create(void);
    void stats_destroy(stats_t *stats);
#endif