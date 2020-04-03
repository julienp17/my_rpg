/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns true if its time for the animation to update, false otherwise
*/

#include <stdbool.h>
#include "animation.h"

bool animation_can_update(animation_t *animation)
{
    return (animation->elapsed >= animation->switch_time);
}