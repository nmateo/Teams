/*
** EPITECH PROJECT, 2020
** my_ftp
** File description:
** header
*/

#include "cli.h"
#include <netinet/ip.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static void get_active_inputs(cli_ctrl_t *ctrl)
{
    errno = 0;
    ctrl->max_fd = (0 > ctrl->control_socket) ? 0:ctrl->control_socket;
    FD_ZERO(&ctrl->read_fds);
    FD_SET(ctrl->control_socket, &ctrl->read_fds);
    FD_SET(0, &ctrl->read_fds);
    if ((select(ctrl->max_fd + 1, &ctrl->read_fds, NULL, NULL, NULL)) < 0 && \
            (errno != EINTR)) {
        perror("select()");
        exit(84);
    }
}

static void event_manager(cli_ctrl_t *ctrl)
{
    char *msg;
    char **toks;
    char *buf[1];

    if (recv(ctrl->control_socket, buf, sizeof(buf), \
                MSG_PEEK | MSG_DONTWAIT) == 0) {
        exit(0);
    }
    if ((msg = read_msg_socket(ctrl)) == NULL)
        return;
    toks = sep_tok(msg, ";\n\r");
    for (int i = 0; events[i].str != NULL; i++) {
        if (strcmp(events[i].str, toks[0]) == 0) {
            events[i].ptr(ctrl, toks);
        }
    }
}

static void input_manager(cli_ctrl_t *ctrl)
{
    char **toks = NULL;
    char *line = NULL;
    size_t len = 0;

    if ((getline(&line, &len, stdin)) == EOF)
        exit(0);
    for (int i = 0; line[i] != '\0'; i++)
        (line[i] == '\n') ? line[i] = '\0': 0;
    fflush(stdin);
    toks = sep_tok_args(line, " \n\r\t");
    for (int i = 1; toks[i] != NULL; i++)
        toks[i] = add_dquotes(toks[i]);
    if (toks == NULL || toks[0] == NULL)
        return;
    for (int i = 0; commands[i].str != NULL; i++) {
        if (strcmp(commands[i].str, toks[0]) == 0) {
            commands[i].ptr(ctrl, toks);
        }
    }
}

int shell(cli_ctrl_t *ctrl)
{
    while (1) {
        get_active_inputs(ctrl);
        if (FD_ISSET(ctrl->control_socket, &ctrl->read_fds))
            event_manager(ctrl);
        if (FD_ISSET(0, &ctrl->read_fds))
            input_manager(ctrl);
    }
    return (0);
}

int init_control_socket(unsigned short port, char *ip)
{
    int sock;
    struct sockaddr_in sad = { 0 };

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket()");
        exit(84);
    }
    sad.sin_family = AF_INET;
    sad.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &sad.sin_addr) <= 0) {
        perror("inet_pton()");
        exit(84);
    }
    if (connect(sock, (struct sockaddr *) &sad, sizeof(sad)) < 0) {
        perror("connect()");
        exit(84);
    }
    return (sock);
}
