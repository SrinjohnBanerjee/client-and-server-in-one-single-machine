//making a socket
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
int main()
{
    //create a socket
    int network_socket;
    network_socket = socket(AF_INET,SOCK_STREAM,0);
    //the socket is setted up 
    //specify address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;//we need to specify the address family it should be the same as the address family of our socket AF_INET
    server_address.sin_port = htons(8080);//htons converts the number to ppriopiate form 
    server_address.sin_addr.s_addr = INADDR_ANY;





    int connection_status = connect(network_socket(struct sockaddr *) &server_address, sizeof(server_address));//sizeof is required to know to size of the address structure and information in other words the earlier lines we wrote
   


//(struct sockaddr *): This is the explicit instruction to the compiler to temporarily treat that struct sockaddr_in * as if it were a struct sockaddr * for the purpose of passing it to connect().
if(connection_status == -1){
    printf("there was an error making a connection to the remote socket");
    //if we get -1 we print that and else start recieveing transmission
}
//we now recieve
char server_response[256];// A CHARACTER ARRAY WITH 256 SIZES MEANT FOR STORING THE DATA RECIEVED FROM THE SERVER
recv(network_socket, &server_response, sizeof(server_response), 0);//0 STANDS FOR THE FLAG 
//idk close the socket
    if(server_response > 0){
        printf("s\n",%server_response);
    }
close(SOCK);//SOCK means sock_stream aka tcp connection
    return 0;
}



