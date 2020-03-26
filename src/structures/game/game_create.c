/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Create a Game structure
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "game.h"

game_t *game_create(void)
{
    game_t *game = NULL;

    game = malloc(sizeof(game_t));
    if (game == NULL) {
        my_puterr("Couldn't allocate memory for game structure.\n");
        return (NULL);
    }
    game->assets = assets_create();
    return (game);
}