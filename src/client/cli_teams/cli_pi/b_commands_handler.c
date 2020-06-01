/*
** EPITECH PROJECT, 2017
** my_ftp
** File description:
** header
*/

#include "cli.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int asprintf(char **strp, const char *fmt, ...);

int command_send(cli_ctrl_t *ctrl, char **toks)
{
    char *msg = "send ";
    if (toks[1] == NULL || toks[2] == NULL)
        return (-1);
    asprintf(&msg, "%s%s", msg, toks[1]);
    asprintf(&msg, "%s %s", msg, toks[2]);
    write_msg_socket(ctrl->control_socket, msg);
    return (0);
}

int command_message(cli_ctrl_t *ctrl, char **toks)
{
    char *msg = "messages ";

    if (toks[1] == NULL)
        return (-1);
    asprintf(&msg, "%s%s", msg, toks[1]);
    write_msg_socket(ctrl->control_socket, msg);
    return (0);
}

int command_subscribe(cli_ctrl_t *ctrl, char **toks)
{
    (void)(toks);
    (void)(ctrl);
    return (0);
}

int command_subscribed(cli_ctrl_t *ctrl, char **toks)
{
    (void)(toks);
    (void)(ctrl);
    return (0);
}

int command_unsubscribe(cli_ctrl_t *ctrl, char **toks)
{
    (void)(toks);
    (void)(ctrl);
    return (0);
}
