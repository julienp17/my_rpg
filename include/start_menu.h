/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start_menu
*/

#ifndef START_MENU_H_
    #define START_MENU_H_

    #include "game.h"
    #include "button.h"

    typedef struct start_menu {
        button_t *start;
        button_t *quit;
    } start_menu_t;

    start_menu_t *start_menu_create(void);
    void start_menu_load(start_menu_t *start_menu, font_t *font);
    void start_menu_destroy(start_menu_t *start_menu);

    void start_menu_run(game_t *game);
    void start_menu_poll_events(game_t *game);
    void start_menu_loop(game_t *game, start_menu_t *start_menu);
    void start_menu_draw(window_t *win, start_menu_t *start_menu);
    void start_menu_update(game_t *game, start_menu_t *start_menu);
#endif