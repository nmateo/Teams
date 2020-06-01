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

int print_thread(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL || toks[2] == NULL || toks[3] == NULL || \
            toks[4] == NULL || toks[5] == NULL)
        return (-1);
    client_channel_print_threads(toks[1], toks[2], \
            (time_t)strtol(toks[3], NULL, 10), toks[4], toks[5]);
    return (0);
}

int print_team_created(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL || toks[2] == NULL || toks[3] == NULL)
        return (-1);
    client_print_team_created(toks[1], toks[2], toks[3]);
    return (0);

}

int team_created(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL || toks[2] == NULL || toks[3] == NULL)
        return (-1);
    client_print_team_created(toks[1], toks[2], toks[3]);
    return (0);
}

int channel_created(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL || toks[2] == NULL || toks[3] == NULL)
        return (-1);
    client_print_channel_created(toks[1], toks[2], toks[3]);
    return (0);
}

int thread_created(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL || toks[2] == NULL || toks[3] == NULL || \
            toks[4] == NULL || toks[5] == NULL)
        return (-1);
    client_print_thread_created(toks[1], toks[2], \
            (time_t)strtol(toks[3], NULL, 10), toks[4], toks[5]);
    return (0);
}
