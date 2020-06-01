/*
** EPITECH PROJECT, 2017
** my_ftp
** File description:
** header
*/

#ifndef MY_TEAMS_CLI_
#define MY_TEAMS_CLI_

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

#define CONNECTED 707
#define EVENT_LOGGEDIN 200
#define EVENT_LOGGEDOUT 210
#define EVENT_PRIV_MSG 220
#define EVENT_THREAD_MSG 230
#define EVENT_TEAM_CREATED 240
#define EVENT_CHANNEL_CREATED 250
#define EVENT_THEARD_CREATED 260
#define PRINT_USERS 270
#define PRINT_TEAMS 280
#define PRINT_CHANNELS 290
#define PRINT_THREADS 300
#define PRINT_REPLIES 310
#define PRINT_CONV 320
#define UNKNOWN_TEAM 330
#define UNKNOWN_CHANNEL 340
#define UNKNOWN_THREAD 350
#define UNKNOWN_USER 360
#define ERROR_UNAUTHORIZED 370
#define ALREADY_EXIST 380
#define PRINT_USER 390
#define PRINT_TEAM 400
#define PRINT_CHANNEL 410
#define PRINT_THREAD 420
#define TEAM_CREATED 430
#define CHANNEL_CREATED 440
#define THREAD_CREATED 450
#define REPLY_CREATED 460
#define PRINT_SUB 470
#define PRINT_UNSUB 480

#include <sys/select.h>
#include <stdbool.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <uuid/uuid.h>

typedef struct client_control_s {
    int control_socket;
    int max_fd;
    fd_set read_fds;
    char *user_uuid;
    char *user_name;
    char *team_uuid;
    char *team_name;
    char *channel_uuid;
    char *channel_name;
    char *thread_uuid;
    char *thread_name;
} cli_ctrl_t;

typedef int (*fptr_commands_t)(cli_ctrl_t *, char **);

typedef struct command_func_arr_s {
    char *str;
    fptr_commands_t ptr;
} cf_arr_t;

typedef int (*fptr_respevents_t)(cli_ctrl_t *, char **);

typedef struct response_event_func_arr_s { 
    char *str;
    fptr_respevents_t ptr;
} ref_arr_t;

extern cf_arr_t commands[];
extern ref_arr_t events[];
int command_login(cli_ctrl_t *, char **);
int command_logout(cli_ctrl_t *, char **);
int command_users(cli_ctrl_t *, char **);
int command_user(cli_ctrl_t *, char **);
int command_send(cli_ctrl_t *, char **);
int command_message(cli_ctrl_t *, char **);
int command_subscribe(cli_ctrl_t *, char **);
int command_subscribed(cli_ctrl_t *, char **);
int command_unsubscribe(cli_ctrl_t *, char **);
int command_use(cli_ctrl_t *, char **);
int command_create(cli_ctrl_t *, char **);
int command_help(cli_ctrl_t *, char **);
int command_list(cli_ctrl_t *, char **);
int command_info(cli_ctrl_t *, char **);
int start(unsigned short port, char *path);
int write_msg_socket(int socket, char *msg);
void left_operand_void();
int interpret_clients_commands(void);
char *get_new_path(cli_ctrl_t *ctrl, char *path);
char *read_msg_socket(cli_ctrl_t *ctrl);
char **sep_tok(char *buffer, char *seps);
int shell(cli_ctrl_t *ctrl);
int init_control_socket(unsigned short port, char *ip);
int get_response_code(char *str);
int event_logged_in(cli_ctrl_t *ctrl, char **);
int event_logged_out(cli_ctrl_t *ctrl, char **);
int event_priv_msg(cli_ctrl_t *ctrl, char **);
int event_thread_msg(cli_ctrl_t *ctrl, char **);
int event_team_created(cli_ctrl_t *ctrl, char **);
int event_channel_created(cli_ctrl_t *ctrl, char **);
int event_thread_created(cli_ctrl_t *ctrl, char **);
int print_users(cli_ctrl_t *ctrl, char **);
int print_teams(cli_ctrl_t *ctrl, char **);
int print_channels(cli_ctrl_t *ctrl, char **);
int print_threads(cli_ctrl_t *ctrl, char **);
int print_replies(cli_ctrl_t *ctrl, char **);
int print_conv(cli_ctrl_t *ctrl, char **);
int unknown_team(cli_ctrl_t *ctrl, char **);
int unknown_channel(cli_ctrl_t *ctrl, char **);
int unknown_thread(cli_ctrl_t *ctrl, char **);
int unknown_user(cli_ctrl_t *ctrl, char **);
int error_unauthorized(cli_ctrl_t *ctrl, char **);
int already_exist(cli_ctrl_t *ctrl, char **);
int print_user(cli_ctrl_t *ctrl, char **);
int print_team(cli_ctrl_t *ctrl, char **);
int print_channel(cli_ctrl_t *ctrl, char **);
int print_thread(cli_ctrl_t *ctrl, char **);
int print_team_created(cli_ctrl_t *ctrl, char **);
int team_created(cli_ctrl_t *ctrl, char **);
int channel_created(cli_ctrl_t *ctrl, char **);
int thread_created(cli_ctrl_t *ctrl, char **);
int print_sub(cli_ctrl_t *ctrl, char **);
int print_unsub(cli_ctrl_t *ctrl, char **);
bool is_socket_up(int socket);
char *add_dquotes(char *str);
char **sep_tok_args(char *str, char *seps);
int is_whitespaces(char *str);
int reply_created(cli_ctrl_t *ctrl, char **toks);
#endif
