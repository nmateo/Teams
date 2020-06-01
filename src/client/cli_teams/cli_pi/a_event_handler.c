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

int event_logged_in(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL || toks[2] == NULL)
        return (-1);
    client_event_loggedin(toks[1], toks[2]);
    return (0);
}

int event_logged_out(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL || toks[2] == NULL)
        return (-1);
    client_event_loggedout(toks[1], toks[2]);
    return (0);
}

int event_priv_msg(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL || toks[2] == NULL)
        return (-1);
    client_event_private_message_received(toks[1], toks[2]);
    return (0);
}

int event_thread_msg(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL || toks[2] == NULL \
            || toks[3] == NULL || toks[4] == NULL)
        return (-1);
    client_event_thread_message_received(toks[1], toks[2], toks[3], toks[4]);
    return (0);
}

int event_team_created(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    if (toks[1] == NULL || toks[2] == NULL || toks[3] == NULL)
        return (-1); 
    client_event_team_created(toks[1], toks[2], toks[3]);
    return (0);
}
