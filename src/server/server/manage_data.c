/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** [enter description here]
*/

#include "server.h"

void manage_data(void)
{
    if (check_folder("data") == -1)
        mkdir("data", 0777);
    if (check_folder("./data/teams") == -1)
        mkdir("./data/teams", 0777);
    if (check_folder("./data/users") == -1)
        mkdir("./data/users", 0777);
    if (check_folder("./data/conv") == -1)
        mkdir("./data/conv", 0777);
}

void set_uuid_user(char *uuid, char *name)
{
    FILE *fp;

    chdir("./data/users/");
    fp = fopen(uuid, "w+");
    fseek(fp, 0, SEEK_SET);
    fprintf(fp, "%s\n", name);
    fclose(fp);
    chdir("./../../");
}
