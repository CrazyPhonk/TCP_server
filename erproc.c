#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "erproc.h"


int Socket(int domain, int type, int protocol){
int res = socket(domain,type,protocol);
if (res == -1){
perror("SOCKET HAS NOT BEEN CREATED");
exit(EXIT_FAILURE);
}
//printf("socket creating success\n");
return res;
}

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
int res = bind(sockfd, addr, addrlen);
if(res == -1) {
perror("bind failed");
exit(EXIT_FAILURE);
}
//printf("bind success\n");
}

void Listen(int sockfd, int backlog){
int res = listen(sockfd, backlog);
if(res == -1){
perror("listen failed");
exit(EXIT_FAILURE);
}
//printf("Listen success\n");
}


int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
int res = accept(sockfd, addr, addrlen);
if (res == -1) {
perror("accept failed");
exit(EXIT_FAILURE);
}
//printf("Accept success\n");
return res;
}
