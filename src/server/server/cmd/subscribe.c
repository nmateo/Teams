/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** [enter description here]
*/

#include "server.h"

int already_sub(client_t *client, char *txt)
{
    (void)txt;
    FILE *fp;
    char *buf = NULL;
    char **list_sub = NULL;
    struct stat st;
    size_t size = 0;

    fp = fopen("sub", "r");
    fseek(fp, 0, SEEK_SET);
    stat("sub", &st);
    size = st.st_size;
    buf = malloc(sizeof(char) * (size + 1));
    bzero(buf, size + 1);
    fread(buf, size, 1, fp);
    fclose(fp);
    list_sub = str_twa(buf, "\n");
    for (size_t i = 0; list_sub[i] != NULL; i++)
        if (strcmp(list_sub[i], concat("user;", client->uuid)) == 0)
            return -1;
    return 0;
}

void write_on_user_file(client_t *client, char *txt)
{
    char buf[60];

    chdir("./data/users");
    sprintf(buf, "team;%s\n", txt);
    add_line_at_end(client->uuid, buf);
    chdir("./../../");
}

int parsind_error(client_t *client, char *txt)
{
    char buf[128];

    bzero(buf, 128);
    if (chdir(txt) == -1) {
        chdir("../../");
        sprintf(buf, "330;%s\r\n", txt);
        print(client->socket, buf);
        return -1;
    }
    if (already_sub(client, txt) == -1) {
        print(client->socket, "370\r\n");
        chdir("./../../../");
        return -1;
    }
    return 0;
}

void subscribe(client_t **list_clients, client_t *client, char *txt)
{
    (void)list_clients;
    char buf[128];
    txt = take_arg(txt, 1);
    chdir("./data/teams");
    if (parsind_error(client, txt) == -1)
        return;
    sprintf(buf, "user;%s",  client->uuid);
    add_line_at_end("sub", buf);
    chdir("./../../../");
    write_on_user_file(client, txt);
    bzero(buf, 128);
    sprintf(buf, "470;%s;%s\r\n", client->uuid, txt);
    print(client->socket, buf);
}
