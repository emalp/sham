#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>


int clientSocket;

void startClient(){
	printf("Hello world\n");

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	if(clientSocket > 0){

		printf("Client socket created!");
		
	}

}

int main(){

	startClient();

return 0;
}
