/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** logging_server
*/

#ifndef __LOGGING_SERVER_H__
#define __LOGGING_SERVER_H__

#include <stdint.h>
#include <time.h>

// Handler called when a new team is created
int server_event_team_created(char const *team_id, char const *team_name, \
char const *user_id);

// Handler called when a channel is created
int server_event_channel_created(char const *team_id, char const *channel_id, \
char const *channel_name);

// Handler called when a thread is created
int server_event_thread_created(char const *channel_id, \
char const *thread_id, char const *user_id, char const *message);

// Handler called when a message is post in a thread
int server_event_thread_new_message(char const *thread_id, \
char const *user_id, char const *message);

// Handler called when a user join a team
int server_event_user_join_a_team(char const *team_id, char const *user_id);

// Handler called when a user leave a team
int server_event_user_leave_a_team(char const *team_id, char const *user_id);

// Handler called when a user is created
int server_event_user_created(char const *user_id, char const *user_name);

// Handler called when a user is reloaded (on server startup)
int server_event_user_loaded(char const *user_id, char const *user_name);

// Handler called when a user is logging in
int server_event_user_logged_in(char const *user_id);

// Handler called when a user is logging out
int server_event_user_logged_out(char const *user_id);

// Handler called when a user send a private message to an other
int server_event_private_message_sended(char const *sender_id, \
char const *receiver_id, char const *message);

#endif /* __LOGGING_SERVER_H__ */