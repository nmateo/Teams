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
#include <stdlib.h>
#include "logging_client.h"

int asprintf(char **strp, const char *fmt, ...);

int command_help(cli_ctrl_t *ctrl, char **toks)
{
    (void)(toks);
    (void)(ctrl);
    return (0);
}

int command_login(cli_ctrl_t *ctrl, char **toks)
{
    char *msg = "login ";

    if (toks[1] == NULL) {
        return (-1);
    }
    if ((asprintf(&msg, "%s%s", msg, toks[1])) == -1)
        exit(84);
    write_msg_socket(ctrl->control_socket, msg);
    return (0);
}

int command_logout(cli_ctrl_t *ctrl, char **toks)
{
    (void)(toks);
    write_msg_socket(ctrl->control_socket, "logout");
    return (0);
}

int command_users(cli_ctrl_t *ctrl, char **toks)
{
    (void)(toks);
    write_msg_socket(ctrl->control_socket, "users \r\n");
    return (0);
}

int command_user(cli_ctrl_t *ctrl, char **toks)
{
    char *msg = "user ";

    if (toks[1] == NULL)
        return (-1);
    asprintf(&msg, "%s%s", msg, toks[1]);
    write_msg_socket(ctrl->control_socket, msg);
    return (0);
}
