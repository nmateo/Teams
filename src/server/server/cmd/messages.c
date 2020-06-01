/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** messages
*/

#include "cli.h"
#include "server.h"

static void send_error(client_t *client)
{
    char msg[256];

    memset(msg, 0, sizeof(msg));
    sprintf(msg, "%i%s", ERROR_UNAUTHORIZED, END);
    print(client->socket, msg);
}

static void send_data(client_t *client, char *buffer)
{
    char msg[1024];

    memset(msg, 0, sizeof(msg));
    sprintf(msg, "%i;%s%s", PRINT_CONV, buffer, END);
    print(client->socket, msg);
}

void messages(client_t **list_clients, client_t *client, char *txt)
{
    char *uuid = NULL;
    char *buffer = NULL;

    (void) list_clients;
    txt = clean_txt(txt);
    if ((uuid = get_uuid_conv(client->uuid, txt)) != NULL)
        buffer = read_file(concat(PATH_CONV, uuid));
    if (buffer == NULL) {
        send_error(client);
        return;
    }
    send_data(client, buffer);
}