/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns a float rectangle from a string
*/

#include "graphical_def.h"
#include "my.h"

frect frect_from_str(char const *str, char const sep)
{
    frect rect = frect(0.0, 0.0, 0.0, 0.0);
    char **line_tokens = NULL;

    line_tokens = my_str_to_word_array(str, sep);
    rect.left   = my_atoi(line_tokens[0]);
    rect.top    = my_atoi(line_tokens[1]);
    rect.width  = my_atoi(line_tokens[2]);
    rect.height = my_atoi(line_tokens[3]);
    my_strarr_free(line_tokens);
    return (rect);
}