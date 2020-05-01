/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** write_to_file
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int write_to_file(char const *output_filename, void *buf, size_t buf_size)
{
    int fd = 0;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int status = 0;

    fd = open(output_filename, O_CREAT | O_TRUNC | O_WRONLY, mode);
    if (fd < 0) {
        my_puterr("Error opening file.\n");
        return (EXIT_FAILURE);
    }
    if (write(fd, buf, buf_size) < 0) {
        my_puterr("Error writing file.\n");
        status = EXIT_FAILURE;
    }
    if (close(fd) < 0) {
        my_puterr("Error closing file.\n");
        status = EXIT_FAILURE;
    }
    return (status);
}