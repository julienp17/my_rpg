/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Main file for my_rpg
*/

#include <stddef.h>
#include "game.h"

int main(void)
{
    game_t *game = NULL;
    int status = 0;

    game = game_create();
    if (game == NULL)
        return (84);
    status = game_run(game);
    game_destroy(game);
    return (status);
}