/*
** EPITECH PROJECT, 2020
** serveur
** File description:
** set_fd
*/

#include "server.h"

void set_fd_server(fd_set *readfs, int server, int *h_socket)
{
    FD_ZERO(readfs);
    FD_SET(server, readfs);
    *h_socket = server;
}

void set_fd_client(client_t *list_clients, fd_set *readfs, int *h_socket)
{
    for (client_t *cli = list_clients; cli != NULL; cli = cli->next) {
        FD_SET(cli->socket, readfs);
        if (cli->socket > *h_socket)
            *h_socket = cli->socket;
    }
}
