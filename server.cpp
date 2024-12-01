#include <string>
#include <netinet/in.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int InitSocket(int serverPort);
bool validArgs(int argc, char* argv[]);

int main(int argc, char* argv[]){
    if(!validArgs(argc, argv)){
        cout << "Usage: " << argv[0] << " port" << endl;
        exit(1);
    }
    int server = InitSocket(atoi(argv[1]));
}

// Creates and binds socket to serverPort, enables socket reuse without waiting for OS to recycle it, 
// and sets it to listen for up to 5 connections waiting. Returns socket descriptor.
int InitSocket(int serverPort){
    int sd = socket(AF_INET, SOCK_STREAM, 0); // creates a new socket for IP using TCP
    // Enable socket reuse without waiting for the OS to recycle it
    const int on = 1;
    setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(int)); // this lets us reuse the socket without waiting for the OS to recycle it

    // set up the data structure
    sockaddr_in acceptSock;
    bzero((char *)&acceptSock, sizeof(acceptSock)); // zero out the data structure
    acceptSock.sin_family = AF_INET;                // using IP
    acceptSock.sin_addr.s_addr = htonl(INADDR_ANY); // listen on any address this computer has
    acceptSock.sin_port = htons(serverPort);       // set the port to listen on

    // Bind the socket
    bind(sd, (sockaddr *)&acceptSock, sizeof(acceptSock)); // bind the socket using the parameters we set earlier

    // Set socket status to listen
    int n = 4;
    listen(sd, n); // listen on the socket and allow up to n connections to wait.
    
    return sd;
}

//returns true if valid CLI args
bool validArgs(int argc, char* argv[]){
    if (argc < 2) return false;
    char* curr = argv[1];
    while(*curr != 0){
        if(!isdigit(*curr)) return false;
        curr++;
    }
    return true;
}