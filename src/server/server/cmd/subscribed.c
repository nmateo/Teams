/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** subscribed
*/

#include "server.h"
#include "cli.h"

/*
susbcribed uuid
-> read . /data/teams/uid/sub and print it
susbcribed
    -> list all teams i am susbcribed
*/

static void send_data(client_t *client, int code)
{
    char msg[256];

    memset(msg, 0, sizeof(msg));
    sprintf(msg, "%i;", code);
    print(client->socket, msg);
}

static char *get_uuid(char *line)
{
    line = line + strlen("user;");
    return (strdup(line));
}

static void list_members(client_t **list_clients, client_t *client, \
char *uuid_team)
{
    char *sub_buffer = NULL;
    char **tab = NULL;
    char *path = concat(PATH_TEAM, uuid_team);
    size_t i = 0;

    send_data(client, PRINT_USERS);
    path = concat(path, "/sub");
    sub_buffer = read_file(path);
    tab = str_twa(sub_buffer, "\n");
    while (tab[i] != NULL) {
        if (strncmp("user", tab[i], 4) == 0)
            print_a_user(list_clients, client, get_uuid(tab[i]));
        i++;
    }
}

static void list_teams_subscribed(client_t *client)
{
    char *user_buffer = read_file(concat(PATH_USER, client->uuid));
    char code[256];
    char **tab = str_twa(user_buffer, "\n");
    size_t i = 0;

    memset(code, 0, sizeof(code));
    sprintf(code, "%i;", PRINT_TEAMS);
    print(client->socket, code);
    while (tab[i] != NULL) {
        if (strncmp("team", tab[i], 4) == 0)
            continue;
        i++;
    }
}

void subscribed(client_t **list_clients, client_t *client, char *txt)
{
    txt = clean_txt(txt);
    if (strlen(txt) == 0) {
        list_teams_subscribed(client);
    }
    else if (strlen(txt) > 0) {
        list_members(list_clients, client, txt);
    }
}