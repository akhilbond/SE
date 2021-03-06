//Vinay Shah

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>


/*int speakerZero = 0;
int speakerOne = 0;

int setSpeakers(int decibel){		//enabled for demo with laptop and desktop with soundcard only
	
	if(decibel>-42){
		
		system("amixer sset Front 0");
		system("amixer sset Headphone 100");
		//speakerZero = 0;
		//speakerOne = 1;
		
	}
	
	else{
		system("amixer sset Front 100");
		system("amixer sset Headphone 0");
		//speakerZero = 1;
		//speakerOne = 0;
		
		
		
	}
	
	
}*/


int runServer(){
	
	
	int serverSock, clientSock;
	struct sockaddr_in server, client;
	unsigned int addrLen = sizeof(struct sockaddr_in);
	
	char data [7];
	
	if((serverSock = socket(AF_INET, SOCK_STREAM, 0))==-1){
		
		perror("socket error");
		exit(-1);
	}
	
	server.sin_family = AF_INET;
	server.sin_port = htons(25000);
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&server.sin_zero,8);
	
	
	if((bind(serverSock, (struct sockaddr *)&server, addrLen)) == -1){	//binding server socket to server ip info
		
		perror("bind error");
		exit(-1);
	}
	
	if((listen(serverSock,5) == -1)){		//listening on socket
		
		perror("listen error");
		exit(-1);
	}
	
	
	pid_t ppid = getppid(); //later for forking new process. child processes will handle accepting socket
	
	while(1){
		
		if((clientSock = accept(serverSock, (struct sockaddr *)&client, &addrLen)) == -1){
			
			perror("accept error");
			exit(-1);
		}
		
		recv(clientSock, data, sizeof(data), 0);
		data[6]='\0';
		//setSpeakers(atoi(data));		//enabled for demo with laptop and desktop with soundcard only
		
		printf("%s\n", data);
		
		close(clientSock);
		
	}
	
	
}


int main(){
	
	runServer();
	
}
