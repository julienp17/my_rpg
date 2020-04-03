/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Destroy an animation structure
*/

#include <stdlib.h>
#include "animation.h"

void animation_destroy(animation_t *animation)
{
    free(animation);
}