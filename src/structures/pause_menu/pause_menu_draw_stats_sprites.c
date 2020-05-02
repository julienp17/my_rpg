/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu_draw_stats_sprites
*/

#include "pause_menu.h"

static void draw_each_sprite(window_t *win, sprite_t *sprite, frect bounds);

void pause_menu_draw_stats_sprites(window_t *win, frect bounds, sheet_t *icons)
{
    sprite_t *sprite = NULL;
    v2u texture_size = v2u(0, 0);
    irect sprite_rect = irect(0, 0, 0, 0);
    v2f pos = v2f(0.0f, 0.0f);

    sprite = sfSprite_create();
    if (sprite == NULL)
        return;
    texture_size = sfTexture_getSize(icons);
    sprite_rect.width = texture_size.x;
    sprite_rect.height = texture_size.y / STATS_NB_FIELDS;
    sfSprite_setTexture(sprite, icons, sfFalse);
    sfSprite_setTextureRect(sprite, sprite_rect);
    pos.x = bounds.left + bounds.width / 20;
    pos.y = bounds.top + bounds.height / 2 - sprite_rect.height / 2;
    sfSprite_setPosition(sprite, pos);
    draw_each_sprite(win, sprite, bounds);
    sfSprite_destroy(sprite);
}

static void draw_each_sprite(window_t *win, sprite_t *sprite, frect bounds)
{
    irect sprite_rect = irect(0, 0, 0, 0);

    sprite_rect = sfSprite_getTextureRect(sprite);
    sfRenderWindow_drawSprite(win, sprite, NULL);
    for (int i = 0 ; i < STATS_NB_FIELDS ; i++) {
        sprite_rect.top += sprite_rect.height;
        sfSprite_setTextureRect(sprite, sprite_rect);
        if (i % 2 == 0)
            sfSprite_move(sprite, v2f(bounds.width, 0.0f));
        else
            sfSprite_move(sprite, v2f(-bounds.width, bounds.height));
        sfRenderWindow_drawSprite(win, sprite, NULL);
    }
}