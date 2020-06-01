/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** parse_client_file
*/

#include "cli.h"
#include "server.h"

static int get_user_status(client_t **list_clients, char *uuid)
{
    for (client_t *cli = *list_clients; cli != NULL; cli = cli->next) {
        if (strcasecmp(cli->uuid, uuid) == 0)
            return 1;
    }
    return 0;
}

static void send_data(client_t *client, char *uuid, char *username, int status)
{
    char msg[256];

    memset(msg, 0, sizeof(msg));
    sprintf(msg, "%i;%s;%s;%d%s", PRINT_USER, uuid, username, status, END);
    print(client->socket, msg);
}

static void no_user(client_t *client)
{
    char msg[256];

    memset(msg, 0, sizeof(msg));
    sprintf(msg, "%i%s", PRINT_USER, END);
    print(client->socket, msg);
}

static char *get_user_name(char *name)
{
    FILE *fp;
    size_t size = 0;
    char *uuid = NULL;

    chdir("users");
    fp = fopen(name, "r");
    if (fp == NULL)
        return NULL;
    getline(&uuid, &size, fp);
    uuid[strlen(uuid) - 1] = '\0';
    fclose(fp);
    chdir("..");
    return (uuid);
}

void user(client_t **list_clients, client_t *client, char *txt)
{
    char *user_name = NULL;
    int user_status = 0;
    char buffer[256];

    txt = clean_txt(txt);
    user_status = get_user_status(list_clients, txt);
    memset(buffer, 0, sizeof(buffer));
    chdir("./data");
    if ((user_name = get_user_name(txt)) == NULL) {
        no_user(client);
        return;
    }
    sprintf(buffer, "390;%s;%s;%d", txt, user_name, user_status);
    send_data(client, txt, user_name, user_status);
    chdir("./../");
}