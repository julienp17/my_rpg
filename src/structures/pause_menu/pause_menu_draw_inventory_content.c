/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu_draw_inventory_value
*/

#include <stdlib.h>
#include "pause_menu.h"
#include "my.h"

static void draw_items_name(window_t *win, frect bounds, font_t *font);
static void draw_items_value(window_t *win, frect bounds, stats_t *stats,
                            font_t *font);
static void draw_each_value(window_t *win, frect bounds, text_t *text,
                            stats_t *stats);
static void draw_value(window_t *win, text_t *text, char *label, int value);
// static void draw_stats_value(window_t *win, frect bounds, stats_t *stats,
//                             font_t *font);

void pause_menu_draw_inventory_content(window_t *win, frect bounds,
                                        stats_t *stats, font_t *font)
{
    draw_items_name(win, bounds, font);
    draw_items_value(win, bounds, stats, font);
    // draw_stats_value(win, bounds, stats, font);
    // draw_xp_bar(win, bounds, stats->xp);
}

static void draw_items_name(window_t *win, frect bounds, font_t *font)
{
    text_t *text = NULL;
    frect text_rect = frect(0.0f, 0.0f, 0.0f, 0.0f);
    char const *items_name[] = {"Red hat", "Striped shirt",
        "Louis Vitton Jeans", "Claquette Chaussette", "Pocket knife", NULL
    };

    text_rect = bounds;
    text_rect.width /= 2.0f;
    text_rect.height /= 2.0f;
    text_rect.top -= text_rect.height / 4.0f;
    text = get_default_text(text_rect, "", font);
    if (text == NULL)
        return;
    for (int i = 0 ; items_name[i] ; i++) {
        sfText_setString(text, items_name[i]);
        sfRenderWindow_drawText(win, text, NULL);
        sfText_move(text, v2f(0.0f, bounds.height));
    }
    sfText_destroy(text);
}

static void draw_items_value(window_t *win, frect bounds, stats_t *stats,
                            font_t *font)
{
    text_t *text = NULL;
    frect text_rect = frect(0.0f, 0.0f, 0.0f, 0.0f);

    text_rect = bounds;
    text_rect.width /= 2.0f;
    text_rect.height /= 2.0f;
    text_rect.top += text_rect.height / 2.0f;
    text = get_default_text(text_rect, "", font);
    if (text == NULL)
        return;
    draw_each_value(win, bounds, text, stats);
    sfText_destroy(text);
}

static void draw_each_value(window_t *win, frect bounds, text_t *text,
                            stats_t *stats)
{
    int items_value[5][STATS_NB_FIELDS] = {
        {1, 0, 0, 4, 0},
        {3, 0, 0, 6, 0},
        {2, 0, 0, 4, 0},
        {0, 2, 0, 3, 0},
        {0, 0, 4, 0, 0}
    };
    frect text_bounds = frect(0.0f, 0.0f, 0.0f, 0.0f);
    char *stat_label = NULL;

    (void) stats;
    text_bounds = sfText_getGlobalBounds(text);
    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < STATS_NB_FIELDS ; j++) {
            stat_label = stats_get_str_by_enum(j);
            draw_value(win, text, stat_label, items_value[i][j]);
            if (i == 3 && j == STATS_NB_FIELDS - 1) {
                stat_label = my_strdup("Style");
                draw_value(win, text, stat_label, -3);
            }
            free(stat_label);
        }
        sfText_setPosition(text, v2f(text_bounds.left, bounds.height *(i + 2)));
    }
}

static void draw_value(window_t *win, text_t *text, char *label, int value)
{
    char *str = NULL;
    frect text_bounds = frect(0.0f, 0.0f, 0.0f, 0.0f);

    if (value == 0)
        return;
    str = my_int_to_strnum(value);
    if (value < 0) {
        sfText_setFillColor(text, sfRed);
    } else {
        str = my_strdupcat("+", str);
        sfText_setFillColor(text, sfGreen);
    }
    str = my_strdupcat(str, my_strdupcat(" ", label));
    sfText_setString(text, str);
    text_bounds = sfText_getGlobalBounds(text);
    sfRenderWindow_drawText(win, text, NULL);
    sfText_move(text, v2f(text_bounds.width + 20.0f, 0.0f));
    free(str);
}