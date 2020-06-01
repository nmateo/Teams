/*
** EPITECH PROJECT, 2020
** serveur
** File description:
** server_h
*/

#ifndef SOCKET_H_
#define SOCKET_H_

#include "lib.h"

struct sockaddr_in socket_configuration(int port);
void waiting_conection(int socket);
int create_socket(void);

#endif /*SOCKET_H_*/
