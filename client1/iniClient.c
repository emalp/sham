#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include "include/iniClient.h"

const int port = 9000;

char commandToServer[50];

int clientSocket;
char serverIp[50];

struct sockaddr_in server_address;
struct hostent *server_ip_details;

void startClient(){
	printf("client started...\n");
	
	bzero((char *)&server_address , sizeof(server_address));


	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);	

	printf("Please enter the server's IP:\n");
	scanf("%s", &serverIp);	
	server_ip_details = gethostbyname(serverIp);

	
	bcopy(server_ip_details->h_addr, (char *)&server_address.sin_addr.s_addr, sizeof(server_ip_details->h_length));
	


	clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	if(clientSocket > 0){

		printf("Client socket created!\n");
		int connected = connect(clientSocket,(struct sockaddr_in *)&server_address, sizeof(server_address) );	
		
		if(connected != 0){
			perror("Client can't connect to server\n");
			exit(1);
		}

		//char *buf = "Emalp\0";
	
		printf("Command to server:\n");
		scanf("%s", &commandToServer);

		write(clientSocket, commandToServer, sizeof(commandToServer)+1);
		printf("Message sent to server\n");
		close(clientSocket);
	}

}


