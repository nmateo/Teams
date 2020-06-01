/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** [enter description here]
*/

#include "server.h"

int prepare_thread(client_t *client, char *uuid, char *channel_uuid)
{
    chdir("..");
    if (already_sub(client, client->uuid) == 0) {
        print(client->socket, "370\r\n");
        return -1;
    }
    chdir(channel_uuid);
    mkdir(uuid, 0777);
    chdir(uuid);
    create_file("description");
    create_file("replies");
    return 0;
}

void create_thread(client_t **list_clients, char *txt, client_t *client)
{
    char *name = take_arg(txt, 1);
    char *des = take_arg(txt, 2);
    char *uuid = generate_uuid();
    char *channel_uuid = get_parent_uuid();
    char *ts = get_timestamp();
    char buf[1024];

    if (prepare_thread(client, uuid, channel_uuid) == -1)
        return;
    filling_description(name, des, ts);
    chdir("..");
    server_event_thread_created(channel_uuid, uuid, client->uuid, des);
    sprintf(buf, "260;%s;%s;%s;%s;%s\r\n", uuid, client->uuid, ts, name, des);
    chdir("..");
    char *team = get_parent_uuid();
    chdir("./../../../");
    print_event_teams(list_clients, team, buf, client->uuid);
    bzero(buf, 1024);
    sprintf(buf, "450;%s;%s;%s;%s;%s\r\n", uuid, client->uuid, ts, name, des);
    print(client->socket, buf);
}

char *prepare_reply(client_t *client, char *thread)
{
    char *channel = NULL;
    char *team = NULL;

    chdir("..");
    channel = get_parent_uuid();
    chdir("..");
    team = get_parent_uuid();
    if (already_sub(client, client->uuid) == 0) {
        print(client->socket, "370\r\n");
        return NULL;
    }
    chdir(channel);
    chdir(thread);
    return team;
}

void create_reply(client_t **list_clients, char *txt, client_t *client)
{
    char *thread = get_parent_uuid();
    char *des = take_arg(txt, 1);
    char *ts = get_timestamp();
    char buf[1024];
    char *team = NULL;

    if ((team = prepare_reply(client, thread)) == NULL)
        return;
    sprintf(buf, "%s;%s;%s\n", client->uuid, ts, des);
    add_line_at_end("replies", buf);
    bzero(buf, 1024);
    sprintf(buf, "230;%s;%s;%s;%s\r\n", team, thread, client->uuid, des);
    chdir("./../../../../../");
    print_event_teams(list_clients, team, buf, client->uuid);
    bzero(buf, 1024);
    sprintf(buf, "460;%s;%s;%s;%s\r\n", thread, client->uuid, ts, des);
    print(client->socket, buf);
}

void create(client_t **list_clients, client_t *client, char *txt)
{
    char home[256];

    bzero(home, 256);
    getcwd(home, 256);
    chdir(client->use);
    if (client->use == NULL) {
        print(client->socket, "370\r\n");
        return;
    }
    if (client->folder == TEAM)
        create_team(list_clients, txt, client);
    if (client->folder == CHANNEL)
        create_channel(list_clients, txt, client);
    if (client->folder == THREAD)
        create_thread(list_clients, txt, client);
    if (client->folder == REPLY)
        create_reply(list_clients, txt, client);
    chdir(home);
}
