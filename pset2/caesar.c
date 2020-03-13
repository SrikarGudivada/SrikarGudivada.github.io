#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if( argc != 2 || (atoi(argv[1]) < 0))
    {
        printf("wtf have you done!");
        return 1;
    }
    else
    {
    int key = atoi(argv[1])%26;
    string input = GetString();
    string output = malloc(sizeof(char) * (strlen(input) + 1));
    
    for (int i = 0,n = strlen(input); i < n; i++)
    {
        if(input[i] >= 'a' && input[i] <= 'z')
        {
            if(((int)input[i] + key) > (int)'z')
                output[i] = (char)(((int)input[i]) + key - 26);
            else
                output[i] = (char)(((int)input[i]) + key);
        }
        else if(input[i] >= 'A' && input[i] <= 'Z')
        {
            if(((int)input[i] + key) > (int)'Z')
                output[i] = (char)(((int)input[i]) + key - 26);
            else
                output[i] = (char)(((int)input[i]) + key);
        }
        else
        {
            output[i] = input[i];
        }
    }
    printf("%s\n", output);
    return 0;
    }
}