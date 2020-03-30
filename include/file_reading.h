/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** file_reading
*/

#ifndef FILE_READING_H_
    #define FILE_READING_H_

    unsigned int get_file_size(char const *file_path);
    char *get_pretty_filename(char *ugly_filename);
    char *get_file_buffer(char const *file_path);
    char **get_file_lines(char const *file_path);

    int get_nb_files_in_dir(char const *dir_path);
    char **get_filenames_in_dir(char const *dir_path);
#endif