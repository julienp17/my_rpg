/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu
*/

#ifndef PAUSE_MENU_H_
    #define PAUSE_MENU_H_

    #include "game.h"
    #include "button.h"

    typedef struct pause_menu {
        button_t *start_menu;
        button_t *quit;
    } pause_menu_t;

    pause_menu_t *pause_menu_create(void);
    void pause_menu_load(pause_menu_t *pause_menu, font_t *font);
    void pause_menu_destroy(pause_menu_t *pause_menu);

    void pause_menu_run(game_t *game);
    void pause_menu_poll_events(game_t *game);
    void pause_menu_loop(game_t *game, pause_menu_t *pause_menu);
    void pause_menu_draw(game_t *game, pause_menu_t *pause_menu);
    void pause_menu_update(game_t *game, pause_menu_t *pause_menu);
#endif