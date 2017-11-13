#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include "include/initialServer.h"
#include<netinet/in.h>

char buffer[1024];
int port;
short family;

int serverSocket;
int clientSocket;

int clientMsg; // client's message (Message sent by client)

struct sockaddr_in serverAddress, clientAddress;


void initializeServerAddress(){
	port = 9000;
	family = AF_INET;
	
	bzero((char *)&serverAddress, sizeof(serverAddress));
	
	serverAddress.sin_family = family;
	serverAddress.sin_port = htons(port);
	serverAddress.sin_addr.s_addr = INADDR_ANY;	

}

void startServer(){

	// initialize the server
	serverSocket = socket(AF_INET,SOCK_STREAM, 0 );
	
	if(!(serverSocket < 1)){
		
		initializeServerAddress();
		// bind the server socket to it's local location	
		
		printf("Server started at port : %d\n", port);	
		int binding = bind(serverSocket, (struct sockaddr*)&serverAddress , sizeof(serverAddress) );

		if(binding < 0){
			perror("Could not create server socket");
			exit(1);
		}

		
		// start listening now
		if(listen(serverSocket, 5) < 0){perror("Server can't listen"); exit(1); }
	
		
		// accept the client's connection
		int clientLength = sizeof(clientAddress);			
		clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientLength);
		
		if(clientSocket < 0){ perror("Could not accept client");}

		bzero(buffer, 1024);

		// read the message from the client
		clientMsg = read(clientSocket, (void *)&buffer, 1024);

		if(clientMsg < 0 ){perror("Can't read from client"); exit(1);}
		
		printf("Client's message:\n %s", buffer);
		

		// read and close the connection for now
		close(clientSocket);
		close(serverSocket);

	}


}
