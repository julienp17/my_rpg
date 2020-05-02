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

    #define GAME_NAME           "Mobius"
    #define ICON_PATH           "assets/icons/my_rpg_icon.png"
    #define FPS_LIMIT           60
    #define WIN_TITLE           GAME_NAME
    #define WIN_WIDTH           1920
    #define WIN_HEIGHT          1080
    #define WIN_SIZE            WIN_WIDTH, WIN_HEIGHT
    #define VIEW_WIDTH          480
    #define VIEW_HEIGHT         360
    #define VIEW_SIZE           VIEW_WIDTH, VIEW_HEIGHT

    enum game_state {
        QUIT,
        START_MENU,
        PAUSE_MENU,
        INGAME
    };

    typedef struct game {
        assets_t *assets;
        map_t *map;
        player_t *player;
        view_t *view;
        gclock_t *clock;
        window_t *win;
        enum game_state state;
    } game_t;

    window_t *window_create(uint width, uint height, char const *title);
    game_t *game_create(void);
    int game_load(game_t *game);
    void game_destroy(game_t *game);
    int game_run(game_t *game);

    void ingame_run(game_t *game);
    void ingame_poll_events(game_t *game);
    void ingame_loop(game_t *game);
    void ingame_draw(game_t *game);
    void ingame_update(game_t *game, int delta_time);
    void ingame_update_view(game_t *game);
    int  ingame_handle_warps(map_t *map, player_t *player);
#endif