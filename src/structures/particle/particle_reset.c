/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** particle_reset
*/

#include <stdlib.h>
#include <math.h>
#include "particle.h"

void particle_reset(particle_t *particle)
{
    float angle = 0.0f;
    float speed = 0.0f;
    v2f new_vel = v2f(0.0f, 0.0f);
    sfTime new_lifetime = sfTime_Zero;

    angle = (rand() % 360) * 3.14f / 180.0f;
    speed = (rand() % 50) + 50.0f;
    new_vel = v2f(cos(angle) * speed, sin(angle) * speed);
    new_lifetime = sfMilliseconds((rand() % 2000) + 1000);
    particle->vel = new_vel;
    particle->lifetime = new_lifetime;
}