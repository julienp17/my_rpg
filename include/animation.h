/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Animation structure
*/

#ifndef ANIMATION_H_
    #define ANIMATION_H_

    #include <stdbool.h>

    #define DEFAULT_SWITCH_TIME     0.5

    typedef struct animation {
        float elapsed;
        float switch_time;
    } animation_t;

    animation_t *animation_create(float switch_time);
    void animation_destroy(animation_t *animation);

    void animation_update(void *entity, void (*anim_func)(void *),
                        float delta_time);
    bool animation_can_update(animation_t *animation);
#endif