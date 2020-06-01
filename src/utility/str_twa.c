/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** str_twa
*/

#include "server.h"

static int get_size(char *buffer, char *delimiter)
{
    int ret = 0;
    int buff_size = strlen(buffer);

    for (int i = 0; i < buff_size; i++)
        if (strchr(delimiter, buffer[i]) != 0)
            ret++;
    return (ret);
}

char **str_twa(char *buffer, char *delimiter)
{
    size_t size = get_size(buffer, delimiter) + 1;
    char **ret = malloc(sizeof(char *) * (size + 1));
    size_t i = 0;
    char *tmp = strtok(buffer, delimiter);

    ret[i] = tmp;
    i++;
    while (tmp != NULL && i < size) {
        tmp = strtok(NULL, delimiter);
        ret[i] = tmp;
        i++;
    }
    ret[i] = NULL;
    return (ret);
}
