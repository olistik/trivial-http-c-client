#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "simple_tcp.h"

int main(int argc, char **ARGV) {
  int sockfd = 0;
  int port = 0;
  char * hostname = NULL;
  char * path = NULL;
  const int HTTP_COMMAND_LENGTH = 1204;
  char http_command[HTTP_COMMAND_LENGTH];
  const char * HTTP_COMMAND_TEMPLATE = "GET %s HTTP/1.0\n\n";
  const int MAX_PATH_SIZE = HTTP_COMMAND_LENGTH - strlen(HTTP_COMMAND_TEMPLATE) - 2;

  if (argc < 4) {
    printf("Usage:\nhttp_client <hostname|ip_address> <port> <path>");
    return 1;
  }

  hostname = ARGV[1];
  port = strtol(ARGV[2], NULL, 10);
  if (port == 0 && errno == EINVAL) {
    printf("Error: invalid port specified");
    return 1;
  }
  path = ARGV[3];

  if (strlen(path) > MAX_PATH_SIZE) {
    printf("Error: path too long");
    return 1;
  }

  if ((sockfd = create_socket()) < 0) {
    printf("Error: Could not create socket\n");
    return 1;
  }

  if (tcp_connect(sockfd, hostname, port) < 0) {
    printf("Error: Connect Failed\n");
    return 1;
  }

  sprintf(http_command, HTTP_COMMAND_TEMPLATE, path);

  if (send_tcp_message(sockfd, http_command) < 0) {
    printf("Error: Message Send Failed\n");
  }

  if (print_tcp_response(sockfd) < 0) {
    printf("Error: Message Read Failed\n");
  }

  return 0;
}
