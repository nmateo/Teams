/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** concat_str
*/

#include "server.h"

char *concat(char *s1, char *s2)
{
    char *ret = malloc(sizeof(char) * strlen(s1) + strlen(s2) + 1);

    strcpy(ret, s1);
    strcat(ret, s2);
    return (ret);
}