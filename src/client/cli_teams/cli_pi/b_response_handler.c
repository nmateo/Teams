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

int print_conv(cli_ctrl_t *ctrl, char **toks)
{
    time_t timestamp = 0;
    char *userid = NULL;
    char *msg = NULL;
    (void)(ctrl);
    for (size_t i = 1, idx = 0; toks[i] != NULL; i++) {
        switch (idx) {
            case 0: userid = strdup(toks[i]);
                    break;
            case 1: timestamp = (time_t)strtol(toks[i], NULL, 10);
                    break;
            case 2: msg = strdup(toks[i]);
                    (userid != NULL && msg != NULL) ? \
                    client_private_message_print_messages \
                    (userid, timestamp, msg):0;
                    idx = -1;
                    break;
            default: break;
        }
        idx++;
    }
    return (0);
}

int unknown_team(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL)
        return (-1);
    client_error_unknown_team(toks[1]);
    return (0);
}

int unknown_channel(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL)
        return (-1);
    client_error_unknown_channel(toks[1]);
    return (0);
}

int unknown_thread(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL)
        return (-1);
    client_error_unknown_thread(toks[1]);
    return (0);
}

int unknown_user(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL)
        return (-1);
    client_error_unknown_user(toks[1]);
    return (0);
}
