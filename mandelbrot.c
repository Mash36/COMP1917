/*
 *  bmpServer.c
 *  1917 serve that 3x3 bmp from lab3 Image activity
 *
 *  Created by Tim Lambert on 02/04/12.
 *  Containing code created by Richard Buckland on 28/01/11.
 *  Copyright 2012 Licensed under Creative Commons SA-BY-NC 3.0.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include "pixelColor.h"
#include "mandelbrot.h"
#include <math.h>
#define MAX_ITERATIONS 256
#define DISTANCE_AWAY2 16



int waitForConnection (int serverSocket);
int makeServerSocket (int portno);
void serveBMP (int socket, double x, double y, int z);

#define SIMPLE_SERVER_VERSION 1.0
#define REQUEST_BUFFER_SIZE 1000
#define DEFAULT_PORT 1917
#define NUMBER_OF_PAGES_TO_SERVE 10000
// after serving this many pages the server will halt

void writeHeader (FILE *file);

int main (int argc, char *argv[]) {
    
    printf ("************************************\n");
    printf ("Starting simple server %f\n", SIMPLE_SERVER_VERSION);
    printf ("Serving bmps since 2012\n");
    
    int serverSocket = makeServerSocket (DEFAULT_PORT);
    printf ("Access this server at http://localhost:%d/\n", DEFAULT_PORT);
    printf ("************************************\n");
    
    char request[REQUEST_BUFFER_SIZE];
    
    int numberServed = 0;
    while (numberServed < NUMBER_OF_PAGES_TO_SERVE) {
        
        
        double x,y;
        int z;
        
        printf ("*** So far served %d pages ***\n", numberServed);
        
        int connectionSocket = waitForConnection (serverSocket);
        // wait for a request to be sent from a web browser, open a new
        // connection for this conversation
        
        // read the first line of the request sent by the browser
        int bytesRead;
        bytesRead = read (connectionSocket, request, (sizeof request)-1);
        assert (bytesRead >= 0);
        // were we able to read any data from the connection?
        
        
        
        
        //scanning the http request to get x, y, z
        
        int num_parsed = sscanf(request, "GET /tile_x%lf_y%lf_z%d.bmp HTTP/1.1",&x, &y, &z);
        
        if (num_parsed != 3) {
            char homepage [] = "<!DOCTYPE html> <script src=\"http://almondbread.cse.unsw.edu.au/tiles.js\"></script>";
            write (connectionSocket, homepage, sizeof(homepage));
        }
        
        
        
        
        
        
        
        // print entire request to the console
        printf (" *** Received http request ***\n %s\n", request);
        
        //send the browser a simple html page using http
        printf (" *** Sending http response ***\n");
        serveBMP(connectionSocket, x, y, z);
        
        // close the connection after sending the page- keep aust beautiful
        close(connectionSocket);
        
        numberServed++;
    }
    
    // close the server connection after we are done- keep aust beautiful
    printf ("** shutting down the server **\n");
    close (serverSocket);
    
    return EXIT_SUCCESS;
}



//escapeSteps function


int escapeSteps(double x, double y) {
    double real, imag;
    double a, ib;
    double complex;
    
    unsigned short int steps = 0;
    a = ib = real = imag = complex = 0;
    
    while (steps < MAX_ITERATIONS && complex < DISTANCE_AWAY2) {
        
        real = (a*a) - (ib*ib) + x;
        imag = 2 * a * ib + y;
        
        a = real;
        ib = imag;
        complex = real*real + imag*imag;
        
        steps++;
    }
    return steps;
}




#define BYTES_PER_PIXEL 3
#define BITS_PER_PIXEL (BYTES_PER_PIXEL*8)
#define NUMBER_PLANES 1
#define PIX_PER_METRE 2835
#define MAGIC_NUMBER 0x4d42
#define NO_COMPRESSION 0
#define OFFSET 54
#define DIB_HEADER_SIZE 40
#define NUM_COLORS 0
#define BLACK 0
#define WHITE 255

#define SIZE 512

typedef unsigned char  bits8;
typedef unsigned short bits16;
typedef unsigned int   bits32;

#define BYTES_PER_ROW (BYTES_PER_PIXEL*SIZE)

unsigned char bmp[OFFSET + BYTES_PER_ROW*SIZE];



#define WRITE8(X) *p++  = (X)
#define WRITE16(X) *p++ = (X)&0xff; *p++ = ((X)>>8)&0xff
#define WRITE32(X) *p++ = (X)&0xff; *p++ = ((X)>>8)&0xff; *p++ = ((X)>>16)&0xff; *p++ = ((X)>>24)&0xff




void serveBMP (int socket, double x_ctr, double y_ctr, int z) {
    char* message;
    
    // first send the http response header
    
    // (if you write stings one after another like this on separate
    // lines the c compiler kindly joins them togther for you into
    // one long string)
    message = "HTTP/1.0 200 OK\r\n"
    "Content-Type: image/bmp\r\n"
    "\r\n";
    printf ("about to send=> %s\n", message);
    write (socket, message, strlen (message));
    
    
    //get a pointer ready to fill in the bmp data
    unsigned char* p = bmp;
    // writing the header for the bmp
    WRITE8('B');
    WRITE8('M');
    WRITE32(OFFSET + BYTES_PER_ROW*SIZE);
    WRITE16(0);
    WRITE16(0);
    WRITE32(OFFSET);
    // writing the DIB header for the bmp
    WRITE32(40);
    WRITE32(SIZE);
    WRITE32(SIZE);
    WRITE16(1);
    WRITE16(BITS_PER_PIXEL);
    WRITE32(0);
    WRITE32(BYTES_PER_ROW*SIZE);
    WRITE32(PIX_PER_METRE);
    WRITE32(PIX_PER_METRE);
    WRITE32(0);
    WRITE32(0);
    
    double zoom = 1.0 / (double)(1<<z);
    
    int y_index = 0;
    while (y_index < SIZE) {
        
        double y = y_ctr + zoom * ( (double)y_index - (SIZE-1.0)/2.0 );

        int x_index = 0;
        while (x_index < SIZE) {
            
            double x = x_ctr + zoom * ( (double)x_index - (SIZE-1.0)/2.0 );
            int steps = escapeSteps(x,y);
            
            //write the colours in (they come in this order in a bmp)
            WRITE8(stepsToBlue(steps));
            WRITE8(stepsToGreen(steps));
            WRITE8(stepsToRed(steps));

        
            
            x_index++;
        }
        
        
        
        y_index++;
    }


    printf("expected bmp Size = %d, Bytes written = %d\n",OFFSET + BYTES_PER_ROW*SIZE, (int)(p-bmp));
 
    
    write (socket, bmp, sizeof(bmp));
}


// start the server listening on the specified port number
int makeServerSocket (int portNumber) {
    
    // create socket
    int serverSocket = socket (AF_INET, SOCK_STREAM, 0);
    assert (serverSocket >= 0);
    // error opening socket
    
    // bind socket to listening port
    struct sockaddr_in serverAddress;
    memset ((char *) &serverAddress, 0,sizeof (serverAddress));
    
    serverAddress.sin_family      = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port        = htons (portNumber);
    
    // let the server start immediately after a previous shutdown
    int optionValue = 1;
    setsockopt (
                serverSocket,
                SOL_SOCKET,
                SO_REUSEADDR,
                &optionValue,
                sizeof(int)
                );
    
    int bindSuccess =
    bind (
          serverSocket,
          (struct sockaddr *) &serverAddress,
          sizeof (serverAddress)
          );
    
    assert (bindSuccess >= 0);
    // if this assert fails wait a short while to let the operating
    // system clear the port before trying again
    
    return serverSocket;
}

// wait for a browser to request a connection,
// returns the socket on which the conversation will take place
int waitForConnection (int serverSocket) {
    // listen for a connection
    const int serverMaxBacklog = 10;
    listen (serverSocket, serverMaxBacklog);
    
    // accept the connection
    struct sockaddr_in clientAddress;
    socklen_t clientLen = sizeof (clientAddress);
    int connectionSocket =
    accept (
            serverSocket,
            (struct sockaddr *) &clientAddress,
            &clientLen
            );
    
    assert (connectionSocket >= 0);
    // error on accept
    
    return (connectionSocket);
}

