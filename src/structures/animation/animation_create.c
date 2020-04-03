/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns a newly allocated animation strucutre
*/

#include <stdlib.h>
#include "animation.h"
#include "my.h"

animation_t *animation_create(int switch_time)
{
    animation_t *animation = NULL;

    animation = malloc(sizeof(animation_t));
    if (animation == NULL) {
        my_puterr("Couldn't allocate memory for animation structure.\n");
        return (NULL);
    }
    animation->elapsed = 0;
    animation->switch_time = switch_time;
    return (animation);
}