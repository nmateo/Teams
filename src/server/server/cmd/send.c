/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** parse_conv_file
*/

#include "cli.h"
#include "server.h"

static client_t *get_client(client_t **list_clients, char *uuid2)
{
    client_t *current = *list_clients;

    while (current->next != NULL) {
        if (strcmp(current->uuid, uuid2) == 0)
            return (current);
        current = current->next;
    }
    if (strcmp(current->uuid, uuid2) == 0)
        return (current);
    return (NULL);
}

static char *format(char *line, char *uuid)
{
    char ret[1024];
    time_t timestamp = time(NULL);

    memset(ret, 0, sizeof(ret));
    sprintf(ret, "%s;%ld;%s", uuid, timestamp, line);
    return (strdup(ret));
}

static void send_data(client_t *client, char *uuid, char *send)
{
    char msg[256];

    if (client != NULL) {
        memset(msg, 0, sizeof(msg));
        sprintf(msg, "%i;%s;%s%s", EVENT_PRIV_MSG, uuid, send, END);
        print(client->socket, msg);
    }
}

void sendf(client_t **list_clients, client_t *client, char *txt)
{
    char *uuid = NULL;
    char *uuid_conv = NULL;
    client_t *user = NULL;

    txt = clean_txt(txt);
    uuid = strtok(txt, " ");
    txt += strlen(uuid) + 1;
    if (strlen(txt) > MAX_BODY_LENGTH)
        send_error_size(client);
    user = get_client(list_clients, uuid);
    if ((uuid_conv = get_uuid_conv(client->uuid, uuid)) == NULL) {
        uuid_conv = generate_uuid();
        add_conv(client, uuid, uuid_conv);
    }
    add_line_at_end(concat(PATH_CONV, uuid_conv), format(txt, client->uuid));
    send_data(user, client->uuid, txt);
    server_event_private_message_sended(client->uuid, uuid, txt);
}