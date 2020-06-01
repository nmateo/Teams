/*
** EPITECH PROJECT, 2017
** my_ftp
** File description:
** header
*/

#include "cli.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "logging_client.h"

int event_channel_created(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL || toks[2] == NULL || toks[3] == NULL)
        return (-1);
    client_event_channel_created(toks[1], toks[2], toks[3]);
    return (0);
}

int event_thread_created(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    client_event_thread_created(toks[1], toks[2], \
            (time_t)strtol(toks[3], NULL, 10), toks[4], toks[5]);
    return (0);
}
