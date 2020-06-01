/*
** EPITECH PROJECT, 2020
** serveur
** File description:
** server
*/

// add .h

#include "server.h"
#include "client.h"

// init server's socket

static int init_server(int port)
{
    int opt = 1;
    struct sockaddr_in sin;
    int socket = create_socket();

    if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR,
    (char *)&opt, sizeof(opt)) < 0)
        error("Error - setsockopt()");
    sin = socket_configuration(port);
    if (bind(socket, (struct sockaddr *)&sin, sizeof(sin)) < 0)
        error("Error - bind()");
    waiting_conection(socket);
    return socket;
}

void main_loop_server(int port)
{
    client_t *list_clients = NULL;
    int server = init_server(port);
    int h_socket = 0;
    fd_set readfs;

    for (;;) {
        set_fd_server(&readfs, server, &h_socket);
        set_fd_client(list_clients, &readfs, &h_socket);
        if (select(h_socket + 1, &readfs, NULL, NULL, NULL) < 0)
            error("Error - select()");
        if (FD_ISSET(server, &readfs))
            add_new_client(server, &list_clients);
        manage_clients(&list_clients, &readfs);
    }
    close(server);
}
