/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** [enter description here]
*/

#include "server.h"

void return_list(client_t *client, FILE *fp)
{
    struct stat st;
    char *buf = NULL;
    char *string = NULL;
    size_t size = 0;

    fseek(fp, 0, SEEK_SET);
    stat("./data/users/.list_users", &st);
    size = st.st_size;
    buf = malloc(sizeof(char) * (size));
    fread(buf, size, 1, fp);
    buf[size - 1] = '\0';
    string = malloc(sizeof(char) * (size + 32));
    sprintf(string, "270;%s\r\n", buf);
    free(buf);
    print(client->socket, string);
    free(string);
}

static int user_status(client_t **list_clients, char *uuid)
{
    for (client_t *cli = *list_clients; cli != NULL; cli = cli->next) {
        if (strcasecmp(cli->uuid, uuid) == 0)
            return 1;
    }
    return 0;
}

static FILE *users_list_file(void)
{
    FILE *fp;

    chdir("./data/users");
    remove(".list_users");
    create_file(".list_users");
    fp = fopen(".list_users", "w+");
    chdir("./../../");
    return fp;

}

char *get_user_name(char *name)
{
    FILE *fp;
    size_t size = 0;
    char *uuid = NULL;

    chdir("users");
    fp = fopen(name, "r");
    getline(&uuid, &size, fp);
    uuid[strlen(uuid) - 1] = '\0';
    fclose(fp);
    chdir("..");
    return uuid;
}

void users(client_t **list_clients, client_t *client, char *txt)
{
    (void)txt;
    DIR *fd;
    FILE *fp = users_list_file();
    struct dirent *dir;
    char *user_name = NULL;
    int user_stat = 0;

    chdir("./data");
    fd = opendir("users");
    while ((dir = readdir(fd)) != NULL) {
        if (dir->d_name[0] != '.') {
            fseek(fp, 0, SEEK_END);
            user_name = get_user_name(dir->d_name);
            user_stat = user_status(list_clients, dir->d_name);
            fprintf(fp, "%s;%s;%d\n", dir->d_name, user_name, user_stat);
        }
    }
    chdir("./../");
    return_list(client, fp);
    fclose(fp);
    closedir(fd);
}
