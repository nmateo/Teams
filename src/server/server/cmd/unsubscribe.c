/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** unsubscribe
*/

#include "cli.h"
#include "server.h"

/*
Ajouter le $ dans le file sub dans le dossier de la team
*/

static void add_char_at_position(char *filepath, char *str, int position)
{
    FILE *file = fopen(filepath, "r+");

    fseek(file, position, SEEK_SET);
    fwrite(str, strlen(str), 1, file);
    fclose(file);
}

static void send_data(client_t *client, char *uuid)
{
    char msg[256];

    memset(msg, 0, sizeof(msg));
    sprintf(msg, "%i;%s;%s%s", PRINT_UNSUB, client->uuid, uuid, END);
    print(client->socket, msg);
}

void unsubscribe(client_t **list_clients, client_t *client, char *txt)
{
    char *filepath = concat(PATH_USER, client->uuid);
    char **tab = str_twa(read_file(filepath), "\n");
    char *team = NULL;
    size_t i = 0;
    size_t position = 0;

    txt = clean_txt(txt);
    team = concat("team;", txt);
    (void) list_clients;
    while (tab[i] != NULL) {
        if (strcmp(tab[i], team) == 0) {
            add_char_at_position(filepath, "$", position + 1);
            break;
        }
        position += strlen(tab[i]);
        i++;
    }
    send_data(client, txt);
}