/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** [enter description here]
*/

#include "server.h"

int size_arg(int *i, char *arg)
{
    size_t size = 0;

    for (; arg[*i] != '"' && *i >= 0; *i -= 1) {
        size++;
    }
    *i += 1;
    return size;
}

char *take_arg(char *arg, int n)
{
    int nb_g = n * 2;
    int i = 0;
    size_t size = 0;
    char *buf = NULL;

    for (; arg[i] != '\0'; i++) {
        if (arg[i] == '"')
            nb_g--;
        if (nb_g == 0) {
            i--;
            break;
        }
    }
    size = size_arg(&i, arg);
    buf = malloc(sizeof(char) * size + 1);
    bzero(buf, size + 1);
    for (size_t j = 0; j < size; j++) {
        buf[j] = arg[i];
        i++;
    }
    return buf;
}
