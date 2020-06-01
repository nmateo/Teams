/*
** EPITECH PROJECT, 2020
** serveur
** File description:
** server_h
*/

#ifndef SERVER_H_
#define SERVER_H_

#include "lib.h"
#include "socket.h"

#define CMD_SEP ' '
#define END "\r\n"
#define CODE_LENGHT 3

#define PATH_USER "./data/users/"
#define PATH_CONV "./data/conv/"
#define PATH_TEAM "./data/teams/"
#define TEAM 0
#define CHANNEL 1
#define THREAD 2
#define REPLY 3

/* clients connectés */
typedef struct client_s {
    int socket;
    FILE *fp;
    char *name;
    char *uuid;
    char *use;
    int folder;
    struct client_s *next;
    struct client_s *prev;
} client_t;

typedef struct cmd {
    char *cmd;
    void (*func)(client_t **list_clients, client_t *client, char *txt);
} cmd_t;

void main_loop_server(int port);

// tools

char *take_arg(char *arg, int n);
void error(char *msg);
void print(int socketfd, char *msg);
void print_event_teams(client_t **clients, char *uuid, char *txt, char *user);
char *generate_uuid(void);
int check_file(char *name);
int check_folder(char *name);
void create_file(char *name);
void print_event(client_t **clients, char *txt, char *uuid_user);
char *concat(char *s1, char *s2);
char *itoa(int nb, int size);
char **str_twa(char *buffer, char *delimiter);
char *read_file(char *filepath);
int already_sub(client_t *client, char *txt);
char *clean_txt(char *txt);
void print_a_user(client_t **list_clients, client_t *client, char *uuid_user);

// send / message

char *get_uuid_conv(char *uuid1, char *uuid2);
void add_line_at_end(char *path, char *line);
void add_conv(client_t *client, char *uuid, char *uuid_conv);
void send_error_size(client_t *client);

// set_fd.c

void set_fd_server(fd_set *readfs, int server, int *h_socket);
void set_fd_client(client_t *list_clients, fd_set *readfs, int *h_socket);

//server.c

void manage_data(void);
void set_uuid_user(char *uuid, char *name);

//manage_server.c:

void logout(client_t **list_clients, client_t *client);
void login(client_t **clients_list, client_t *client, char *txt);
void users(client_t **list_clients, client_t *client, char* txt);
void user(client_t **list_clients, client_t *client, char* txt);
void use(client_t **list_clients, client_t *client, char *txt);
void sendf(client_t **list_clients, client_t *client, char* txt);
void messages(client_t **list_clients, client_t *client, char* txt);
void create(client_t **list_clients, client_t *client, char *txt);
void subscribe(client_t **list_clients, client_t *client, char *txt);
void unsubscribe(client_t **list_clients, client_t *client, char* txt);

//cmd

void create_team(client_t **list_clients, char *txt, client_t *client);
void create_channel(client_t **list_clients, char *txt, client_t *client);
char *get_parent_uuid(void);
char *get_param_create(char *t, int arg_n, char end);
void filling_description(char *name, char *des, char *ts);
char *get_timestamp(void);

//create
#endif /*SERVER_H_*/
