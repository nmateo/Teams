/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** [enter description here]
*/

#include "server.h"

static int check_user_name(char *user, char *file)
{
    FILE *fp;
    size_t size = 0;
    char *buf = NULL;

    fp = fopen(file, "r");
    getline(&buf, &size, fp);
    char *buffer = strdup(buf);
    buffer[strlen(buffer) - 1] = '\0';
    fclose(fp);
    if (strcasecmp(user, buffer) == 0)
        return 1;
    return 0;
}

static int check_file_user(client_t *client, char *user)
{
    DIR *fd;
    struct dirent *dir;

    chdir("./data");
    fd = opendir("users");
    chdir("users");
    while ((dir = readdir(fd)) != NULL){
        if (dir->d_name[0] != '.' && check_user_name(user , dir->d_name) == 1) {
            client->uuid = strdup(dir->d_name);
            return 1;
        }
    }
    closedir(fd);
    chdir("./../../");
    return 0;
}

void login(client_t **clients_list, client_t *client, char *txt)
{
    char *user_name = take_arg(txt, 1);
    char buf[256];

    client->name = strdup(user_name);
    free(user_name);
    if (check_file_user(client, client->name) == 0) {
        client->uuid = generate_uuid();
        chdir("./data/users");
        create_file(client->uuid);
        chdir("./../../");
        set_uuid_user(client->uuid, client->name);
        server_event_user_created(client->uuid, client->name);
    } else {
        server_event_user_loaded(client->uuid, client->name);
        chdir("./../../");
    }
    server_event_user_logged_in(client->uuid);
    sprintf(buf, "200;%s;%s\r\n", client->uuid, client->name);
    print_event(clients_list, buf, "yes");
}
