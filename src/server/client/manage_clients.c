/*
** EPITECH PROJECT, 2020
** serveur
** File description:
** mange_clients
*/

#include "server.h"
#include "client.h"

void event_management(client_t **list_clients, client_t *client)
{
    char *buf = NULL;
    size_t size = 0;
    ssize_t n = 0;

    if ((n = getline(&buf, &size, client->fp)) <= 0) {
        logout(list_clients, client);
    } else if (strcmp("\r\n", buf) != 0 && buf[0] != '\n' && buf[0] != '\r')
        command_management(list_clients, client, buf);
    free(buf);
}

void manage_clients(client_t **list_clients, fd_set *readfs)
{
    client_t *cli = *list_clients;

    for (client_t *client = *list_clients; client != NULL; client = cli) {
        cli = client->next;
        if (FD_ISSET(client->socket, readfs))
            event_management(list_clients, client);
    }
}
