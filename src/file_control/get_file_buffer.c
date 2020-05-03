/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Get the file buffer
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "file_control.h"

char *get_file_buffer(char const *filepath)
{
    int fd = 0;
    unsigned int file_size = get_file_size(filepath);
    char *buffer = malloc(sizeof(char) * (file_size + 1));

    if ((fd = open(filepath, O_RDONLY)) == -1) {
        my_puterr("Couldn't open file buffer.\n");
        return (NULL);
    }
    if (read(fd, buffer, file_size) == -1) {
        my_puterr("Coudl'nt read file buffer.\n");
        return (NULL);
    }
    buffer[file_size] = '\0';
    close(fd);
    return (buffer);
}
