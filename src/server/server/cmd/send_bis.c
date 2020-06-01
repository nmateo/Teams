/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** send_bis
*/

#include "cli.h"
#include "server.h"

static char *set_line(char *uuid, char *uuid_conv)
{
    char *ret = NULL;
    char *sep = ";";
    char *conv = "conv";

    ret = concat(conv, sep);
    ret = concat(ret, uuid);
    ret = concat(ret, sep);
    ret = concat(ret, uuid_conv);
    return (ret);
}

void add_conv(client_t *client, char *uuid, char *uuid_conv)
{
    create_file(concat("./data/conv/", uuid_conv));
    add_line_at_end(concat("./data/users/", client->uuid), \
set_line(uuid, uuid_conv));
    add_line_at_end(concat("./data/users/", uuid), \
set_line(client->uuid, uuid_conv));
}

void send_error_size(client_t *client)
{
    char msg[256];

    if (client != NULL) {
        memset(msg, 0, sizeof(msg));
        sprintf(msg, "%i%s", ERROR_UNAUTHORIZED, END);
        print(client->socket, msg);
    }
}