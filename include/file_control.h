/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** file_reading
*/

#ifndef FILE_CONTROL_H_
    #define FILE_CONTROL_H_

    #include <sys/types.h>

    unsigned int get_file_size(char const *file_path);
    char *get_pretty_filename(char *ugly_filename);
    char *get_file_buffer(char const *file_path);
    char **get_file_lines(char const *file_path);

    int get_nb_files_in_dir(char const *dir_path);
    char **get_filenames_in_dir(char const *dir_path);
    char **get_filenames_ext(char const *dir_path, char const *ext);

    int write_to_file(char const *output_filename, void *buf, size_t buf_size);
#endif