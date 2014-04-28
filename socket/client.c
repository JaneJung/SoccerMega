#include "sock_hdr.h"

void stream_cli(FILE *fp, int sockfd);

int main(int argc, char **argv) {

	int sockfd;
	struct sockaddr_in servaddr;
	int ret;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	memset(&(servaddr.sin_zero), 0, 8);
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	servaddr.sin_addr.s_addr = inet_addr(argv[1]);
	//inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	ret= connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	stream_cli(stdin, sockfd);

	exit(0);
}

void stream_cli(FILE *fp, int sockfd) {
	char sendline[MAXLINE], recvline[MAXLINE];

	while(fgets(sendline, MAXLINE, fp) != NULL) {
		send(sockfd, sendline, MAXLINE, 0);
		if (recv(sockfd, recvline, MAXLINE, 0) == 0){
			fprintf(stderr, "str_cli : server terminated prematurely");
		}
		fputs(recvline, stdout);
	}
}
