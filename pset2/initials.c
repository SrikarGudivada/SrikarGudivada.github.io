#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define size 10

int main(void)
{
    int j = 0, k = 0;
    string result = malloc(sizeof(char) * size);
    string s = GetString();
    if (s != NULL)
    {
        for(int i = 0, n =strlen(s); i < n; i++)
        {
            s[i] = toupper(s[i]);
        }
        result[k] = s[0];
        k = k+1;
        while(s[j] != '\0')
        {
            if(s[j] == ' ')
            {
                result[k] = s[j+1];
                k++;
            }
            j++;
        }
        result[k] = '\0';
    }
    printf("%s", result);
    printf("\n");
}