/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu_draw_stats_value
*/

#include "pause_menu.h"
#include "my.h"

static void draw_stats_name(window_t *win, frect bounds, font_t *font);
static void draw_stats_value(window_t *win, frect bounds, stats_t *stats,
                            font_t *font);
static void draw_each_value(window_t *win, frect bounds, text_t *text,
                            stats_t *stats);
static void draw_xp_bar(window_t *win, frect bounds, int xp);

void pause_menu_draw_stats_value(window_t *win, frect bounds,
                                stats_t *stats, font_t *font)
{
    draw_stats_name(win, bounds, font);
    draw_stats_value(win, bounds, stats, font);
    draw_xp_bar(win, bounds, stats->xp);
}

static void draw_stats_name(window_t *win, frect bounds, font_t *font)
{
    text_t *text = NULL;
    frect text_rect = frect(0.0f, 0.0f, 0.0f, 0.0f);
    char const *stats_name[] = {"Mana", "Atk", "Def", "Experience", NULL};

    text_rect = bounds;
    text_rect.width /= 1.5f;
    text_rect.height /= 1.5f;
    text_rect.left += bounds.width / 3.0f;
    text = get_default_text(text_rect, "Health", font);
    if (text == NULL)
        return;
    sfRenderWindow_drawText(win, text, NULL);
    for (int i = 0 ; stats_name[i] ; i++) {
        sfText_setString(text, stats_name[i]);
        if (i % 2 == 0)
            sfText_move(text, v2f(bounds.width, 0.0f));
        else
            sfText_move(text, v2f(-bounds.width, bounds.height));
        sfRenderWindow_drawText(win, text, NULL);
    }
    sfText_destroy(text);
}

static void draw_stats_value(window_t *win, frect bounds, stats_t *stats,
                            font_t *font)
{
    text_t *text = NULL;
    frect text_rect = frect(0.0f, 0.0f, 0.0f, 0.0f);

    text_rect = bounds;
    text_rect.width /= 1.5f;
    text_rect.height /= 1.5f;
    text_rect.left += bounds.width / 3.0f;
    text_rect.top += bounds.height / 3.0f;
    text = get_default_text(text_rect, "", font);
    if (text == NULL)
        return;
    draw_each_value(win, bounds, text, stats);
    sfText_destroy(text);
}

static void draw_each_value(window_t *win, frect bounds, text_t *text,
                            stats_t *stats)
{
    int stats_value[] = {
        stats->health, stats->mana, stats->atk, stats->def, -84
    };
    char *str = NULL;

    str = my_int_to_strnum(stats->health);
    sfText_setString(text, str);
    sfRenderWindow_drawText(win, text, NULL);
    for (int i = 1 ; i < STATS_NB_FIELDS - 1 ; i++) {
        str = my_int_to_strnum(stats_value[i]);
        sfText_setString(text, str);
        if (i % 2)
            sfText_move(text, v2f(bounds.width, 0.0f));
        else
            sfText_move(text, v2f(-bounds.width, bounds.height));
        sfRenderWindow_drawText(win, text, NULL);
    }
}

static void draw_xp_bar(window_t *win, frect bounds, int xp)
{
    rect_t *bar = NULL;
    frect bar_bounds = frect(0.0f, 0.0f, 0.0f, 0.0f);

    bar_bounds = bounds;
    bar_bounds.left += bounds.width / 2.0f + bounds.width / 20.0f;
    bar_bounds.top += (bounds.height * 2.0f);
    bar_bounds.top += bounds.height / 2 + bounds.height / 20;
    bar_bounds.width = (bounds.width * 1.5f) - bounds.width / 10;
    bar_bounds.height = bounds.height / 4.0f;
    bar = get_default_rect(bar_bounds);
    if (bar == NULL)
        return;
    sfRectangleShape_setOutlineColor(bar, sfWhite);
    sfRectangleShape_setOutlineThickness(bar, 5.0f);
    sfRenderWindow_drawRectangleShape(win, bar, NULL);
    sfRectangleShape_setOutlineThickness(bar, 0.0f);
    sfRectangleShape_setFillColor(bar, sfGreen);
    bar_bounds.width = bar_bounds.width * ((float)xp / 100.0f);
    sfRectangleShape_setSize(bar, v2f(bar_bounds.width, bar_bounds.height));
    sfRenderWindow_drawRectangleShape(win, bar, NULL);
    sfRectangleShape_destroy(bar);
}