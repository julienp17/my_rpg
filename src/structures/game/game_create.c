/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Create a Game structure
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "game.h"
#include "my.h"

game_t *game_create(void)
{
    game_t *game = NULL;

    game = malloc(sizeof(game_t));
    if (game == NULL) {
        my_puterr("Couldn't allocate memory for game structure.\n");
        return (NULL);
    }
    game->win = window_create(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
    if (game->win == NULL)
        return (NULL);
    game->assets = assets_create();
    game->player = player_create();
    game->map    = map_create();
    game->view   = sfView_create();
    game->clock  = sfClock_create();
    game->state  = START_MENU;
    return (game);
}