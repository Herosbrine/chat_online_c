/*
** GREGOIRE, OUNIS PROJECT, 2019
** undefined
** File description:
** server.c
*/

#include "server.h"
#include "client.h"
#include "my.h"

void send_message_to_all_clients(client_t *clients, client_t *sender,
int actual, const char *buffer, char from_server)
{
    int i = 0;
    char *message = NULL;
    message = malloc(sizeof(char) * BUFF_SIZE);
    message[0] = 0;
    for (; i < actual; i++) {
        //<----ON associe le message a son client----->
        if (sender->sock != clients[i].sock) {
            if (from_server == 0) {
                strncpy(message, sender->name, BUFF_SIZE - 1);
                strncat(message, " : ", sizeof message - strlen(message) - 1);
            }
            strncat(message, buffer, sizeof message - strlen(message) - 1);
            write_client(clients[i].sock, message);
        }
    }
}