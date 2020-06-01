/*
** EPITECH PROJECT, 2017
** my_ftp
** File description:
** header
*/

#include "cli.h"
#include <string.h>
#include <stdio.h>

ref_arr_t events[] = {
    {
        .str = "200",
        .ptr = event_logged_in
    },
    {
        .str = "210",
        .ptr = event_logged_out
    },
    {
        .str = "220",
        .ptr = event_priv_msg
    },
    {
        .str = "230",
        .ptr = event_thread_msg
    },
    {
        .str = "240",
        .ptr = event_team_created
    },
    {
        .str = "250",
        .ptr = event_channel_created
    },
    {
        .str = "260",
        .ptr = event_thread_created
    },
    {
        .str = "270",
        .ptr = print_users
    },
    {
        .str = "280",
        .ptr = print_teams
    },
    {
        .str = "290",
        .ptr = print_channels
    },
    {
        .str = "300",
        .ptr = print_threads
    },
    {
        .str = "310",
        .ptr = print_replies
    },
    {
        .str = "320",
        .ptr = print_conv
    },
    {
        .str = "330",
        .ptr = unknown_team
    },
    {
        .str = "340",
        .ptr = unknown_channel
    },
    {
        .str = "350",
        .ptr = unknown_thread
    },
    {
        .str = "360",
        .ptr = unknown_user
    },
    {
        .str = "370",
        .ptr = error_unauthorized
    },
    {
        .str = "380",
        .ptr = already_exist
    },
    {
        .str = "390",
        .ptr = print_user
    },
    {
        .str = "400",
        .ptr = print_team
    },
    {
        .str = "410",
        .ptr = print_channel
    },
    {   .str = "420",
        .ptr = print_thread
    },
    {
        .str = "430",
        .ptr = print_team_created
    },
    {
        .str = "440",
        .ptr = channel_created
    },
    {
        .str = "450",
        .ptr = thread_created
    },
    {
        .str = "460",
        .ptr = reply_created
    },
    {
        .str = "470",
        .ptr = print_sub
    },
    {
        .str = "480",
        .ptr = print_unsub
    },
    {
        .str = NULL,
        .ptr = (fptr_respevents_t)0
    }
};
