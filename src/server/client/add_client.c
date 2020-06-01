/*
** EPITECH PROJECT, 2020
** serveur
** File description:
** add_client
*/

#include "server.h"

static void init_client(client_t **list_clients, int c_socket)
{
    client_t *new_client = malloc(sizeof(client_t));
    new_client->socket = c_socket;
    new_client->fp = fdopen(new_client->socket, "r");
    new_client->name = NULL;
    new_client->uuid = NULL;
    new_client->folder = 0;
    new_client->use = NULL;
    new_client->next = *list_clients;
    new_client->prev = NULL;
    if (*list_clients != NULL)
        (*list_clients)->prev = new_client;
    *list_clients = new_client;
}

void add_new_client(int server, client_t **list_clients)
{
    struct sockaddr_in c_sin;
    int size_c_sin = sizeof(c_sin);
    int c_socket = \
    accept(server, (struct sockaddr *)&c_sin, (socklen_t *) &size_c_sin);

    if (c_socket < 0)
        error("accept()");
    init_client(list_clients, c_socket);
}
