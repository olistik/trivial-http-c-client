#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

int create_socket() {
  int sockfd = -1;
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    return -1;
  } else {
    return sockfd;
  }
}

int tcp_connect(int sockfd, const char * hostname, int port) {
  struct sockaddr_in serv_addr;

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_addr.s_addr = inet_addr(hostname);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    return -1;
  }
  return 0;
}

int send_tcp_message(int sockfd, const char * message) {
  int remaining = strlen(message), written = 0;
  while (remaining > 0) {
    if ((written = write(sockfd, message, remaining)) < 0) {
      return -1;
    }
    remaining -= written;
  }
  return 0;
}

int print_tcp_response(int sockfd) {
  int bytes_read = 0;
  char buffer[1024];
  memset(buffer, '0', sizeof(buffer));

  while ((bytes_read = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
    buffer[bytes_read] = 0;
    if (fputs(buffer, stdout) == EOF) {
      return -1;
    }
    printf("\n");
  }

  if (bytes_read < 0) {
    return -1;
  }

  return 0;
}
