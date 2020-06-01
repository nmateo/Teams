/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** read_file
*/

#include "server.h"

char *read_file(char *filepath)
{
    struct stat *size;
    char *buff = NULL;
    int fd = 0;
    int size_map = 0;
    int tmp = 0;

    if ((fd = open(filepath, O_RDONLY)) == -1)
        return (NULL);
    if ((size = malloc(sizeof(struct stat))) == NULL)
        return (NULL);
    if (stat(filepath, size) == -1)
        return (NULL);
    size_map = size->st_size;
    buff = malloc(sizeof(char) * (size_map + 1));
    tmp = read(fd, buff, size_map);
    buff[tmp] = '\0';
    close(fd);
    free(size);
    return (buff);
}
