/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** [enter description here]
*/

#include "server.h"

void create_file(char *name)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    creat(name, mode);
}

void print_event(client_t **clients, char *txt, char *uuid_user)
{
    for (client_t *cli = *clients; cli != NULL; cli = cli->next) {
        if (cli->name == NULL)
            continue;
        if (strcmp(cli->uuid, uuid_user) == 0)
            continue;
        print(cli->socket, txt);
    }
}

char *prepare_event_teams(char *uuid)
{
    FILE *fp;
    struct stat st;
    size_t size = 0;
    char *buf = NULL;

    chdir("./data/teams");
    chdir(uuid);
    stat("sub", &st);
    size = st.st_size;
    buf = malloc(sizeof(char) * (size + 1));
    fp = fopen("sub", "r");
    bzero(buf, size + 1);
    fread(buf, size + 1, 1, fp);
    fclose(fp);
    chdir("../../../");
    return buf;
}

void print_event_teams(client_t **clients, char *uuid, char *txt, char *user)
{
    char *buf = prepare_event_teams(uuid);
    char **tab_uuid = NULL;

    tab_uuid = str_twa(buf, "\n");
    for (size_t i = 0; tab_uuid[i] != NULL; i++)
        for (client_t *cli = *clients; cli != NULL; cli = cli->next) {
            if (strcmp(cli->uuid, user) == 0)
                continue;
            if (strcmp(cli->uuid, tab_uuid[i]) == 0)
                print(cli->socket, txt);
        }
}
