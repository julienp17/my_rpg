/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_destroy
*/

#include <stdlib.h>
#include "button.h"

void button_destroy(button_t *button)
{
    sfRectangleShape_destroy(button->shape);
    free(button);
}