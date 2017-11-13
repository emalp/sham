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

		int binding = bind(serverSocket, (struct *)&serverAddress , sizeof(serverAddress) );

		if(binding == 0){
			perror("Could not create server socket");
			exit(1);
		}
		
		// start listening now
		if(listen(serverSocket, 5) < 0){perror("Server can't listen"); }	
		printf("Server started and listening at port : " + port);		

		
		int clientLength = sizeof(clientAddress);			
		clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientLength);
		
		if(clientSocket < 0){ perror("Could not accept client");}

			
		

	}


}
