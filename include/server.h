/*
** GREGOIRE, OUNIS, 2019
** undefined
** File description:
** chat_online.h
*/

#ifndef SERVER_H_
#define SERVER_H_
#include "client.h"
#include <string.h>
#include <sys/socket.h>
#define MAX_CLIENTS     100
typedef struct my_socket client_t;
struct my_socket {
    int sock;
    char name[BUFF_SIZE];
    int protocol;
};
#endif
