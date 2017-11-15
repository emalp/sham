#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include "include/initialClient.h"

int serverPort = 9000;
struct sockaddr_in server_address;
struct hostent *server;

int clientSocket;

int startClient(){

// create a client socket
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	
	server = gethostbyname("127.0.0.1");
	bzero((char *)&server_address, sizeof(server_address));
	
	server_address.sin_family = AF_INET;

	bcopy((char *)&server->h_addr ,(char *)&server_address.sin_addr.s_addr, server->h_length );

	server_address.sin_port = htons(serverPort);	

	int connected = connect(clientSocket, &server_address, sizeof(server_address));

	if(connected <0){
		perror("Cannot connect to server");
		exit(1);
	}

	printf("Successfully connected to server.\n Ready to start RPC between the computers");

	// this is only for testing purpose.
	char *buf = "Emalp is the best";
	write(clientSocket, buf, sizeof(buf));
	
	close(clientSocket);
return 0;
}





