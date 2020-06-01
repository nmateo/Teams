/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** [enter description here]
*/

#include "server.h"

void init_use(client_t *client)
{
    client->use = malloc(sizeof(char) * 256);
    bzero(client->use, 256);
    getcwd(client->use, 256);
}

int check_name_folder(client_t *client, char *uuid)
{
    char buf[64];

    bzero(buf, 64);
    if (chdir(uuid) != -1) {
        bzero(client->use, 256);
        getcwd(client->use, 256);
        client->folder += 1;
        return 0;
    }
    if (client->folder == 0)
        sprintf(buf, "330;%s\r\n", uuid);
    else if (client->folder == 1)
        sprintf(buf, "340;%s\r\n", uuid);
    else
        sprintf(buf, "350;%s\r\n", uuid);
    print(client->socket, buf);
    return -1;
}
static int nbr_uuid(char *t)
{
    int nb_uuid = 0;

    for (size_t i = 0; i < strlen(t); i++) {
        if (t[i] != ' ')
            nb_uuid++;
        for (;t[i] != ' ' && t[i] != '\0'; i++);
    }
    return nb_uuid;
}

static char **parsing_uuid(char *t)
{
    int nb_uuid = nbr_uuid(t);
    char **tab_uuid = malloc(sizeof(char *) * (nb_uuid + 1));
    int x = 1;
    for (; x <= nb_uuid; x++)
        tab_uuid[x - 1] = take_arg(t, x);
    tab_uuid[x - 1] = NULL;
    return tab_uuid;
}

void use(client_t **list_clients, client_t *client, char *txt)
{
    int err = 0;
    char **tab_uuid = parsing_uuid(txt);
    int folder = client->folder;

    client->folder = 0;
    (void)list_clients;
    chdir("./data/teams");
    if (client->use == NULL)
        init_use(client);
    for (size_t i = 0; tab_uuid[i] != NULL; i++)
        if ((err = check_name_folder(client, tab_uuid[i])) == -1)
            break;
    for (int i = client->folder; i > 0; i--)
        chdir("..");
    if (err != 0 && client->folder == 0)
        client->folder = folder;
    if (tab_uuid[0] == NULL) {
        bzero(client->use, 256);
        client->use = getcwd(client->use, 128);
    }
    chdir("../../");
}
