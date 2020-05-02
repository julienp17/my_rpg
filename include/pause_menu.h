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
    #include "player.h"

    #define STATS_ICONS_PATH        "assets/spritesheets/stats_icons.png"

    typedef struct pause_menu {
        button_t *stats;
        button_t *inventory;
        button_t *start_menu;
        button_t *quit;
        bool show_stats;
        bool show_inventory;
        sheet_t *stats_icons;
    } pause_menu_t;

    pause_menu_t *pause_menu_create(void);
    void pause_menu_load(pause_menu_t *pause_menu, window_t *win, font_t *font);
    void pause_menu_destroy(pause_menu_t *pause_menu);

    void pause_menu_run(game_t *game);
    void pause_menu_poll_events(game_t *game);
    void pause_menu_loop(game_t *game, pause_menu_t *pause_menu);
    void pause_menu_draw(game_t *game, pause_menu_t *pause_menu);
    void pause_menu_draw_stats(window_t *win, pause_menu_t *pause_menu,
                                stats_t *stats, font_t *font);
    void pause_menu_draw_stats_sprites(window_t *win, frect bounds,
                                    sheet_t *icons);
    void pause_menu_draw_stats_value(window_t *win, frect bounds,
                                    stats_t *stats, font_t *font);
    void pause_menu_update(game_t *game, pause_menu_t *pause_menu);
#endif