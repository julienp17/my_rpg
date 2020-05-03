/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** start_menu_draw
*/

#include "game.h"
#include "start_menu.h"

static void draw_circles(window_t *win, start_menu_t *start_menu);
static void draw_something_weird(window_t *win, shader_t *shader);
static void draw_particles(window_t *win, start_menu_t *start_menu);

void start_menu_draw(window_t *win, start_menu_t *start_menu)
{
    draw_circles(win, start_menu);
    draw_something_weird(win, start_menu->shader);
    button_draw(win, start_menu->start);
    button_draw(win, start_menu->commands);
    button_draw(win, start_menu->quit);
    sfRenderWindow_drawText(win, start_menu->game_name, NULL);
    draw_particles(win, start_menu);
}

static void draw_circles(window_t *win, start_menu_t *start_menu)
{
    for (uint i = 0 ; start_menu->circles[i] ; i++)
        sfRenderWindow_drawCircleShape(win, start_menu->circles[i], NULL);
}

static void draw_something_weird(window_t *win, shader_t *shader)
{
    sfRenderStates states;
    sfTexture *texture = NULL;
    sfSprite *sprite = NULL;
    v2u win_size = v2u(0, 0);

    win_size = sfRenderWindow_getSize(win);
    texture = sfTexture_create(win_size.x, win_size.y);
    if (texture == NULL)
        return;
    sfTexture_updateFromRenderWindow(texture, win, 0, 0);
    sfRenderWindow_clear(win, sfBlack);
    sprite = sfSprite_create();
    if (sprite == NULL)
        return;
    sfSprite_setTexture(sprite, texture, sfTrue);
    states.blendMode = sfBlendAlpha;
    states.shader = shader;
    states.transform = sfTransform_Identity;
    states.texture = texture;
    sfRenderWindow_drawSprite(win, sprite, &states);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

static void draw_particles(window_t *win, start_menu_t *start_menu)
{
    sfRenderStates states;

    states.blendMode = sfBlendAlpha;
    states.shader = NULL;
    states.transform = sfTransform_Identity;
    states.texture = NULL;
    sfRenderWindow_drawVertexArray(win, start_menu->vertices, &states);
}