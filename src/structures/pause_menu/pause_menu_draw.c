/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** pause_menu_draw
*/

#include "game.h"
#include "pause_menu.h"

void pause_menu_draw(game_t *game, pause_menu_t *pause_menu)
{
    font_t *font = NULL;

    font = FONT("apple_kid");
    ingame_draw(game);
    button_draw(game->win, pause_menu->stats);
    button_draw(game->win, pause_menu->inventory);
    button_draw(game->win, pause_menu->start_menu);
    button_draw(game->win, pause_menu->quit);
    if (pause_menu->show_stats)
        pause_menu_draw_stats(game->win, pause_menu, game->player->stats, font);
    else if (pause_menu->show_inventory)
        pause_menu_draw_inventory(game->win, pause_menu, game->player->stats, font);
}