/*
** EPITECH PROJECT, 2020
** serveur
** File description:
** main
*/

#include "server.h"

void print_help(void)
{
    printf("USAGE: ./my_teams_server port\n");
    printf("       ");
    printf("port  is the port number on which the server socket listens.\n");
}

int main(int argc, char **argv)
{
    if (argc != 2)
    return (84);
    if (argc == 2 && (strcmp(argv[1], "-help") || strcmp(argv[1], "-h")) == 0) {
        print_help();
        return 0;
    }
    manage_data();
    main_loop_server(atoi(argv[1]));
    return 0;
}
