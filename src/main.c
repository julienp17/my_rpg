/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Main file for my_rpg
*/

#include <stddef.h>
#include "graphical_def.h"
#include "my_rpg.h"

int main(void)
{
    window_t *window = NULL;
    int status = 0;

    window = window_create(W_WIDTH, W_HEIGHT, W_TITLE);
    if (window == NULL)
        return (1);
    status = my_rpg(window);
    return (status);
}