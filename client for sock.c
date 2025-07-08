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
    network_socket = socket(AF_INET,SOCK_STREAM,0);//AF_INET AS WE ARE CONNECTING TO THE INETRNET IDK,,SOCK_STREAM MEANS WE ARE USING TCP PROTOCOL ,, 0 STANDS FOR DEFAULT PROTOCOL
    //the socket is setted up 
    //specify address for the socket
    struct sockaddr_in server_address;//we declare the structure for the address of the  like this server_address is a variable
    server_address.sin_family = AF_INET;//we need to specify the address family it should be the same as the address family of our socket AF_INET
    server_address.sin_port = htons(8080);//htons converts the number to ppriopiate form idk
    server_address.sin_addr.s_addr = INADDR_ANY;//You are saying: "Take the value of INADDR_ANY (which is 0) and put it into the s_addr field, which is inside the sin_addr field, which is inside my server_address variable."
    //Think of it as a nested box:

//You have a big box named server_address (which is a sockaddr_in).

//Inside the server_address box, there's a smaller box named sin_addr (which is an in_addr).

//Inside the sin_addr box, there's a specific slot named s_addr where you put the actual numerical IP address (like INADDR_ANY's value, which is 0).
    int connection_status = connect(network_socket(struct sockaddr *) &server_address, sizeof(server_address));//sizeof is required to know to size of the address structure and information in other words the earlier lines we wrote
    //Because the connect function's prototype expects an argument of like  type struct sockaddr *.

//What you have to (implicitly): &server_address is of type struct sockaddr_in *.

//What connect() expects: An argument of type struct sockaddr *.

//Since these two pointer types are not identical (even though they are compatible in this specific context for network functions), the C compiler requires the explicit type cast (struct sockaddr *) to bridge that type mismatch.

//So, when you see (struct sockaddr *)&server_address:

//&server_address: This expression gives you the memory address, and the compiler inherently knows its type is struct sockaddr_in *.

//(struct sockaddr *): This is the explicit instruction to the compiler to temporarily treat that struct sockaddr_in * as if it were a struct sockaddr * for the purpose of passing it to connect().
if(connection_status == -1){
    printf("there was an error making a connection to the remote socket");
    //if we get -1 we print that and else start recieveing transmission
}
//we now recieve
char server_response[256];// A CHARACTER ARRAY WITH 256 SIZES MEANT FOR STORING THE DATA RECIEVED FROM THE SERVER
recv(network_socket, &server_response, sizeof(server_response), 0);//0 STANDS FOR THE FLAG 
//idk close the socket
close(SOCK);//SOCK means sock_stream aka tcp connection
    return 0;
}

