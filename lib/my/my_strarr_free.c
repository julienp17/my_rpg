/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Free an array of strings
*/

#include <stdlib.h>

void my_strarr_free(char **arr)
{
    for (int i = 0 ; arr[i] ; i++)
        free(arr[i]);
    free(arr);
}