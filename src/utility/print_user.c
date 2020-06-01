/*
** EPITECH PROJECT, 2020
** my_temas
** File description:
** print_user
*/

#include "server.h"

static void send_data(client_t *client, char *uuid, char *username, int status)
{
    char msg[256];

    memset(msg, 0, sizeof(msg));
    sprintf(msg, "%%s;%s;%d%s", uuid, username, status, END);
    print(client->socket, msg);
}

static int get_user_status(client_t **list_clients, char *uuid)
{
    for (client_t *cli = *list_clients; cli != NULL; cli = cli->next) {
        if (strcasecmp(cli->uuid, uuid) == 0)
            return 1;
    }
    return 0;
}

static char *get_user_name(char *path)
{
    FILE *fp;
    size_t size = 0;
    char *uuid = NULL;

    if ((fp = fopen(path, "r")) == NULL);
        return NULL;
    getline(&uuid, &size, fp);
    uuid[strlen(uuid) - 1] = '\0';
    fclose(fp);
    return (uuid);
}

void print_a_user(client_t **list_clients, client_t *client, char *uuid_user)
{
    char *user_name = NULL;
    int user_status = 0;

    user_name = get_user_name(concat(PATH_USER, uuid_user));
    user_status = get_user_status(list_clients, uuid_user);
    send_data(client, uuid_user, user_name, user_status);
}