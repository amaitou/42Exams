#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int sockfd, connfd, max_fd;
struct sockaddr_in servaddr, cli;

fd_set m, r, w;
socklen_t len;

int ids[100000];
char *msgs[100000], buf_r[1024], buf_w[42];

int count = 0;


void fatal()
{
    write(2, "Fatal error\n", strlen("Fatal error\n"));
    exit(1);
}

int extract_message(char **buf, char **msg)
{
    char    *newbuf;
    int    i;

    *msg = 0;
    if (*buf == 0)
        return (0);
    i = 0;
    while ((*buf)[i])
    {
        if ((*buf)[i] == '\n')
        {
            newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
            if (newbuf == 0)
                fatal();
            strcpy(newbuf, *buf + i + 1);
            *msg = *buf;
            (*msg)[i + 1] = 0;
            *buf = newbuf;
            return (1);
        }
        i++;
    }
    return (0);
}

char *str_join(char *buf, char *add)
{
    char    *newbuf;
    int        len;

    if (buf == 0)
        len = 0;
    else
        len = strlen(buf);
    newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
    if (newbuf == 0)
        fatal();
    newbuf[0] = 0;
    if (buf != 0)
        strcat(newbuf, buf);
    free(buf);
    strcat(newbuf, add);
    return (newbuf);
}

void broadcast(int sender, char *msg)
{
    for(int fd = 0; fd <= max_fd; fd++)
    {
        if (fd != sender && FD_ISSET(fd, &w))
            send(fd, msg, strlen(msg), 0);
    }
}

void join_client(int fd)
{
    if (fd > max_fd)
        max_fd = fd;
    
	ids[fd] = count++;
    msgs[fd] = NULL;
    sprintf(buf_w, "server: client %d just arrived\n", ids[fd]);
    broadcast(fd, buf_w);
    FD_SET(fd, &m);
}

void remove_client(int fd)
{
    sprintf(buf_w, "server: client %d just left\n", ids[fd]);
    broadcast(fd, buf_w);
    free(msgs[fd]);
    FD_CLR(fd, &m);
    close(fd);
}

void send_msg(int fd)
{
    char *msg = 0;

    while(extract_message(&(msgs[fd]), &msg))
    {
        sprintf(buf_w, "client %d: ", ids[fd]);
        broadcast(fd, buf_w);
        broadcast(fd, msg);
        free(msg);
    }
}

int main(int ac, char **av)
{
    
	if (ac != 2)
    {
        write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
        return 1;
    }
    
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    
	if (sockfd == -1)
        fatal();
    
	bzero(&servaddr, sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
    servaddr.sin_port = htons(atoi(av[1])); 
    
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        fatal();   
    
	if (listen(sockfd, 0) != 0)
        fatal();
    
	FD_ZERO(&m);
    FD_SET(sockfd, &m);
    max_fd = sockfd;
    
	while (1)
    {
        r = w = m;
        if (select(max_fd + 1, &r, &w, NULL, NULL) < 0)
            fatal();
        for(int fd = 0; fd <= max_fd; fd++)
        {
            if (!FD_ISSET(fd, &r))
                continue;
            
			if (fd == sockfd)
            {
                len = sizeof(cli);
                connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
                if (connfd >= 0)
                {
                    join_client(connfd);
                    break;
                }
            }
            
			else
            {
                int ret = recv(fd, buf_r, 1023, 0);
                
				if (ret <= 0)
                {
                    remove_client(fd);
                    break;
                }
                buf_r[ret] = 0;
                msgs[fd] = str_join(msgs[fd], buf_r);
                send_msg(fd);
            }
        }
    }
    return 0;
}
