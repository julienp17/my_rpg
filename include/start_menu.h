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
    #include "particle.h"

    #define SHADER_PATH                     "assets/shaders/interlace.glsl"
    #define START_MENU_NB_CIRCLES           20
    #define START_MENU_NB_PARTICLES         10000
    #define CIRCLE_COLOR1                   RGB(126, 44, 32)
    #define CIRCLE_COLOR2                   RGB(125, 0, 117)
    #define GAME_NAME_COLOR                 ORANGE_WEIRD
    #define GAME_NAME_Y_FACTOR              10.8f
    #define GAME_NAME_CHAR_FACTOR           6000
    #define GAME_NAME_Y_OFFSET(win_size_y) \
        ((win_size_y) / GAME_NAME_Y_FACTOR)
    #define GAME_NAME_CHAR_OFFSET(win_size) \
        ((win_size.x * win_size.y) / GAME_NAME_CHAR_FACTOR)
    #define START_MENU_BG_IMAGE  \
        "assets/backgrounds/start_menu_bg.jpg"

    typedef struct start_menu {
        text_t *game_name;
        button_t *start;
        button_t *commands;
        button_t *quit;
        button_t *go_back;
        bool show_commands;
        circle_t *circles[START_MENU_NB_CIRCLES + 1];
        shader_t *shader;
        vertex_arr_t *vertices;
        particle_t particles[START_MENU_NB_PARTICLES];
    } start_menu_t;

    start_menu_t *start_menu_create(void);
    void start_menu_load(start_menu_t *start_menu, game_t *game);
    void start_menu_destroy(start_menu_t *start_menu);

    void start_menu_run(game_t *game);
    void start_menu_poll_events(game_t *game);
    void start_menu_loop(game_t *game, start_menu_t *start_menu);
    void start_menu_draw(window_t *win, start_menu_t *start_menu, font_t *font);
    void start_menu_draw_commands(window_t *win, font_t *font);
    void start_menu_update(game_t *game, start_menu_t *start_menu, sfTime dt);
#endif