/*
** EPITECH PROJECT, 2020
** my_ftp
** File description:
** header
*/

#include "cli.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char **sep_tok(char *buffer, char *seps)
{
    char **tok = malloc(sizeof(char *) * 256);
    char *ptr;
    int i = 0;

    if (tok == NULL)
        return (NULL);
    if((ptr = strtok(buffer, seps)) == NULL)
        return (NULL);
    tok[i] = ptr;
    while ((ptr = strtok(NULL, seps)) != NULL) {
        i++;
        tok[i] = ptr;
        if (i >= 254)
            break;
    }
    tok[++i] = NULL;
    return (tok);
}

char **sep_tok_args(char *buffer, char *seps)
{
    char **tok = malloc(sizeof(char *) * 256);
    char *ptr;
    int i = 0;

    if (tok == NULL)
        return (NULL);
    if((ptr = strtok(buffer, seps)) == NULL)
        return (NULL);
    tok[i] = ptr;
    while ((ptr = strtok(NULL, "\"")) != NULL) {
        i++;
        if (is_whitespaces(ptr) == 0) {
            i--;
            continue;
        }
        tok[i] = ptr;
        if (i >= 254)
            break;
    }
    tok[++i] = NULL;
    return (tok);
}

char *add_dquotes(char *str)
{
    char *ret = malloc(sizeof(char) * (strlen(str) + 3));

    ret[0] = '\"';
    strcpy(ret + 1, str);
    ret[strlen(str) + 1] = '\"';
    ret[strlen(str) + 2] = '\0';
    return (ret);
}

char *read_msg_socket(cli_ctrl_t *ctrl)
{
    size_t idx = 0;
    char *buff = malloc(sizeof(char) * 2);
    char *tmp = NULL;

    if (buff == NULL)
        return (NULL);
    while (idx < 8192 && read(ctrl->control_socket, &buff[idx], 1)) {
        if (idx > 0 && buff[idx - 1] == '\r' && buff[idx] == '\n')
            break;
        idx++;
        buff[idx] = '\0';
        if ((tmp = strdup(buff)) == NULL)
            return (NULL);
        free(buff);
        if ((buff = malloc(sizeof(char) * (idx + 2))) == NULL)
            return (NULL);
        strcpy(buff, tmp);
    }
    buff[idx - 1] = '\0';
    return (buff);
}

int write_msg_socket(int socket, char *msg)
{
    dprintf(socket, "%s\n", msg);
    return (0);
}
