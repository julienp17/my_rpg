/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** particle
*/

#ifndef PARTICLE_H_
    #define PARTICLE_H_

    #include "graphical_def.h"

    #define PARTICLE_LIFETIME           3.0f

    typedef struct particle {
        v2f vel;
        sfTime lifetime;
    } particle_t;

    void particle_reset(particle_t *particle);
#endif