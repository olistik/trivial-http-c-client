#ifndef SIMPLE_TCP_H
#define SIMPLE_TCP_H

int create_socket();
int tcp_connect(int sockfd, const char * hostname, int port);
int send_tcp_message(int sockfd, const char * message);
int print_tcp_response(int sockfd);

#endif
