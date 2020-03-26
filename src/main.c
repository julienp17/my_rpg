/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Main file for my_rpg
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include "dict.h"
#include "assets.h"
#include "map.h"

window_t *window_create(uint width, uint height, char const *title);

int main(void)
{
    window_t *win = window_create(1920, 1080, "bite");
    map_t *map = map_create();
    sfTexture *texture = sfTexture_createFromFile("assets/tilesets/tileset1.png", NULL);

    map_load(map, "assets/maps/test.csv", texture);
    (void)win;
    while (sfRenderWindow_isOpen(win)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(win, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(win);
        sfRenderWindow_clear(win, sfBlack);
        map_draw(win, map);
        sfRenderWindow_display(win);
    }
    return (0);
}