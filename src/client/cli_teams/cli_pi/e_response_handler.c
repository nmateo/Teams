/*
** EPITECH PROJECT, 2017
** my_ftp
** File description:
** header
*/

#include "cli.h"
#include <string.h>
#include <stdio.h>
#include "logging_client.h"
#include <stdlib.h>

int reply_created(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL || toks[2] == NULL || toks[3] == NULL || \
            toks[4] == NULL)
        return (-1);
    client_print_reply_created(toks[1], toks[2], \
            (time_t)strtol(toks[3], NULL, 10), toks[4]);
    return (0);
}

int print_sub(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    (void)(toks);
    return (0);
}

int print_unsub(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    (void)(toks);
    return (0);
}
