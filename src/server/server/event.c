/*
** EPITECH PROJECT, 2020
** serveur
** File description:
** [enter description here]
*/


#include "server.h"

cmd_t list_cmd[] = {
    {"users", users},
    {"user", user},
    {"send", sendf},
    {"use", use},
    {"messages", messages},
    {"subscribe", subscribe},
    {"unsubscribe", unsubscribe},
    {"create", create}
};

void log_client(client_t **clients_list, client_t *client, char *cmd, char *txt)
{
    if (strcasecmp(cmd, "login") == 0)
        login(clients_list, client, txt);
    else
        print(client->socket, "370\r\n");
}

void check_list_cmd(client_t **cli_list, client_t *client, char *cmd, char *txt)
{
    if (client->name == NULL) {
        log_client(cli_list, client, cmd, txt);
        return;
    }
    for (size_t i = 0; i < 8; i++) {
        if ((strcasecmp(list_cmd[i].cmd, cmd)) == 0) {
            (list_cmd[i].func(cli_list, client, txt));
            return;
        }
    }
    if (strcasecmp(cmd, "login") == 0)
        print(client->socket, "370\r\n");
}

char *get_txt(char *msg, int i)
{
    char *txt = NULL;
    int j = i;

    for (;msg[i] != '\n' && msg[i] != '\r'; i++);
    txt = malloc(sizeof(char) * ((i - j) + 1));
    txt[(i - j)] = '\0';
    strncpy(txt, msg + j, (i - j));
    return txt;
}

void command_management(client_t **list_clients, client_t *client, char *msg)
{
    char *cmd = 0;
    char *txt = 0;
    size_t i = 0;

    for (;msg[i] != '\n' && msg[i] != ' ' && msg[i] != '\r'; i++);
    cmd = malloc(sizeof(char) * (i + 1));
    cmd[i] = '\0';
    strncpy(cmd, msg, i);
    if (msg[i] == ' ')
        i++;
    txt = get_txt(msg, i);
    if (strcasecmp("logout", cmd) != 0)
        check_list_cmd(list_clients, client, cmd, txt);
    else
        logout(list_clients, client);
    free(cmd);
    free(txt);
}
