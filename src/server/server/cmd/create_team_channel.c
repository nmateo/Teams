/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** [enter description here]
*/

#include "server.h"

void create_team(client_t **list_clients, char *txt, client_t *client)
{
    char *name = take_arg(txt, 1);
    char *des = take_arg(txt, 2);
    char *uuid = generate_uuid();
    char *buf = malloc(sizeof(char) * (strlen(des) + 37 + strlen(name) + 10));

    mkdir(uuid, 0777);
    chdir(uuid);
    create_file("description");
    create_file("sub");
    filling_description(name, des, NULL);
    chdir("..");
    server_event_team_created(uuid, name, client->uuid);
    sprintf(buf, "240;%s;%s;%s\r\n", uuid, name, des);
    print_event(list_clients, buf, client->uuid);
    bzero(buf, (strlen(des) + 37 + strlen(name) + 10));
    sprintf(buf, "430;%s;%s;%s\r\n", uuid, name, des);
    print(client->socket, buf);
}

void create_channel(client_t **list_clients, char *txt, client_t *client)
{
    char *name = take_arg(txt, 1);
    char *des = take_arg(txt, 2);
    char *uuid = generate_uuid();
    char *buf = malloc(sizeof(char) * (strlen(des) + 37 + strlen(name) + 10));
    char *team_uuid = get_parent_uuid();

    mkdir(uuid, 0777);
    chdir(uuid);
    create_file("description");
    filling_description(name, des, NULL);
    chdir("..");
    server_event_channel_created(team_uuid, uuid, name);
    sprintf(buf, "250;%s;%s;%s\r\n", uuid, name, des);
    print_event(list_clients, buf, client->uuid);
    bzero(buf, (strlen(des) + 37 + strlen(name) + 10));
    sprintf(buf, "440;%s;%s;%s\r\n", uuid, name, des);
    print(client->socket, buf);
}
