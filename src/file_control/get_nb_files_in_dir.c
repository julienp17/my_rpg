/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Returns the number of files in a directory
*/

#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include "my.h"

int get_nb_files_in_dir(char const *pathname)
{
    DIR *directory = NULL;
    struct dirent *directory_entry = NULL;
    int nb_files = 0;

    if ((directory = opendir(pathname)) == NULL) {
        my_puterr("Couldn't open directory for some reason.\n");
        return (-1);
    }
    errno = 0;
    while ((directory_entry = readdir(directory)) != NULL)
        nb_files++;
    if (directory_entry == NULL && errno != 0) {
        my_puterr("Couldn't read directory for some reason.\n");
        return (-1);
    }
    if (closedir(directory) != 0) {
        my_puterr("Couldn't close directory for some reason.\n");
        return (-1);
    }
    return (nb_files);
}