//Client.c
#ifdef WIN32

#include <winsock2.h>

#elif defined (linux)

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#endif
#define PORT 4444

static void init(void);
static void end(void);

int main(int argc, char**argv)
{
	SOCKET sock = SOCKET(AF_INET, SOCK_DGRAM, 0);
	char buffer[1024];
	int n = 1;
	if(sock == INVALID_SOCKET)
	{
		printf("socket()");
		return -1;
	}
	struct hostent *hostinfo = NULL;
	SOCKADDR_IN to = {0};
	const char *hostname = "192.168.0.0";
	int tosize = sizeof to;

	hostinfo = gethostbyname(hostname);
	if(hostinfo == NULL)
	{
		printf("UNKNOWN HOST %s.\n", hostname);
		return -1;
	}
	
	to.sin_addr = *(IN_ADDR *) hostinfo->h_addr;
	to.sin_port = htons(PORT);
	to.sin_family = AF_INET;

	if(sento(sock, buffer, strlen(buffer), 0, (SOCKADDR *)&to, tosize) < 0)
	{
		printf("sento()");
		return -1;
	}	

	if((n = recvFrom(sock, buffer, sizeof buffer -1, 0, (SOCKADDR *)&to, &tosize)) < 0)
	{
		printf("recvfrom()");
		return -1;
	}
	buffer[n] = '\0';
}


static void init(void)
{
#ifdef WIN32
	WSADATA wsa;
	int err = WSAStartup(MAKEWORD(2, 2), &wsa);
	if(err < 0)
	{
		puts("WSAStartup failed!\n");
		exit(EXIT_FAILURE);
	}
#endif
}

static void end(void)
{
#ifdef WIN32
	WSACleanup();
#endif
}
