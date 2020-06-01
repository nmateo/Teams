/*
** EPITECH PROJECT, 2020
** serveur
** File description:
** delete_client
*/

#include "server.h"

void free_client(client_t **list_clients, client_t *client)
{
    fclose(client->fp);
    close(client->socket);
    if (*list_clients == client)
        *list_clients = client->next;
    if (client->next != NULL)
        client->next->prev = client->prev;
    if (client->prev != NULL)
        client->prev->next = client->next;
    free(client);
}

void logout(client_t **list_clients, client_t *client)
{
    char buf[256];
    sprintf(buf, "210;%s;%s\r\n", client->uuid, client->name);
    if (client->name != NULL) {
        print_event(list_clients, buf, "yes");
        server_event_user_logged_out(client->uuid);
    }
    free_client(list_clients, client);
}
