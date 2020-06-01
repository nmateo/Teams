/*
** EPITECH PROJECT, 2020
** serveur
** File description:
** tools
*/

#include "lib.h"

void error(char *msg)
{
    perror(msg);
    exit(84);
}

void print(int socketfd, char *msg)
{
    write(socketfd, msg, strlen(msg));
}

char *generate_uuid(void)
{
    uuid_t binuuid;
    char *uuid = malloc(sizeof(char) * 37);

    uuid_generate_random(binuuid);
    uuid_unparse(binuuid, uuid);
    return uuid;
}

int check_folder(char *name)
{
    struct stat sb;

    if (stat(name, &sb) == 0 && S_ISDIR(sb.st_mode))
        return 0;
    return -1;
}

int check_file(char *name)
{
    if (access(name, F_OK) != -1)
        return 0;
    return -1;
}
