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

int command_use(cli_ctrl_t *ctrl, char **toks)
{
    char *msg = "use";
    for (int i = 1; toks[i] != NULL && i <= 3; i++) {
        asprintf(&msg, "%s %s", msg, toks[i]);
    }
    write_msg_socket(ctrl->control_socket, msg);
    return (0);
}

int command_create(cli_ctrl_t *ctrl, char **toks)
{
    char *msg = "create ";

    if (toks[1] == NULL)
        return (-1);
    asprintf(&msg, "%s%s", msg, toks[1]);
    if (toks[2] != NULL)
        asprintf(&msg, "%s %s", msg, toks[2]);
    write_msg_socket(ctrl->control_socket, msg);
    return (0);
}

int command_list(cli_ctrl_t *ctrl, char **toks)
{
    (void)(toks);
    (void)(ctrl);
    return (0);
}

int command_info(cli_ctrl_t *ctrl, char **toks)
{
    (void)(toks);
    (void)(ctrl);
    return (0);
}
