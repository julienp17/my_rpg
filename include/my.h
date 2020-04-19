/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Header file for libmy
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>
    #include <stdbool.h>

    void my_puterr(char const *str);
    void my_strarr_free(char **arr);

    bool my_str_isnum(char const *str);
    bool my_str_ends(char const *str, char const *end);

    int my_atoi(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    int my_strtol(char *str, char **endptr);
    unsigned int my_strlen(char const *str);
    unsigned int my_strarr_len(char **arr);
    unsigned int my_count_char(char const *str, char const to_count);
    unsigned int my_count_until_sep(char const *str, char const sep);

    char *my_sdup(int nb_str, ...);
    char *my_strdup(char const *src);
    char *my_strdupcat(char const *s1, char const *s2);

    char **my_str_to_word_array(char const *str, char const sep);
#endif