/*
** EPITECH PROJECT, 2017
** my_ftp
** File description:
** header
*/

#include "cli.h"
#include <string.h>
#include <stdio.h>

cf_arr_t commands[] = {
    {
        .str = "/help",
        .ptr = command_help
    },
    {
        .str = "/login",
        .ptr = command_login
    },
    {
        .str = "/logout",
        .ptr = command_logout
    },
    {
        .str = "/users",
        .ptr = command_users
    },
    {
        .str = "/user",
        .ptr = command_user
    },
    {
        .str = "/send",
        .ptr = command_send
    },
    {
        .str = "/messages",
        .ptr = command_message
    },
    {
        .str = "/subscribe",
        .ptr = command_subscribe
    },
    {
        .str = "/suscribed",
        .ptr = command_subscribed
    },
    {
        .str = "/unsubscribe",
        .ptr = command_unsubscribe
    },
    {
        .str = "/use",
        .ptr = command_use
    },
    {
        .str = "/create",
        .ptr = command_create
    },
    {
        .str = "/list",
        .ptr = command_list
    },
    {
        .str = "/info",
        .ptr = command_info
    },
    {
        .str = NULL,
        .ptr = (fptr_commands_t)0
    }
};
