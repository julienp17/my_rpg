/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns an allocated button structure with initialized fields
*/

#include <stdlib.h>
#include "button.h"
#include "my.h"

button_t *button_create(void)
{
    button_t *button = NULL;

    button = malloc(sizeof(button_t));
    if (button == NULL) {
        my_puterr("Couldn't allocate memory for button structure.\n");
        return (NULL);
    }
    button->shape = sfRectangleShape_create();
    if (button->shape == NULL) {
        my_puterr("Couldn't allocate memory for button shape.\n");
        return (NULL);
    }
    button->text = sfText_create();
    if (button->text == NULL) {
        my_puterr("Couldn't allocate memory for button text.\n");
        return (NULL);
    }
    button->is_hovered = false;
    button->is_pressed = false;
    return (button);
}