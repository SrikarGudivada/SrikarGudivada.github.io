#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("please provide only one argument! \n");
        return 1;
    }
    string key = argv[1];
    char salt[3];
    strncpy(salt, key, 2);
    salt[2] = 0;
    char test[5];
    int i = 0;
    int index = 0;
    while(i < 4)
    {
        test[4] = '\0';
        for(int k = 'A'; k <= 'z'; k++)
        {
            if(index > 2) test[3] = (char)k;
            else test[3] = '\0';
            for(int j = 'A'; j <= 'z'; j++)
            {   
                if(i == 2) return 1;
                if(index > 1) test[2] = (char)j;
                else test[2] = '\0';
                for(int p = 'A'; p <= 'z'; p++)
                {
                    if(index > 0) test[1] = (char)p;
                    else test[1] = '\0';
                    for(int q = 'A'; q <= 'z'; q++)
                    {
                        test[0] = (char)q;
                        
                        char* result = crypt(test, salt);
                        int ok = strcmp (result, key) == 0;
                        
                        if(ok)
                        {
                            puts(test);
                            return 0;
                        }
                        
                        if(q == 'Z') q = 'a'- 1;
                    }
                    
                    index++;
                if(p == 'Z') p = 'a'- 1;
                }
            
            if(j == 'Z') j = 'a'- 1;
            }
            
            if(k == 'Z') k = 'a'- 1;
        }
        
        i++;
    }
    return 0;
}
