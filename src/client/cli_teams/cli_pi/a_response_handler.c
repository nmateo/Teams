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

int print_users(cli_ctrl_t *ctrl, char **toks)
{
    int userstat;
    char *userid = NULL;
    char *username = NULL;

    (void)(ctrl);
    for (size_t i = 1, idx = 0; toks[i] != NULL; i++) {
        switch (idx) {
            case 0: userid = strdup(toks[i]);
                break;
            case 1: username = strdup(toks[i]);
                break;
            case 2: userstat = atoi(toks[i]);
                (userid != NULL && username != NULL) ? \
                    client_print_users(userid, username, userstat): 0;
                idx = -1;
                break;
            default: break;
        }
        idx++;
    }
    return (0);
}

int print_teams(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    (void)(toks);
    return (0);
}

int print_channels(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    (void)(toks);
    return (0);
}

int print_threads(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    (void)(toks);
    return (0);
}

int print_replies(cli_ctrl_t *ctrl, char **toks)
{
    (void)(ctrl);
    (void)(toks);
    return (0);
}
