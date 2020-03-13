/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE


// libraries related to the functions used in the code. 
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant Macros
#define LIMIT 6553

// program begins from here
int main(int argc, string argv[])
{
    // TODO: check whether the user provided exactly 1/2 command line arguments 
    //else yell at him and return from the code. 
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // TODO: command line argument which is string integral number is converted to integer.
    // if a string is given as an input then o is returned.
    int n = atoi(argv[1]);

    // TODO: if 2nd command line argument is given then fix the 2nd argument as the seed value 
    //else no seed and seed value is substitued with NULL indicating no fixed set of random numbers.
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // TODO: generate random number per line until the number of lines we have given as input in the command line
    // in the form of argument one.
    //starting from 0 and until the upper limit provided above in the program.
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}