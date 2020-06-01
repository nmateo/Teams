/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** [enter description here]
*/

#include "server.h"

char *get_parent_uuid(void)
{
    char buf[256];
    size_t size  = 0;
    size_t i = 0;
    char *uuid = NULL;

    bzero(buf, 256);
    getcwd(buf, 256);
    for (i = strlen(buf); buf[i] != '/'; i--)
        size++;
    uuid = malloc(sizeof(char) * size);
    bzero(uuid, size);
    i += 1;
    for (size_t j = 0; buf[i] != '\0'; j++) {
        uuid[j] = buf[i];
        i++;
    }
    return uuid;
}

char *get_param_create(char *t, int arg_n, char end)
{
    int nb_space = 0;
    char *buf = NULL;
    int x = 0;
    int save_x = 0;
    size_t size = 0;

    for (; nb_space != arg_n; x++)
    if (t[x] == ' ')
    nb_space++;
    save_x = x;
    for (; t[x] != end; x++)
    size++;
    x = save_x;
    buf = malloc(sizeof(char) * size + 1);
    bzero(buf, size + 1);
    for (size_t i = 0; i < size; i++) {
        buf[i] = t[x];
        x++;
    }
    return buf;
}

void filling_description(char *name, char *des, char *ts)
{
    FILE *fp;

    fp = fopen("description", "w+");
    fseek(fp, 0, SEEK_END);
    if (ts == NULL)
        fprintf(fp, "%s\n%s\n", name, des);
    else
        fprintf(fp, "%s\n%s\n%s\n", ts, name, des);
    fclose(fp);
}

char *get_timestamp(void)
{

    char ret[1024];
    time_t timestamp = time(NULL);

    memset(ret, 0, sizeof(ret));
    sprintf(ret, "%ld", timestamp);
    return (strdup(ret));
}
