/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draws the text of an npc to the screen
*/

#include "npc.h"
#include "my.h"

static text_t *init_text(font_t *font);
static rect_t *init_text_box(void);
static void draw_npc_name(window_t *win, text_t *text, rect_t *text_box,
                            char *npc_name);
static void draw_npc_text(window_t *win, text_t *text, rect_t *text_box,
                            char **npc_text);

void npc_draw_text(window_t *win, npc_t *npc, font_t *font)
{
    text_t *text = NULL;
    rect_t *text_box = NULL;

    text = init_text(font);
    text_box = init_text_box();
    if (text == NULL || text_box == NULL)
        return;
    draw_npc_text(win, text, text_box, npc->text);
    draw_npc_name(win, text, text_box, npc->name);
    sfText_destroy(text);
    sfRectangleShape_destroy(text_box);
}

static text_t *init_text(font_t *font)
{
    text_t *text = NULL;

    text = sfText_create();
    if (text == NULL) {
        my_puterr("Couldn't allocate memory for text of npc_draw_text\n");
        return (NULL);
    }
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 2.0);
    return (text);
}

static rect_t *init_text_box(void)
{
    rect_t *text_box = NULL;

    text_box = sfRectangleShape_create();
    if (text_box == NULL) {
        my_puterr("Couldn't allocate memory for text box of npc_draw_text\n");
        return (NULL);
    }
    sfRectangleShape_setFillColor(text_box, RGBA(0, 0, 0, 125));
    sfRectangleShape_setOutlineColor(text_box, sfBlack);
    sfRectangleShape_setOutlineThickness(text_box, 2.0);
    return (text_box);
}

static void draw_npc_name(window_t *win, text_t *text, rect_t *text_box,
                            char *npc_name)
{
    v2u win_size = v2u(0, 0);
    v2f vec = v2f(0.0, 0.0);
    frect text_bounds = frect(0.0, 0.0, 0.0, 0.0);

    win_size = sfRenderWindow_getSize(win);
    text_bounds = sfText_getGlobalBounds(text);
    vec.y = win_size.y * 2 / 3 - text_bounds.height - NPC_NAME_OFFSET;
    sfRectangleShape_setPosition(text_box, vec);
    vec = v2f(NPC_NAME_OFFSET, vec.y - NPC_NAME_OFFSET);
    sfText_setPosition(text, vec);
    vec.x = text_bounds.width + NPC_NAME_OFFSET;
    vec.y = text_bounds.height + NPC_NAME_OFFSET;
    sfRectangleShape_setSize(text_box, vec);
    sfText_setString(text, npc_name);
    sfRenderWindow_drawRectangleShape(win, text_box, NULL);
    sfRenderWindow_drawText(win, text, NULL);
}

static void draw_npc_text(window_t *win, text_t *text, rect_t *text_box,
                            char **npc_text)
{
    v2u win_size = v2u(0, 0);
    v2f vec = v2f(0.0, 0.0);
    v2f offset = v2f(0.0, 0.0);

    win_size = sfRenderWindow_getSize(win);
    vec = v2f(0.0, win_size.y * 2 / 3);
    sfRectangleShape_setPosition(text_box, vec);
    sfRectangleShape_setSize(text_box, v2f(win_size.x, win_size.y / 3));
    sfRenderWindow_drawRectangleShape(win, text_box, NULL);
    vec.x = win_size.x / 20;
    offset = v2f(0.0, (win_size.y - vec.y) / 3);
    sfText_setPosition(text, vec);
    for (uint i = 0 ; npc_text[i] ; i++) {
        sfText_setString(text, npc_text[i]);
        sfRenderWindow_drawText(win, text, NULL);
        sfText_move(text, offset);
    }
}