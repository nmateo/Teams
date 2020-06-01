/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** socket
*/

#include "lib.h"

struct sockaddr_in socket_configuration(int port)
{
    struct sockaddr_in sin;

    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    return sin;
}

void waiting_conection(int socket)
{
    if (listen(socket, 5) < 0) {
        perror("Error - listen()");
        exit(84);
    }
}

int create_socket(void)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock >= 0)
        return sock;
    perror("Error - socket()");
    exit(84);
}
