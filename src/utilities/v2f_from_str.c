/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Returns a FloatVector2 from a string
*/

#include "graphical_def.h"
#include "my.h"

v2f v2f_from_str(char const *str, char const sep)
{
    v2f vector = v2f(0, 0);
    char **line_tokens = NULL;

    line_tokens = my_str_to_word_array(str, sep);
    vector.x    = my_atoi(line_tokens[0]);
    vector.y    = my_atoi(line_tokens[1]);
    my_strarr_free(line_tokens);
    return (vector);
}