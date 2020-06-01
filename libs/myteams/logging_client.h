/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** logging_client
*/

#ifndef __LOGGING_CLIENT_H__
#define __LOGGING_CLIENT_H__

#include <stdint.h>
#include <time.h>

// Handler called when a user connect to the server (you or someone else)
int client_event_loggedin(char const *user_id, const char *user_name);

// Handler called when a user disconnect from the server (you or someone else)
int client_event_loggedout(char const *user_id, const char *user_name);

// Handler called when a new private message is received
int client_event_private_message_received(char const *user_id, \
char const *message_body);

// Handler called when a new reply is post in a thread
int client_event_thread_message_received(char const *team_id, \
char const *thread_id, char const *user_id, char const *message);

// Handler called when a new team is created
int client_event_team_created(char const *team_id, char const *team_name, \
char const *team_description);

// Handler called when a new channel is created
int client_event_channel_created(char const *channel_id, \
char const *channel_name, char const *channel_description);

// Handler called when a new thread is created
int client_event_thread_created(char const *thread_id, \
char const *user_id, time_t thread_timestamp, char const *thread_title, \
char const *thread_body);

// Handler called when the user ask for the users list
int client_print_users(char const *user_id, char const *user_name, \
int user_status);

// Handler called when the user ask for the team list
int client_print_teams(char const *team_id, char const *team_name, \
char const *team_description);

// Handler called when the user select a specific team to be in
int client_team_print_channels(char const *channel_id, \
char const *channel_name, char const *channel_description);

// Handler called when the user select a specific channe
int client_channel_print_threads(char const *thread_id, char const *user_id, \
time_t thread_timestamp, char const *thread_title, char const *thread_body);

// Handler called when the user ask for a specific thread
int client_thread_print_replies(char const *thread_id, char const *user_id, \
time_t reply_timestamp, char const *reply_body);

// Handler called when the user ask for a specific private discussion
int client_private_message_print_messages(char const *sender_id, \
time_t timestamp, char const *message);

// Handler called when the user ask for an unknown specific team
int client_error_unknown_team(char const *team_id);

// Handler called when the user ask for an unknown specific channel
int client_error_unknown_channel(char const *channel_id);

// Handler called when the user ask for an unknown specific thread
int client_error_unknown_thread(char const *thread_id);

// Handler called when the user want to chat with an unknown user
int client_error_unknown_user(char const *user_id);

// Handler called when the user want to perform an action that is unauthorized
int client_error_unauthorized(void);

// Handler called when the user want to perform an action that was refused
int client_error_already_exist(void);

// Handler called when the user ask for a user in particular
int client_print_user(char const *user_id, char const *user_name, \
int user_status);

// Handler called when the user ask for a team in particular (/info CLI command)
int client_print_team(char const *team_id, char const *team_name, \
char const *team_description);

// Handler called when the user ask for a channel in particular
int client_print_channel(char const *channel_id, char const *channel_name, \
char const *channel_description);

// Handler called when the user ask for a thread in particular
int client_print_thread(char const *thread_id, char const *user_id, \
time_t thread_timestamp, char const *thread_title, char const *thread_body);

// Handler called when the user create a team (/create CLI command)
int client_print_team_created(char const *team_id, char const *team_name, \
char const *team_description);

// Handler called when the user create a channel (/create CLI command)
int client_print_channel_created(char const *channel_id, \
char const *channel_name, char const *channel_description);

// Handler called when the user create a thread (/create CLI command)
int client_print_thread_created(char const *thread_id, char const *user_id, \
time_t thread_timestamp, char const *thread_title, char const *thread_body);

// Handler called when the user create a reply (/create CLI command)
int client_print_reply_created(char const *thread_id, char const *user_id, \
time_t reply_timestamp, char const *reply_body);

// Handler called when the user create a reply (/subscribe CLI command)
int client_print_subscribed(char const *user_id, char const *team_id);

// Handler called when the user create a reply (/unsubscribe CLI command)
int client_print_unsubscribed(char const *user_id, char const *team_id);

#endif /* __LOGGING_CLIENT_H__ */
