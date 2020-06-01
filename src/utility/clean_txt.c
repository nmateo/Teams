/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** clean_txt
*/

#include "server.h"

static size_t get_size(char *txt)
{
    size_t i = 0;
    size_t ret = 0;

    while (txt[i] != '\0') {
        if (txt[i] != '"')
            ret++;
        i++;
    }
    return (ret);
}

char *clean_txt(char *txt)
{
    char *new = NULL;
    size_t size = get_size(txt);
    size_t i = 0;
    size_t j = 0;

    new = malloc(size + 1);
    while (txt[i] != '\0') {
        if (txt[i] != '"') {
            new[j] = txt[i];
            j++;
        }
        i++;
    }
    new[j] = '\0';
    return (new);
}