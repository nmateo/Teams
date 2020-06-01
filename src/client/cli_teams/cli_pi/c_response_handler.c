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

int error_unauthorized(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    (void)(toks);
    client_error_unauthorized();
    return (0);
}

int already_exist(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    (void)(toks);
    client_error_already_exist();
    return (0);
}

int print_user(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL || toks[2] == NULL || toks[3] == NULL)
        return (-1);
    client_print_user(toks[1], toks[2], atoi(toks[3]));
    return (0);
}

int print_team(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL || toks[2] == NULL || toks[3] == NULL)
        return (-1);
    client_print_team(toks[1], toks[2], toks[3]);
    return (0);
}

int print_channel(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL || toks[2] == NULL || toks[3] == NULL)
        return (-1);
    client_print_channel(toks[1], toks[2], toks[3]); 
    return (0);
}
