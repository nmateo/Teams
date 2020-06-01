/*
** EPITECH PROJECT, 2020
** my_ftp
** File description:
** header
*/

#include "cli.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int is_whitespaces(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ')
            return (1);
    }
    return (0);
}
