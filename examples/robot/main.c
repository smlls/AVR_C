// serialio - demonstrate how to successfully read a line of text and
// use STRTOK() to split the line into tokens (or words)
// Robot will be used to allow user to input commands that control a robotic arm
#include <stdio.h>
#include <string.h>
#include "uart.h"
#include "readLine.h"

#define MAX_BUFFER 24
#define MAX_TOKENS (MAX_BUFFER/2)
#define MAX_DELIMS 3
int main(void) 
{    
    init_serial();
    char input[MAX_BUFFER + 1] = {}; // array will store input
    char delims[MAX_DELIMS + 1] = {" .,"}; // array of delim

    puts("Control Robotic Arm!");// starts output for user
    printf("Enter text between any ',. ' to create command.\n");// delims
    // instructs user of format for entering input
    printf("In this order: Command,Joint,Direction,Distance. \nEnter:");
    
    uint8_t num_char = readLine(input, MAX_BUFFER);// stores the inputs into num_char
    printf("You entered %i characters:\n", num_char); // how many char are read/provided in command
    
    for (uint8_t out_char=0; out_char<num_char; out_char++)// prints out user's input
    { 
        printf("%c", input[out_char]);// input[out_char] is the tokens found
    }
     
    char *tokens[MAX_TOKENS];// break input line into tokens
    uint8_t index = 0;// start count from 0
    tokens[index] = strtok(input, delims);
    //keeps getting more tokens
    while ( (tokens[index] != NULL) && (index < MAX_TOKENS - 1) )// while loop to print out tokens
    {
        index++;// increases the index (0..1...2..etc)
        tokens[index] = strtok(NULL, delims);// points index to tokens
    }
    // depending on how many tokens are accounted for, store that # in tokens_found
    uint8_t tokens_found = index;
    printf("\nThe %i commands are:\n", tokens_found);// prints out user's commands

    for (index=0; index<tokens_found; index++)// for loop to print index and token
    {
        printf("%5i %s\n", index, tokens[index]);

    }
}