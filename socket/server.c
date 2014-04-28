#include "sock_hdr.h"

void stream_echo(int sockfd);

int main(int argc, char **argv) {
	int listenfd, connfd;
	socklen_t clilen;
	struct sockaddr_in cliaddr, servaddr;
	int state;

	pid_t childpid = 0;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("listenfd : %d\n", listenfd);

	memset(&(servaddr.sin_zero), 0, 8);
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	state = bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	printf("state : %d\n", state);

	listen(listenfd, BACKLOG);

	for (;;) {
		clilen = sizeof(cliaddr);
		if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen)) < 0) {
			if (errno == EINTR) continue;
			printf("accept error\n");
			exit(0);
		}

		if ((childpid = fork()) == 0) {
			close(listenfd);
			stream_echo(connfd);
			exit(0);
		}
		close(connfd);
	}
	return 0;
}

void stream_echo(int sockfd) {
	ssize_t n;
	char line[MAXLINE];

	printf("stream_echo\n");

	for(;;) {
		if ((n = recv(sockfd, line, MAXLINE, 0)) == 0) {
			return ;
		}
		printf("recv %d\n", n);
		printf("client message : %s\n", line);
		send(sockfd, line, n, 0);
	}
}
