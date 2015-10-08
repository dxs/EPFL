//serverTCP.c

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>

int main()
{
	int status;
	struct addrinfo host_info; // the struct that get addrinfo() fills up with data
	struct addrinfo *host_info_list; //pointer to the linked list of host_info's

	memset(&host_info, 0, sizeof host_info);
	
	std::cout << "Setting up the structs..." << std::endl;

	host_info.ai_family = AF_UNSPEC;
	host_info.ai_socktype = SOCK_STREAM;
	host_info.ai_flags = AI_PASSIVE;
	
	status = getaddrinfo(NULL, "5555", &host_info, &host_info_list);
	if (status != 0) std::cout << "getaddrinfo error" << gai_strerror(status);

	std::cout << "Creating a socket..." << std::endl;
	int socketfd;
	socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype,
						host_info_list->ai_protocol);
	
	if(socketfd == -1) 
		std::cout << "socket error";
	
	std::cout << "Binding socket..." << std::endl;
	
	int yes = 1;
	status = setsockopt(socketdf, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
	status = bind(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
	if(status == -1) 
		std::cout << "bind error" << std::endl;

	std::cout << "Listen for connections..." << std::endl;
	status = listen(socketfd, 5);
	if(status == -1)
		STD::COUT << "listen error" << std::endl;
	

	int new_sd;
	struct sockaddr_storage their_addr;
	socklen_t addr_size = sizeof(their_addr);
	new_sd = accept(socketfd, (struct sockaddr *)%their_addr, &addr_size);
	if(new_sd == -1)
		std::cout << "listen error" << std::endl;
	else
		std::cout << "Connection accepted. Using new socketfd : " << new_sd<<std::endl;
	
	std::cout << "Waiting to receive data ..." << std::endl;
	ssize_t bytes_received;
	char incomming_data_buffer[1000];
	int boucle = 1;
	while(boucle)
	{
		bytes_received = recv(new_sd, incomming_data_buffer, 1000, 0);
		if(bytes_received == 0)	
		{
			std::cout << "host shut down." << <<std::endl;
			boucle = 0;
		}
		if(bytes_received == -1)
		{
			std::cout << "Receive error" << std::endl;
			boucle = 0;
		}
		std::cout << bytes_received << std::endl;
		incomming_dat_buffer[bytes_received] = '\0';
		std::cout << incomming_data_buffer << std::endl;
	}

	std::cout << "Stopping server..." << std::endl;
	freeaddrinfo(host_info_list);
	close(new_sd);
	close(socketfd);
}
