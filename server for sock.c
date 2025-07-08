//server
#include<stdio.h>
#include<stdlib.h>
#include<sys/type.h>
#include<sys/system.h>
#include<netinet.h>
int main()
{
    char server_message[256]="the server message";
    //create a socket
    int network_socket;
    network_socket = socket(AF_INET,SOCK_STREAM,0);
     
    
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY; 

    bind(network_socket, (struct sockaddr *)&server_address,sizeof(server_address));
    listen(network_socket,1);//NUMBER OF CLIENTS TO LISTEN TO

    int CLIENT_SOCKET;
    CLIENT_SOCKET = accept(network_socket,NULL,NULL);//the position with null is used to show the origin of the client made request since it is on the same device it is deliberately kept null
    send(CLIENT_SOCKET,server_message,sizeof(server_message),0);//doubt eikhane & nei kno ar pointer kothai galo ar ekhane struct kno lageni?
    close(server_socket);
    return 0;


}