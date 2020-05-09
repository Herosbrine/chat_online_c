/*
** GREGOIRE, OUNIS, 2019
** undefined
** File description:
** chat_online.h
*/

#ifndef CLIENT_H_
#define CLIENT_H_
#ifdef WIN32
#include <winsock2.h>
#elif defined (linux)
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#define INVALID_SOCKET  -1
#define SOCKET_ERROR    -1
#define PORT            1901
#define BUFF_SIZE        1024

typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;
#endif
#endif
