/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include <SFML/Graphics.h>
    #include "graphical_def.h"
    #include "assets.h"
    #include "map.h"
    #include "player.h"

    typedef struct game {
        assets_t *assets;
        map_t *map;
        player_t *player;
        view_t *view;
        gclock_t *clock;
        window_t *win;
    } game_t;

    game_t *game_create(window_t *win);
    int game_load(game_t *game);
    void game_destroy(game_t *game);

    void game_poll_events(game_t *game);
    void game_draw(game_t *game);
    void game_update(game_t *game, int delta_time);
    void game_update_view(game_t *game);
#endif