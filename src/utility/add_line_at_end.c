/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** add_line_at_end
*/

#include "server.h"

void add_line_at_end(char *path, char *line)
{
    FILE *file;

    file = fopen(path, "a");
    line = concat(line, "\n");
    fprintf(file, "%s", line);
    fclose(file);
}