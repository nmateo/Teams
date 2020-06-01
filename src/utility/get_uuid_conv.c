/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** get_uuid_conv
*/

#include "server.h"

static size_t get_tab_size(char **tab)
{
    size_t ret = 0;

    for (; tab[ret] != NULL; ret++);
    return (ret);
}

static char *check_line(char *line, char *uuid2)
{
    char **tab = str_twa(line, ";");

    if (get_tab_size(tab) < 3)
        return (NULL);
    if (strcmp(tab[0], "conv") != 0)
        return (NULL);
    if (strcmp(tab[1], uuid2) != 0)
        return (NULL);
    return (tab[1]);
}

static char *found(FILE *fd, char *uuid)
{
    fclose(fd);
    uuid[strlen(uuid) - 1] = '\0';
    return (uuid);
}

char *get_uuid_conv(char *uuid1, char *uuid2)
{
    FILE *fd;
    size_t size = 0;
    char *line = NULL;
    char *uuid_conv = NULL;

    if ((fd = fopen(concat(PATH_USER, uuid1), "r")) == NULL)
        return (NULL);
    while (getline(&line, &size, fd) != -1) {
        if ((uuid_conv = check_line(line, uuid2)) != NULL)
            return (found(fd, uuid_conv));
    }
    fclose(fd);
    return (NULL);
}
