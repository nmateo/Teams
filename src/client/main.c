/*
** EPITECH PROJECT, 2018
** idk
** File description:
** idk
*/

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "cli.h"
#include <unistd.h>

static bool is_digits_only(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (false);
    return (true);
}

static int help(int ret)
{
    printf("USAGE: ./myteams_cli ip port\n\t");
    printf("ip is the server ip adress on which the server socket listens\n\t");
    printf("port is the port number on which the server socket listens\n");
    return (ret);
}

int main(int ac, char **av)
{
    errno = 0;
    char *endptr;
    long port;
    cli_ctrl_t ctrl;

    if (ac != 3)
        return (help(0));
    if (is_digits_only(av[2]) == false)
        return (help(84));
    port = strtol(av[2], &endptr, 0);
    switch (errno) {
        case 0: NULL;
            break;
        default: return (help(84));
    }
    if (port < 0 || port > USHRT_MAX)
        return (help(84));
    ctrl.control_socket = init_control_socket((unsigned short)port, av[1]);
    return (shell(&ctrl));
}
