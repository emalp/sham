#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>

int serverSocket;

void startServer(){

	// initialize the server
	serverSocket = socket(AF_INET,SOCK_STREAM, 0 );
	



}
