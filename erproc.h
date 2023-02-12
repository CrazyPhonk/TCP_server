#ifndef ERPROC_H
#define ERPROC_H //чтобы не сработал include дважды


#include <sys/types.h>
#include <sys/socket.h>

int Socket(int domain, int type, int protocol);

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

void Listen(int sockfd, int  backlog);

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
#endif
