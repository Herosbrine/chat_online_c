/*
** GREGOIRE, OUNIS, 2019
** undefined
** File description:
** chat_online.h
*/

#ifndef CHAT_ONLINE_H_
#define CHAT_ONLINE_H_

typedef struct my_socket data_t;
struct my_socket {
    int domain;
    int type;
    int protocol;
};

int my_socket(data_t *socket);
int main(void);
#endif
