#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "erproc.h"


int main(){
int server = Socket(AF_INET, SOCK_STREAM, 0); // 1-IPv4 2-TCP-SOCK_STREAM 3-0(default)
struct sockaddr_in adr = {0}; //для того, чтобы задать адрес IPv4
adr.sin_family = AF_INET;
adr.sin_port = htons(34543); //port
Bind(server, (struct sockaddr *) &adr, sizeof adr); //
Listen(server, 1);//1 clients in queue
socklen_t adrlen = sizeof adr;
int fd = Accept(server, (struct sockaddr *) &adr, &adrlen); //return different fd to communicate with client
ssize_t nread;
char buf[256];
nread = read(fd, buf, 256); //read the message from client
if (nread == -1) {
perror("read failed");
exit(EXIT_FAILURE);
}
if (nread == 0) {
printf("END OF FILE\n");
}
write(STDOUT_FILENO, buf, nread);
write(fd, buf, nread);
sleep(1);
close(fd);
close(server);

return 0;
}
