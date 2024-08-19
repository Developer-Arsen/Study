#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

#define MAXBUF 256
#define PUERTO 8080
#define GRUPO "226.0.1.1"

int main(void) {
  int s, r;
  struct sockaddr_in srv, cli;
  struct ip_mreq mreq;
  char buf[MAXBUF];

  memset(&srv, 0, sizeof(srv));
  srv.sin_family = AF_INET;
  srv.sin_port = htons(PUERTO);
  srv.sin_addr.s_addr = inet_addr(GRUPO);
//   srv.sin_addr.s_addr = INADDR_ANY;
  if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket");
    return 1;
  }

  if (bind(s, (struct sockaddr *)&srv, sizeof(srv)) < 0) {
    perror("bind");
    return 1;
  }

  mreq.imr_multiaddr.s_addr = inet_addr(GRUPO);
  mreq.imr_interface.s_addr = htonl(INADDR_ANY);

  if (setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0) {
    perror("setsockopt");
    return 1;
  }

  socklen_t n = sizeof(cli);

  while (1) {
    printf("aaaaaa %s\n", buf);
    if ((r = recvfrom(s, buf, MAXBUF, 0, (struct sockaddr *) &cli, &n)) < 0) {
      perror("recvfrom");
    } else {
      buf[r] = 0;
      fprintf(stdout, "Message from %s: %s\n", inet_ntoa(cli.sin_addr), buf);
    }
  }
 
  return 0;
}