/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** ingame_run
*/

#include "game.h"

void ingame_run(game_t *game)
{
    sfMusic *music = NULL;

    music = MUSIC("onett");
    if (sfMusic_getStatus(music) != sfPlaying) {
        sfMusic_setLoop(music, sfTrue);
        sfMusic_setVolume(music, 40.0f);
        sfMusic_play(music);
    }
    sfClock_restart(game->clock);
    while (game->state == INGAME)
        ingame_loop(game);
}