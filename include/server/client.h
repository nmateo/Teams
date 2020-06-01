/*
** EPITECH PROJECT, 2020
** serveur
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include "server.h"

void add_new_client(int s_socket, client_t **list_clients);
void free_client(client_t **list_clients, client_t *client);
void logout(client_t **list_clients, client_t *client);

void manage_clients(client_t **list_clients, fd_set *readfs);

void command_management(client_t **list_clients, client_t *client, char *msg);

#endif /*CLIENT_H*/
