/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** itoa
*/

#include "server.h"

char *itoa(int nb, int size)
{
    char *buffer = malloc(sizeof(char) * (size + 1));

    memset(buffer, 0, size);
    sprintf(buffer, "%d", nb);
    return (buffer);
}