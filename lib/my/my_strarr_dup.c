/*
** EPITECH PROJECT, 2019
** C Pool Day 08
** File description:
** Duplicates an array of string
*/

#include <stdlib.h>
#include "my.h"

char **my_strarr_dup(char **arr)
{
    char **dest = NULL;
    unsigned int len = 0;

    len = my_strarr_len(arr);
    dest = malloc(sizeof(char *) * (len + 1));
    if (dest == NULL) {
        my_puterr("Couldn't allocate memory for my_strarr_dup\n");
        return (NULL);
    }
    for (unsigned int i = 0 ; arr[i] ; i++)
        dest[i] = my_strdup(arr[i]);
    dest[len] = NULL;
    return (dest);
}
