#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>


int main(int argc, char* argv[])
{
	int sock;

	struct sockaddr_in serv_addr;
	int str_len;

	char msg[30];

	if (argc != 3)
	{
		printf("");
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (serv_sock == -1)
	{
		std::cout << "error " << std::endl;
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if (connect(sock, (struct sockaddr*)& serv_addr, sizeof(serv_addr)) == -1)
	{
		std::cout << "error " << std::endl;
	}
	str_len = read(sock, msg, sizeof(msg) - 1);

	if (clnt_sock == -1)
	{
		std::cout << "error " << std::endl;
	}

	std::cout << msg << std::endl;
	close(sock);
	return 0;
}