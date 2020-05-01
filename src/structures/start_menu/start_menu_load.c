/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start_menu_load
*/

#include "start_menu.h"

static void init_game_name(text_t *game_name, font_t *font, v2u win_size);
static void init_buttons(start_menu_t *start_menu, v2u win_size, font_t *font);

void start_menu_load(start_menu_t *start_menu, game_t *game)
{
    v2u win_size = v2u(0, 0);

    win_size = sfRenderWindow_getSize(game->win);
    init_game_name(start_menu->game_name, FONT("apple_kid"), win_size);
    init_buttons(start_menu, win_size, FONT("apple_kid"));
}

static void init_game_name(text_t *game_name, font_t *font, v2u win_size)
{
    v2f pos = v2f(0.0f, 0.0f);
    frect text_bounds = frect(0.0f, 0.0f, 0.0f, 0.0f);
    unsigned int char_size = 0;

    sfText_setString(game_name, GAME_NAME);
    sfText_setFont(game_name, font);
    char_size = GAME_NAME_CHAR_OFFSET(win_size);
    sfText_setCharacterSize(game_name, char_size);
    text_bounds = sfText_getGlobalBounds(game_name);
    pos.x = win_size.x / 2 - text_bounds.width / 2;
    pos.y = -(text_bounds.height) + GAME_NAME_Y_OFFSET(win_size.y);
    sfText_setPosition(game_name, pos);
    sfText_setColor(game_name, GAME_NAME_COLOR);
    sfText_setOutlineColor(game_name, PURPLE);
    sfText_setOutlineThickness(game_name, 3.0f);
    sfText_setStyle(game_name, sfTextBold);
}

static void init_buttons(start_menu_t *start_menu, v2u win_size, font_t *font)
{
    frect rect = frect(0.0f, 0.0f, 0.0f, 0.0f);

    rect.left = win_size.x / 2 - win_size.x / 8;
    rect.width = win_size.x / 4;
    rect.height = win_size.y / 12;
    rect.top = QUIT_BUTTON_Y_OFFSET(win_size.y) - rect.height;
    button_load(start_menu->quit, rect, "Quit", font);
    rect.top -= win_size.y / 8;
    button_load(start_menu->commands, rect, "Commands", font);
    rect.top -= win_size.y / 8;
    button_load(start_menu->start, rect, "Start", font);
}
