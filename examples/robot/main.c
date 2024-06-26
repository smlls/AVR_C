// serialio - demonstrate how to successfully read a line of text and
// use STRTOK() to split the line into tokens (or words)
//testcomment
#include <stdio.h>
#include <string.h>
#include "uart.h"
#include "readLine.h"

#define MAX_BUFFER 24
#define MAX_TOKENS (MAX_BUFFER/2)
#define MAX_DELIMS 3

int main(void) {    

    init_serial();
    char input[MAX_BUFFER + 1] = {}; //array will store input
    char delims[MAX_DELIMS + 1] = {" .,"}; //array of delim

//print
/*
    puts("Serial I/O Test: readLine with tokens");
     printf("Enter text up to %i characters, or end w/ CR\n", MAX_BUFFER);
    printf("Line will be parsed into tokens\n");
    printf("Possible delimitors are (w/ ASCII code): ");
 
    for (uint8_t delim=0; delim < MAX_DELIMS; delim++)
    {
        printf("'%c' 0x%x ", delims[delim], delims[delim]);
    }
    printf("\n");
    */
   
    printf("In this order: Command,Joint,Direction,Distance. \nEnter:");
    //reads sentence
    /*
    uint8_t num_char = readLine(input, MAX_BUFFER);
                                        //how many charcateruint8_t num_char = readLine(input, MAX_BUFFER);s are read
    printf("You entered %i characters\n", num_char);
    */
   uint8_t num_char = readLine(input, MAX_BUFFER);
    for (uint8_t out_char=0; out_char<num_char; out_char++)
    {               //out_char is the actual "sentence" given
        printf("%c", input[out_char]);
    }
 

    
////////////////////////////////////////////////////////////add comment
    // break input line into tokens
    char *tokens[MAX_TOKENS];
    uint8_t index = 0;
    tokens[index] = strtok(input, delims);
    //keeps getting more tokens
    while ( (tokens[index] != NULL) && (index < MAX_TOKENS - 1) ) {
        index++;
        tokens[index] = strtok(NULL, delims);
    }
    //index is 0,1,2,3 - places where the seperate tokens are stored
    //set tokens like 0 = command
    // dist = token[1] move = token[0] ...
    uint8_t tokens_found = index;

    printf("\nThe %i commands are:\n", tokens_found);
    //printf("index token\n");
    //0, 1,2,...etc if there is another token not accounted for
    // in the index, add one more index space
    for (index=0; index<tokens_found; index++)
    {
        printf("%5i %s\n", index, tokens[index]);

    }
}